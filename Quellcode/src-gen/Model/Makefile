SHELL=/bin/bash
CPP=g++
CLFAGS=-Wall -I ../
LFLAGS=-lOpenDIS -lGeographic

OBJECTS=main.o externeFunktionen/send_recv_data.o externeFunktionen/Timer.o DIS/DataStream.o DIS/Vector3Double.o object.o driven.o Surface.o warShip.o DIS_enum.o externeFunktionen/pos_convert.o Equipment.o weapon.o cannon.o vls.o rocket.o civilPlane.o military.o warPlane.o civilShip.o Munition.o sensor.o sonar.o	radar.o


all: main

%.o: %.cpp
	$(CPP) $(CLFAGS) -c -o  $@ $<


main: $(OBJECTS)
	$(CPP) $(CFLAGS) $(LFLAGS) -o $@ $(OBJECTS)


clean:
	rm *.o
	rm main
