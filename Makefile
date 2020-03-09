CC=g++
CFLAGS =-g -std=c++11 -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`

default: main

main: fonctions.o main.o mlv.o
	$(CC) $(CFLAGS) -o main fonctions.o main.o mlv.o $(LDFLAGS) $(LDLIBS)

fonctions.o: fonctions.cpp projet.h
	$(CC) $(CFLAGS) -c fonctions.cpp

main.o: main.cpp projet.h
	$(CC) $(CFLAGS) -c main.cpp

mlv.o: mlv.cpp projet.h
	$(CC) $(CFLAGS) -c mlv.cpp $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) *.o*

