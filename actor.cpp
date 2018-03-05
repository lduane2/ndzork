#include "actor.hpp"


Actor::~Actor() {
	for (auto item : get_items()) {
		delete item;
	}
}

void Actor::add_item(Item *item) {
	items.insert(item);
}

void Actor::remove_item(Item *item) {
	items.erase(item);
}

std::unordered_set<Item *> Actor::get_items() {
	return items;
}

bool Actor::handle(Command c) {
	return Object::handle(c);
}

