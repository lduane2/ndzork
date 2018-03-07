#include "../../include/rooms/golden_dome.hpp"
Golden_Dome::Golden_Dome() {
//	add_item(new Candle());
//	add_item(new Stones());
	//add_item(new Matches());
//	add_item(new Statue());
}

std::string Golden_Dome::get_name() {
	return name;
}

std::string Golden_Dome::get_descr() {
	return description;
}

bool Golden_Dome::handle(Command c) {
	return Room::handle(c);
}
