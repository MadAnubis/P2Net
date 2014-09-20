#include <include/p2net.h>

#include "threading/linux/threading_linux_2.h"
#include "log/system_log.h"

int main()
{
  SystemLog* test = new SystemLog();

  char str[] = "Kollane";
  std::vector<char> aa1;

  aa1.insert(aa1.end(), str, str + 7);

  for(int c = 0; c < 10; c++)
  {
    test->addLog(&aa1);
  }

  sleep(5);
  
  return 0;
}
