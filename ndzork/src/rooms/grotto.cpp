#include "../../include/rooms/grotto.hpp"

#include "../../include/items/cave.hpp"

Grotto::Grotto() {
	add_item(new Cave());
}

std::string Grotto::get_name() {
	return name;
}

std::string Grotto::get_descr() {
	return description;
}

bool Grotto::handle(Command c) {
	return Room::handle(c);
}
