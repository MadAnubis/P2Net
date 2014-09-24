#ifndef SYSTEM_LOG_H
#define SYSTEM_LOG_H

#include "include/p2net.h"

#ifdef WINDOWS

#else
#include "threading/linux/threading_linux_2.h"
#endif
class SystemLog
{
  public:
    SystemLog();
    ~SystemLog();

    void run();
    void stop();
    void addLog(std::vector<char>* log);

  private:
    struct connection_cont_
    {
      unsigned int ip_;
      unsigned short port_;
      std::vector<char> total_sent_;
      std::vector<char> total_received_;
      unsigned int total_connections_;
      int last_connection_time_;
    };

    bool working_;

    std::mutex buffer_lock_;
    std::list<std::vector<char>*> buffer_;
    std::mutex connection_lock_;
    std::list<connection_cont_*> connections_;

    Threading<SystemLog> thread_;

    connection_cont_* startConnection(
                    std::vector<char>* data);
    connection_cont_* getConnection(
                    std::vector<char>* data);
    void closeConnection(
                    std::vector<char>* data);

};

#endif //SYSTEM_LOG_H
