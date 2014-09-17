#ifndef CONNECTION_H
#define CONNECTION_H


class Connection
{
  public:
    Connection();
    ~Connection();

    bool init(short port,
              void(log_callback)(char*, int),
              char*(http_callback)(char*));
    void run();

  private:

};

#endif //  CONNECTION_H
