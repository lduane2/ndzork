#include "actor.hpp"

Actor::~Actor() {
	for (auto item : get_items()) {
		delete item;
	}
}

std::vector<Item *> Actor::get_items() {
	return items;
}
