 
CC=g++
CFLAGS=-I. -I./source
OBJ = obj/main.o obj/JulianDay.o #obj/SolarPhysics.o

all: $(OBJ)
	$(CC) $(OBJ) -o solarPos

obj/main.o: main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o main.cpp

obj/JulianDay.o : src/JulianDay.h src/JulianDay.cpp
	$(CC) $(CFLAGS) -c -o obj/JulianDay.o src/JulianDay.cpp

#obj/SolarPhysics.o : src/SolarPhysics.h src/SolarPhysics.cpp
#	$(CC) $(CFLAGS) -c -o obj/SolarPhysics.o src/SolarPhysics.cpp

clean:
	rm -rf obj/*.o
	rm solarPos