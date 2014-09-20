OBJS = main.o system_log.o
CC = g++ 
CFLAGS = -Wall -c -std=c++0x -I $(shell pwd)
LFLAGS = -Wall -std=c++0x -I $(shell pwd)
PRJNAME = prog.out
LIBS = -pthread

FTHREADL = threading/linux/
FLOG = log/

PRJNAME : $(OBJS)
	$(CC) $(LFLAGS) $(LIBS) $(OBJS) -o $(PRJNAME)

main.o : main.cpp $(FTHREADL)threading_linux_2.h system_log.o
	$(CC) $(CFLAGS) main.cpp

system_log.o : $(FLOG)system_log.cpp $(FLOG)system_log.h $(FTHREADL)threading_linux_2.h
	$(CC) $(CFLAGS) $(FLOG)system_log.cpp

clean:
	\rm *.o $(PRJNAME)

