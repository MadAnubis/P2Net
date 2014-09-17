OBJS = main.o
CC = g++ 
CFLAGS = -Wall -c -std=c++0x
LFLAGS = -Wall -std=c++0x
PRJNAME = prog.out
LIBS = -pthread

FTHREADL = threading/linux/

PRJNAME : $(OBJS)
	$(CC) $(LFLAGS) $(LIBS) $(OBJS) -o $(PRJNAME)

main.o : main.cpp $(FTHREADL)threading_linux_2.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o $(PRJNAME)

