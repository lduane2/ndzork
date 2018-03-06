#include "../../include/items/statue.hpp"

#include "../../include/game/gameio.hpp"

std::string Statue::get_name() {
	return name;
}

std::string Statue::get_descr() {
	return descr;
}

bool Statue::handle(Command c) {
	return Item::handle(c);
}

