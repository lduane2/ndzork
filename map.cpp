#include "map.hpp"

Map::~Map() {
	for (Room *room : get_rooms()) {
		delete room;
	}
}

void Map::add_room(Room *r) {
	rooms.insert(r);
}

void Map::remove_room(Room *r) {
	rooms.erase(r);
}

std::unordered_set<Room *> Map::get_rooms() {
	return rooms;
}
