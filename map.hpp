#ifndef MAP_HPP
#define MAP_HPP

#include "room.hpp"

#include <vector>

class Map {
public:
	~Map();
	void add_room(Room *r);
	std::vector<Room *> get_rooms();
private:
	std::vector<Room *> rooms;
};

#endif
