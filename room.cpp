#include "room.hpp"

Room::~Room() {
	for (auto item : get_items()) {
		delete item;
	}

	for (auto actor : get_actors()) {
		delete actor;
	}

	//It is Map's duty to release room memory
}
std::vector<Item *> Room::get_items() {
	return items;
}

std::vector<Actor *> Room::get_actors() {
	return actors;
}

std::vector<Room *> Room::get_adj_rooms() {
	return adj_rooms;
}
