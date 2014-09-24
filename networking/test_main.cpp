#include <unistd.h>

#include "network.h"

int main()
{
  Network* aa = new Network();
  aa->init(8450, NULL, NULL);
  sleep(4);
  return 0;
}
