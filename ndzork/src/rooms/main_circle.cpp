#include "../../include/rooms/main_circle.hpp"
#include "../../include/items/matches.hpp"
#include "../../include/misc.hpp"

Main_Circle::Main_Circle() {
    add_item(new Matches());
}

std::string Main_Circle::get_name() {
	return name;
}

std::string Main_Circle::get_descr() {
	return description;
}

bool Main_Circle::handle(Command c) {
	return Room::handle(c);
}
