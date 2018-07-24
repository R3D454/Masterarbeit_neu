SHELL=/bin/bash
CPP=g++
CLFAGS=-Wall -I ../
LFLAGS=-lOpenDIS -lGeographic

OBJECTS=main.o  DIS/DataStream.o  object.o driven.o Surface.o warShip.o DIS_enum.o externeFunktionen/pos_convert.o Equipment.o weapon.o cannon.o rocket.o civilPlane.o civilShip.o Munition.o sensor.o sonar.o	radar.o


all: main

%.o: %.cpp
	$(CPP) $(CLFAGS) -c -o  $@ $<


main: $(OBJECTS)
	$(CPP) $(CFLAGS) $(LFLAGS) -o $@ $(OBJECTS)


clean:
	rm *.o
	rm main
