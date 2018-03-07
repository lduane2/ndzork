#include "../include/object.hpp"

#include <iostream>

Object::~Object() {
}

std::string Object::get_full_name() {
	return get_name();
}

bool Object::handle(Command /*c*/) {
	return false;
}

bool Object::can_contain_items() {
	return false;
}

std::unordered_set<Item *> Object::get_items() {
	return items;
}

void Object::add_item(Item *item) {
	std::cout << "log: " << get_name() << " is adding item " << ((Object *)item)->get_name() << std::endl;
	items.insert(item);
}

void Object::remove_item(Item *item) {
	std::cout << "log: " << get_name() << " is removing item " << ((Object *)item)->get_name() << std::endl;
	items.erase(item);
}
