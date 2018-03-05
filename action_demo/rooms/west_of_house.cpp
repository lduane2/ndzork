#include "west_of_house.hpp"

#include "../items/mailbox.hpp"
#include "../items/house.hpp"
#include "../actors/adventurer.hpp"

West_Of_House::West_Of_House() {
	add_item(new Mailbox());
	add_item(new House());
}

std::string West_Of_House::get_name() {
	return name;
}

std::string West_Of_House::get_descr() {
	return description;
}

bool West_Of_House::handle(Command c) {
	return Room::handle(c);
}
