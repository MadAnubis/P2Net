#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <cstdio>
#include <cstring>
#include <errno.h>

#ifdef WINDOWS

#else //Linux

#include "linux/connection_server.h"
//#include "linux/connection_client.h"
#include "threading/linux/threading_linux_2.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

#endif

class Network
{
  public:
    Network();
    ~Network();
    void run();
    bool init(
          unsigned short port,
          void(*logCallback)(std::vector<char>*),
          std::vector<char>*(*httpCallback)
                          (std::vector<char>*));
    void stop();
  private:
    unsigned short port_;
    Threading<Network> thread_;
    bool work_;
    void(*logCallback_)(std::vector<char>*);
    std::vector<char>*(*httpCallback_)
                        (std::vector<char>*);

    void sToC(short in, char* out);
    void log(char* in, long unsigned int size);

};

#endif //NETWORK_H
