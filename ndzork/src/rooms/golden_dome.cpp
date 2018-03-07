#include "../../include/rooms/golden_dome.hpp"

#include "../../include/items/candle.hpp"
#include "../../include/items/stairs.hpp"

Golden_Dome::Golden_Dome() {
	add_item(new Candle());
	add_item(new Stairs());
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
