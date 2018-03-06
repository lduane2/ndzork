#include "../../include/rooms/room.hpp"

#include "../../include/game/gameio.hpp"

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

std::unordered_set<Room *> Room::get_adj_rooms() {
	return adj_rooms;
}

void Room::add_item(Item *item) {
	items.insert(item);
}
void Room::add_actor(Actor *actor) {
	actors.insert(actor);
}
void Room::add_adj_room(Room *room) {
	adj_rooms.insert(room);
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

bool Room::look(Command c) {
	print(get_name(), "\n");
	print(get_descr(), "\n");
	for (auto actor : get_actors()) {
		if (actor == c.get_actor()) continue;
		print("There is a ", actor->get_full_name(), " here.\n");
	}

	for (auto item : get_items()) {
		print("There is a ", item->get_full_name(), " here.\n");
		if (!item->get_items().empty()) {
			print("The ", item->get_full_name(), " contains:\n");
			for (auto inner_item : item->get_items()) {
				print("  A ", inner_item->get_full_name(), "\n");
			}
		}
	}
	print("\n");

	return true;
}

