#include "../../include/items/matches.hpp"
#include "../../include/game/gameio.hpp"

std::string Matches::get_name() {
	return name;
}

std::string Matches::get_descr() {
	std::string descr = "It looks like a regular box of matches\n";

	return descr;
}

bool Matches::handle(Command c) {
	std::string verb(c.get_verb());
	if (c.get_dobj() == this) {
		if (verb == "take"){
			return take(c);
		} else if (verb == "put"){
			return put(c);
		}
	}

	return Item::handle(c);
}

bool Matches::take(Command c) {
	print("You took the matches\n");
	Room * room = c.get_room();
	room->remove_item(this);
	Actor * actor = c.get_actor();
	actor->add_item(this);
	return true;
}

bool Matches::put(Command c){
	//check if you have the candle
	Room * room = c.get_room();
	Actor * actor = c.get_actor();
	if(actor->check_item(this)){
		//put the matches down
		print("You put the matches down\n");
		room->add_item(this);
		actor->remove_item(this);
		return true;
	} else {
		print("You don't have any matches to put down\n");
		return true;
	}
}

