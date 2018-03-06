CXX=g++ -std=gnu++11 -Wall -Wextra -Wfatal-errors

all: action_demo

PARSER=../parser.o ../parse.o
OBJECTS=../map.o ../gameio.o ../game.o ../object.o ../room.o ../item.o ../actor.o ../command.o
GAME=zork.o zork_actions.o
ITEMS=items/house.o items/mailbox.o items/leaflet.o items/jesusStatue.o items/candle.o
ACTORS=actors/adventurer.o
ROOMS=rooms/west_of_house.o

action_demo: main.o $(OBJECTS) $(GAME) $(ROOMS) $(ITEMS) $(ACTORS) $(PARSER)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm action_demo main.o $(OBJECTS) $(ROOMS) $(ITEMS) $(ACTORS) $(PARSER)
