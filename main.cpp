#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "threading/linux/threading_linux_2.h"

class Test
{
  public:
   void run()
   {
     for(int c = 0;c < 10; c++)
     {
       printf("ALIVE!!!\n");
       sleep(1);
     }
     printf("FINISH!!\n");
   }
};
int main()
{
  Test* aa;
  ThreadingLinux2<Test> bb;

  for(int c = 0; c < 10; c++)
  {
    aa = new Test();
    bb.startThread(aa);
  }

  sleep(20);

  return 0;
}
