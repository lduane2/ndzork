#include "../../include/items/item.hpp"
#include "../../include/rooms/room.hpp"
#include "../../include/game/gameio.hpp"

#include <iostream>

Item::~Item() {
	for (auto item : get_items()) {
		delete item;
	}
}

std::unordered_set<Item *> Item::get_items() {
	return items;
}

void Item::add_item(Item *item) {
	items.insert(item);
}

void Item::remove_item(Item *item) {
	items.erase(item);
}

bool Item::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "look") return look(c);
		if (verb == "take") return take(c);
	}

	return Object::handle(c);
}

bool Item::look(Command /*c*/) {
	print(get_descr(), "\n");
	for (auto item : get_items()) {
		print("There is a ", item->get_name(), " here.\n");
	}
	return true;
}

bool Item::take(Command c) {
	std::cout << "item take" << std::endl;
	// Sanity check
	if (!is_takeable()) {
		print("You cannot take that\n");
		return true;
	}

	// Find and remove item
	Room *room = c.get_room();
	for (Item *item : room->get_items()) {
		if (item == this) {
			room->remove_item(this);
			break;
		}
		for (Item *inner_item : item->get_items()) {
			if (inner_item == this) {
				item->remove_item(this);
				break;
			}
		}
	}

	// Move the item
	c.get_actor()->add_item(this);
	print("You took the ", this->get_full_name(), "\n");
	return true;
}
