#include "../include/object.hpp"

#include "../include/game/gameio.hpp"

Object::~Object() {
}

bool Object::handle(Command /*c*/) {
	return false;
}
