#include <include/p2net.h>

#include "threading/linux/threading_linux_2.h"
#include "log/system_log.h"

int main()
{
  char f[] = "1234567890";
  std::vector<char> aa;
  char s[6];

  aa.insert(aa.begin(), f, f + 10);

  for(int c = 0; c < 5; ++c)
    s[c] = aa[c];
  s[5] = 0;

  printf("%s\n", s);

  
  return 0;
}
