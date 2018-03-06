#include "main_circle.hpp"

//#include "../items/mailbox.hpp"
//#include "../items/house.hpp"
#include "../items/jesusStatue.hpp"
#include "../actors/adventurer.hpp"
#include "../../gameio.hpp"


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
    std::string verb = c.get_verb();
    Object * mobj = c.get_dobj();
    print("checkin main circle");
    if (verb == "go") {
        if (mobj->get_name() == "north") {
            print ("success");
            return true;
        }
    
    }


    

	return Room::handle(c);
}
