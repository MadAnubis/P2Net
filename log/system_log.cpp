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
