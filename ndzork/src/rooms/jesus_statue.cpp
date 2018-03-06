#include "../../include/rooms/jesus_statue.hpp"
#include "../../include/items/candle.hpp"

Jesus_Statue::Jesus_Statue() {
	add_item(new Candle());
}

std::string Jesus_Statue::get_name() {
	return name;
}

std::string Jesus_Statue::get_descr() {
	return description;
}

bool Jesus_Statue::handle(Command c) {
	return Room::handle(c);
}