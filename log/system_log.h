#ifndef SYSTEM_LOG_H
#define SYSTEM_LOG_H

#include "include/p2net.h"

#include "threading/linux/threading_linux_2.h"

class SystemLog
{
  public:
    SystemLog();
    ~SystemLog();

    void run();
    void stop();
    void addLog(std::vector<char>* log);

  private:
    struct connection_file_cont_
    {
      int IP_;
      short port_;
      std::vector<char> total_send_;
      std::vector<char> total_received_;
      unsigned int total_connections_;
      int last_connection_time_;
    };
    bool working_;

    std::mutex buffer_lock_;
    std::list<std::vector<char>*> buffer_;

    ThreadingLinux2<SystemLog> thread_;
};

#endif //SYSTEM_LOG_H
