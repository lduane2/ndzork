#ifndef MAP_HPP
#define MAP_HPP

#include "room.hpp"

#include <unordered_set>

class Map {
public:
	~Map();
	void add_room(Room *r);
	void remove_room(Room *r);
	std::unordered_set<Room *> get_rooms();
private:
	std::unordered_set<Room *> rooms;
};

#endif
