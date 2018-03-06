#include "../../include/items/stones.hpp"

#include "../../include/game/gameio.hpp"

std::string Stones::get_name() {
	return name;
}

std::string Stones::get_descr() {
	std::string descr = "These are the stones that fell off the Jesus Statue enclosement. \nThey say \"il y un moyen d\'eclairer le monde\". \nFrom your semester in French, it translates to \"there is one way to light the world\".";
	return descr;
}

bool Stones::handle(Command c) {
	return Item::handle(c);
}

