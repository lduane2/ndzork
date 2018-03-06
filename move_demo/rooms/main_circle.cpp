#include "main_circle.hpp"

#include "../items/mailbox.hpp"
#include "../items/house.hpp"
#include "../items/jesusStatue.hpp"
#include "../actors/adventurer.hpp"



Main_Circle::Main_Circle() {
//	add_item(new Mailbox());
//	add_item(new House());
    
    add_item(new jesusStatue());
    add_misc(new Misc("north"));

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
