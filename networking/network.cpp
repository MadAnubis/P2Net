#include "network.h"


Network::Network()
{
  work_ = true;
}
Network::~Network()
{}
bool Network::init(
        unsigned short port,
        void(*logCallback)(std::vector<char>*),
        std::vector<char>*(*httpCallback)(std::vector<char>*))
{
  //if(httpCallback_ == NULL)
   // return false;

  port_ = port;
  logCallback_ = logCallback;
  httpCallback_ = httpCallback_;

  thread_.startThread(this);

  return true;
}

void Network::run()
{
  addrinfo* server, hints, *temp;
  int error_code, server_socket, yes = 1;
  char port[6];

  sToC(port_, port);

  memset(&hints, 0, sizeof(hints));  

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  error_code = getaddrinfo(NULL,
                            port,
                            &hints,
                            &server);

  if(error_code != 0)
  {
    char temp[] = "10GetAddrInfo Failed!\n";
    log(temp, sizeof(temp));
    return;
  }

  temp = server;
  while(temp != NULL)
  {
    server_socket = socket(
                        temp->ai_family,
                        temp->ai_socktype,
                        temp->ai_protocol);
    if(server_socket == -1)
    {
      temp = temp->ai_next;
      continue;
    }

    error_code = setsockopt(server_socket,
                            SOL_SOCKET,
                            SO_REUSEADDR,
                            &yes,
                            sizeof(int));
    if(error_code == -1)
    {
      char err[] = "10Socket Error\n";
      log(err, sizeof(err));
      freeaddrinfo(server);
      return;
    }
    
    error_code = bind(server_socket,
                      temp->ai_addr,
                      temp->ai_addrlen);
    if(error_code == -1)
    {
      char err[] = "10Socket Bind Fail\n";
      close(server_socket);
      log(err, sizeof(err));
      temp = temp->ai_next;
      continue;
    }

    break;

  }

  if(temp == NULL)
  {
    char err[] = "10Server Bind Fail!\n";
    log(err, sizeof(err));
    freeaddrinfo(server);
    printf("SAD\n");
    return;
  }

  freeaddrinfo(server);

  error_code = listen(server_socket,
                      10);
  if(error_code == -1)
  {
    char err[] = "10Server listen failed!!\n";
    log(err, sizeof(err));
    return;
  }

  while(work_)
  {
    int in_con;
    sockaddr_storage* in_addr = new sockaddr_storage();
    socklen_t in_size = sizeof(in_addr);

    in_con = accept(server_socket,
                    (sockaddr*)in_addr,
                    &in_size);
    if(in_con == -1)
      continue;

    int read_in;
    char read_buff[512];
    while(true)
    {
      read_in = recv(in_con,
                      read_buff,
                      511,
                      0);
      if(read_in < 1)
        break;

      read_buff[read_in] = 0;
      puts(read_buff);
    }
    close(in_con);
  }

  close(server_socket);

}

void Network::sToC(short in, char* out)
{
  char temp[6];
  int idx = 0;

  if(in < 10)
  {
    out[0] = in + '0';
    out[1] = 0;
    return;
  }

  while(in)
  { 
    temp[idx] = in % 10 + '0';
    ++idx;
    in /= 10;
  }

  out[idx] = 0;

  for(int c = 0; idx > 0; ++c, --idx)
    out[c] = temp[idx - 1];
}

void Network::log(char* in, long unsigned int size)
{
  std::vector<char> temp(6, '0');

  if(logCallback_ == NULL)
    return;

  temp.insert(temp.end(),
              in,
              in + size - 1);

  logCallback_(&temp);
}

void Network::stop()
{
  work_ = false;
}


