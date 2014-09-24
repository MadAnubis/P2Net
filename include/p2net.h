#ifndef P2NET_H
#define P2NET_H


  /*
  * Global header
  */

  // #define WINDOWS


  #ifdef WINDOWS

    #include <windows.h>


    #define sleep(x) Sleep(1000 * x) 

  #else

    #include <unistd.h>

  #endif //WINDOWS

  #include <cstdio>
  #include <list>
  #include <mutex>
  #include <vector>
  #include <cstdlib>
  #include <ctime>
  #include <cstring>

#endif //P2NET_H
