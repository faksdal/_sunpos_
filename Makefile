 
CC=g++
CFLAGS=-I. -I./src
OBJ = obj/sunpos.o obj/julianDay.o obj/solarPhysics.o obj/parseOptarg.o obj/printUsage.o

all: $(OBJ)
	$(CC) $(OBJ) -o sunpos

obj/sunpos.o: sunpos.cpp
	$(CC) $(CFLAGS) -c -o obj/sunpos.o sunpos.cpp

obj/julianDay.o : src/julianDay.h src/julianDay.cpp
	$(CC) $(CFLAGS) -c -o obj/julianDay.o src/julianDay.cpp

obj/solarPhysics.o : src/solarPhysics.h src/solarPhysics.cpp
	$(CC) $(CFLAGS) -c -o obj/solarPhysics.o src/solarPhysics.cpp

obj/parseOptarg.o : src/parseOptarg.h src/parseOptarg.cpp
	$(CC) $(CFLAGS) -c -o obj/parseOptarg.o src/parseOptarg.cpp

obj/printUsage.o : src/printUsage.h src/printUsage.cpp
	$(CC) $(CFLAGS) -c -o obj/printUsage.o src/printUsage.cpp

clean:
	rm -rf obj/*.o