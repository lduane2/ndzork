#include "../../include/items/stones.hpp"

#include "../../include/game/gameio.hpp"

std::string Stones::get_name() {
	return name;
}

std::string Stones::get_descr() {
	return "These are the stones that fell off the Jesus Statue enclosement. They say \"il y un moyen d\'eclairer le monde\". From your semester in French, it translates to \"there is one way to light the world\"";
}

bool Stones::handle(Command c) {
	return Item::handle(c);
}

