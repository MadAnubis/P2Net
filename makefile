OBJS = main.o system_log.o connection_server.o network.o
CC = g++ 
CFLAGS = -Wall -c -std=c++0x -I $(shell pwd)
LFLAGS = -Wall -std=c++0x -I $(shell pwd)
PRJNAME = prog.out
LIBS = -pthread

FTHREADL = threading/linux/
FLOG = log/
FNETL = networking/linux/

PRJNAME : $(OBJS)
	$(CC) $(LFLAGS) $(LIBS) $(OBJS) -o $(PRJNAME)

main.o : main.cpp $(FTHREADL)threading_linux_2.h 
	$(CC) $(CFLAGS) main.cpp

system_log.o : $(FLOG)system_log.cpp $(FLOG)system_log.h $(FTHREADL)threading_linux_2.h
	$(CC) $(CFLAGS) $(FLOG)system_log.cpp

connection_server.o : $(FNETL)connection_server.cpp $(FNETL)connection_server.h
	$(CC) $(CFLAGS) $(FNETL)connection_server.cpp

network.o : networking/network.cpp networking/network.h
	$(CC) $(CFLAGS) networking/network.cpp

clean:
	\rm *.o $(PRJNAME)

