#include <include/p2net.h>
#include "networking/network.h"


int main()
{
  Network net;
  
  net.init(10, NULL, NULL);

  sleep(3);
  return 0;
}
