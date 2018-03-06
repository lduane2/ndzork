#include "../../include/rooms/jesus_statue.hpp"

Jesus_Statue::Jesus_Statue() {
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
