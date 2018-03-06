#include "../include/object.hpp"

#include "../include/game/gameio.hpp"

Object::~Object() {
}

std::string Object::get_full_name() {
	return get_name();
}

bool Object::handle(Command /*c*/) {
	return false;
}
