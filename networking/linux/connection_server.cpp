#include "connection_server.h"

Connection::Connection()
{}

Connection::~Connection()
{}

bool Connection::init(
          short port,
          void(logCallback)(std::vector<char>),
          std::vector<char>(httpCallback)(std::vector<char>))
{
  return false;
}

void Connection::run()
{

}
