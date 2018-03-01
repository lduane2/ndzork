CXX=g++ -std=gnu++11

all: house_demo

PARSER=../parser.o ../parse.o
OBJECTS=../map.o ../object.o ../room.o ../item.o ../actor.o
ITEMS=items/house.o items/small_mailbox.o
ACTORS=actors/adventurer.o
ROOMS=rooms/west_of_house.o

house_demo: main.o $(OBJECTS) $(ROOMS) $(ITEMS) $(ACTORS) $(PARSER)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm house_demo main.o $(OBJECTS) $(ROOMS) $(ITEMS) $(ACTORS) $(PARSER)
