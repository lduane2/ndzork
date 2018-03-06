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
	return Object::handle(c);
}
