#include "map.hpp"

Map::~Map() {
	for (Room *room : get_rooms()) {
		delete room;
	}
}

void Map::add_room(Room *r) {
	rooms.push_back(r);
}

std::vector<Room *> Map::get_rooms() {
	return rooms;
}
