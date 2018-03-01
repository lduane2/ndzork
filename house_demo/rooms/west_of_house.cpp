#include "west_of_house.hpp"

#include "../items/small_mailbox.hpp"
#include "../items/house.hpp"

#include "../actors/adventurer.hpp"

West_Of_House::West_Of_House() {
	items.push_back(new Small_Mailbox());
	items.push_back(new House());

	actors.push_back(new Adventurer());
}

std::string West_Of_House::get_name() {
	return name;
}
