#ifndef THREADING_LINUX_2_H
#define THREADING_LINUX_2_H

#include <pthread.h>

template<class T> class Threading
{
  public:
   Threading() {}
   ~Threading() {}

   int startThread(T* data)
   {
     pthread_t thread;
     int error_code;

     error_code = pthread_create(
                        &thread,
                        NULL,
                        &workingThread,
                        static_cast<void*>(data));
     if(!error_code)
       pthread_detach(thread);

     return error_code;
   }

  private:
   static void* workingThread(void* data)
   {
      T* thread_class;

      thread_class = static_cast<T*>(data);
      thread_class->run();
      delete thread_class;

      pthread_exit(NULL);
   }

};

#endif // THREADING_LINUX_2_H
