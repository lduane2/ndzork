CXX=g++ -std=gnu++11 -Wall -Wextra -Wfatal-errors

all: ndzork

PARSER=src/parse/parser.o src/parse/parse.o
OBJECTS=src/map.o src/game/gameio.o src/game/game.o src/object.o src/rooms/room.o src/items/item.o src/actors/actor.o src/command.o src/misc.o
GAME=src/game/ndzork.o src/game/ndzork_actions.o
ITEMS=src/items/candle.o src/items/stones.o src/items/matches.o src/items/statue.o
ACTORS=src/actors/luke.o  src/actors/jank.o
ROOMS=src/rooms/jesus_statue.o src/rooms/main_circle.o

ndzork: main.o $(OBJECTS) $(GAME) $(ROOMS) $(ITEMS) $(ACTORS) $(PARSER)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm ndzork main.o $(OBJECTS) $(GAME) $(ROOMS) $(ITEMS) $(ACTORS) $(PARSER)
