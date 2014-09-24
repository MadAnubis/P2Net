#include "system_log.h"

SystemLog::SystemLog()
{
  working_ = true;

  thread_.startThread(this);
}
SystemLog::~SystemLog()
{
}
void SystemLog::run()
{
  std::vector<char>* temp;

  while(working_)
  {
    while(true)
    {
      buffer_lock_.lock(); //Lock

      if(buffer_.size() < 1)
      {
        buffer_lock_.unlock(); //Unlock
        break;
      }

      temp = buffer_.front();
      buffer_.pop_front();

      buffer_lock_.unlock(); //Unlock

      printf("%s\n", &temp->front());

      delete temp;
    }

    sleep(1);
  }
}
void SystemLog::stop()
{
  working_ = false;
}
void SystemLog::addLog(std::vector<char>* log)
{
  std::vector<char>* temp =
    new std::vector<char>(*log);

  buffer_lock_.lock(); //Lock

  buffer_.push_back(temp);

  buffer_lock_.unlock(); //Unlock
}
SystemLog::connection_cont_* SystemLog::startConnection(
                    std::vector<char>* data)
{
  FILE* in_file = NULL;
  char name[] = "Logs/Connection_logs/123412";
  //char buffer[64];
  connection_cont_* temp = new connection_cont_();

  temp->ip_ = static_cast<unsigned int>(data->front());
  temp->port_ = static_cast<unsigned int>(data->front() + 4);
  temp->total_sent_.push_back('0');
  temp->total_received_.push_back('0');
  temp->total_connections_ = 0;
  temp->last_connection_time_ = time(NULL);


  for(int c = 0; c < 6; ++c)
    name[c + 21] = (*data)[c];


  in_file = fopen(name, "r");

  connection_lock_.lock(); // Lock
  connections_.push_back(temp);
  connection_lock_.unlock();
  
  if(in_file == NULL)
    return temp;

  for(int c = 0; c < 3; ++c)
  {
    
    switch (c)
    {
      case 0:
        temp->total_sent_.erase(
                temp->total_sent_.begin());
        break;
    }
  }
  return NULL;
}

