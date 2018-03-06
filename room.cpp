#include "room.hpp"

#include "gameio.hpp"

#include <string>

Room::~Room() {
	for (auto item : get_items()) {
		delete item;
	}

	for (auto actor : get_actors()) {
		delete actor;
	}
}

std::unordered_set<Item *> Room::get_items() {
	return items;
}

std::unordered_set<Actor *> Room::get_actors() {
	return actors;
}

std::unordered_set<Misc *> Room::get_miscs() {
	return miscs;
}




std::unordered_map<std::string, Room *> Room::get_dir_table() {
	return dir_table;
}



void Room::add_item(Item *item) {
	items.insert(item);
}
void Room::add_actor(Actor *actor) {
	actors.insert(actor);
}
/*void Room::add_adj_room(std::string dir, Room *room) {
	dir_table[dir] = room;
}
*/
void Room::add_misc(Misc *misc) {
    miscs.insert(misc);
}


void Room::remove_item(Item *item) {
	items.erase(item);
}
void Room::remove_actor(Actor *actor) {
	actors.erase(actor);
}
void Room::remove_adj_room(Room *room) {
	adj_rooms.erase(room);
}

bool Room::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "look") return look(c);
	}
	else if (c.get_dobj() == nullptr) {
		if (verb == "look") return look(c);
	}

	return Object::handle(c);
}

// Actions
bool Room::look(Command c) {
	print(get_descr(), "\n");
	for (auto item : get_items()) {
		print("There is a ", item->get_name(), " here.\n");
	}
	for (auto actor : get_actors()) {
		if (actor == c.get_actor()) continue;
		print("There is a ", actor->get_name(), " here.\n");
	}
	return true;
}

