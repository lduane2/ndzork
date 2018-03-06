#include "../../include/items/candle.hpp"

#include "../../include/game/gameio.hpp"

std::string Candle::get_name() {
	return name;
}

std::string Candle::get_descr() {
	std::string descr;
	if (!is_lit) {
		return "The "+get_name()+" is unlit.";
	}
	else {
		descr = "The "+get_name()+" is lit";
	}

	return descr;
}

bool Candle::handle(Command c) {
	std::string verb(c.get_verb());
	if (c.get_dobj() == this) {
		if 		(verb == "light") return light();
	}
	return Item::handle(c);
}

bool Candle::light() {
	if (is_lit) {
		print("The candle is already lit.\n");
	}
	else {
		is_lit = true;
		print("The candle is lit.\n"); 
	}

	return true;
}
