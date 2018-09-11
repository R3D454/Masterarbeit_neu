SHELL=/bin/bash
CPP=g++
CLFAGS=-Wall -I ../
LFLAGS=-lOpenDIS -lGeographic

OBJECTS=main.o Klasse1.o Klasse2.o


all: main

%.o: %.cpp
	$(CPP) $(CLFAGS) -c -o  $@ $<


main: $(OBJECTS)
	$(CPP) $(CFLAGS) $(LFLAGS) -o $@ $(OBJECTS)


clean:
	rm *.o
	rm main
