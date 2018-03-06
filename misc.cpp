#include "misc.hpp"

#include "gameio.hpp"




Misc::~Misc() {
	for (auto misc : get_miscs()) {
		delete misc;
	}
}

std::unordered_set<Misc *> Misc::get_miscs() {
	return miscs;
}



void Misc::add_misc(Misc *misc) {
	miscs.insert(misc);
}

void Misc::remove_misc(Misc *misc) {
	miscs.erase(misc);
}

bool Misc::handle(Command c) {
	return Object::handle(c);
}
