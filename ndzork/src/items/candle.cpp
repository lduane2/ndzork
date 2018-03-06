#include "candle.hpp"

#include "../../gameio.hpp"

/*
Candle::Candle() {}
*/

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
		//else if (verb == "putout") return putout();
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
/*
bool Candle::putout(){
	if (is_lit) {
		is_lit = false;
		print("Candle put out.\n");
	}
	else {
		print("The candle is not lit.\n");
	}
	return true;
}*/
