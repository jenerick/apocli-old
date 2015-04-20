# Makefile

EXE=apocli
DEP=actor display entity game input main object signal terrain tile tools ui world

SRC_DIR=src/
BIN_DIR=bin/
OBJ_DIR=obj/

OBJECTS=$(addprefix $(OBJ_DIR), $(addsuffix .o, $(DEP)))

OPT=-march=native -Wall -O2

all : $(SRC_DIR) $(BIN_DIR) $(OBJ_DIR) bin/$(EXE)

bin/$(EXE) : $(OBJECTS)
	g++ -o bin/$(EXE) $(OBJECTS)

obj/%.o: src/%.cpp
	g++ $(OPT) -c $< -o $@

#obj/actor.o : src/actor.cpp
#	g++ $(OPT) -c src/actor.cpp
#
#obj/display.o : src/display.cpp
#	g++ $(OPT) -c src/display.cpp
#
#obj/entity.o : src/entity.cpp
#	g++ -c src/entity.cpp
#
#obj/game.o : src/game.cpp
#	g++ -c src/game.cpp
#
#obj/input.o : src/input.cpp
#	g++ -c src/input.cpp
#
#obj/main.o : src/main.cpp
#	g++ -c src/main.cpp
#
#obj/object.o : src/object.cpp
#	g++ -c src/object.cpp
#
#obj/terrain.o : src/terrain.cpp
#	g++ -c src/terrain.cpp
#
#obj/tile.o : src/tile.cpp
#	g++ -c src/tile.cpp
#
#obj/tools.o : src/tools.cpp
#	g++ -c src/tools.cpp -o
#
#obj/ui.o : src/ui.cpp
#	g++ -c src/ui.cpp -o obj/ui.o
#
#obj/world.o : src/world.cpp
#	g++ -c src/world.cpp -o obj/world.o

clean :
	rm -rf bin/$(EXE) obj/*.o
