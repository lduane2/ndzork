#include "object.hpp"

#include "gameio.hpp"

Object::~Object() {
}

bool Object::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "look") {
			print(get_descr(),'\n');
			return true;
		}
	}
	return false;
}
