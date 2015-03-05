OBJECTS=map.o actor.o entity.o object.o terrain.o tile.o tools.o

all : test

test : $(OBJECTS)
	g++ $(OBJECTS) -o test
map.o : map.cpp
	g++ -c map.cpp
actor.o : ../src/actor.cpp
	g++ -c ../src/actor.cpp
entity.o : ../src/entity.cpp
	g++ -c ../src/entity.cpp
object.o : ../src/object.cpp
	g++ -c ../src/object.cpp
terrain.o : ../src/terrain.cpp
	g++ -c ../src/terrain.cpp
tile.o : ../src/tile.cpp
	g++ -c ../src/tile.cpp
tools.o : ../src/tools.cpp
	g++ -c ../src/tools.cpp

clean :
	rm -rf *.o
