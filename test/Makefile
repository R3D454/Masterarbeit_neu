SHELL=/bin/bash
CPP=g++
CLFAGS=-Wall -I ../
LFLAGS=-lQtTime

OBJECTS=timestamp.o


all: main

%.o: %.cpp
	$(CPP) $(CLFAGS) -c -o  $@ $<


main: $(OBJECTS)
	$(CPP) $(CFLAGS) $(LFLAGS) -o $@ $(OBJECTS)


clean:
	rm *.o
	rm main
