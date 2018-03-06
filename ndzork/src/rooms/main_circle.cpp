#include "../../include/rooms/main_circle.hpp"
#include "../../include/items/matches.hpp"
#include "../../include/misc.hpp"




Main_Circle::Main_Circle() {
//	add_item(new Mailbox());
//	add_item(new House());
    
    add_item(new Matches());
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
