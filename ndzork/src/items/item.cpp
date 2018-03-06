#include "../../include/items/item.hpp"

#include "../../include/game/gameio.hpp"

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
