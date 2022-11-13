 
CC=g++
CFLAGS=-I. -I./source
OBJ = obj/sunpos.o obj/julianDay.o obj/solarPhysics.o obj/parseOptarg.o

all: $(OBJ)
	$(CC) $(OBJ) -o sunpos

obj/sunpos.o: sunpos.cpp
	$(CC) $(CFLAGS) -c -o obj/sunpos.o sunpos.cpp

obj/julianDay.o : source/julianDay.h source/julianDay.cpp
	$(CC) $(CFLAGS) -c -o obj/julianDay.o source/julianDay.cpp

obj/solarPhysics.o : source/solarPhysics.h source/solarPhysics.cpp
	$(CC) $(CFLAGS) -c -o obj/solarPhysics.o source/solarPhysics.cpp

obj/parseOptarg.o : source/parseOptarg.h source/parseOptarg.cpp
	$(CC) $(CFLAGS) -c -o obj/parseOptarg.o source/parseOptarg.cpp

clean:
	rm -rf obj/*.o
	rm sunpos