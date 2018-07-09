SHELL=/bin/bash
CPP=g++
CLFAGS=-Wall -I ../

OBJECTS=main.o object.o driven.o Surface.o warShip.o externeFunktionen/pos_convert.o Equipment.o weapon.o cannon.o


all: main

%.o: %.cpp
	$(CPP) $(CLFAGS) -c -o  $@ $<


main: $(OBJECTS)
	$(CPP) $(CFLAGS) $(LFLAGS) -o $@ $(OBJECTS)


clean:
	rm *.o
	rm main
