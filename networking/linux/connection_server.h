#ifndef CONNECTION_SERVER_H
#define CONNECTION_SERVER_H

#include <include/p2net.h>

class Connection
{
  public:
    Connection();
    ~Connection();

    bool init(short port,
              void(logCallback)(std::vector<char>),
              std::vector<char>(httpCallback)
                                (std::vector<char>));
    void run();

  private:
    

};

#endif //  CONNECTION_SERVER_H
