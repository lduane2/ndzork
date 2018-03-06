#include "../../include/items/candle.hpp"
#include "../../include/game/gameio.hpp"

std::string Candle::get_name() {
	return name;
}

std::string Candle::get_descr() {
	std::string descr;
	if (!is_lit) {
		return "The "+get_name()+" is unlit.";
	}
	else {
		descr = "The "+get_name()+" is lit.";
	}

	return descr;
}

bool Candle::handle(Command c) {
	std::string verb(c.get_verb());
	if (c.get_dobj() == this) {
		if 		(verb == "light"){
		 	return light(c);
		} else if (verb == "take"){
			return take(c);
		} else if (verb == "put"){
			return put(c);
		}
	}

	return Item::handle(c);
}

bool Candle::take(Command c) {
	if (is_lit){
		print("You can't pick up a lit candle!\n");
	} else {
		print("You took the candle\n");
		Room * room = c.get_room();
		room->remove_item(this);
		Actor * actor = c.get_actor();
		actor->add_item(this);
	}
	return true;
}

bool Candle::put(Command c){
	//check if you have the candle
	Room * room = c.get_room();
	Actor * actor = c.get_actor();
	if(actor->check_item(this)){
		//put the candle down
		print("You put the candle down\n");
		room->add_item(this);
		actor->remove_item(this);
		return true;
	} else {
		print("You don't have a candle to put down\n");
		return true;
	}
}

bool Candle::light(Command c) {
	//check if indirect object
	auto iobj = c.get_iobj();
	auto actor = c.get_actor();
	if(iobj == nullptr){
		print("Light the candle with what?\n");
		return true;
	} else if (iobj->get_name() == "matches"){
		if(actor->check_item(iobj->get_name())){ //actor has matches
			//lighting the candle
			if (is_lit) {
				print("The candle is already lit.\n");
				return true;
			}
			else {
				is_lit = true;
				print("Lit the candle.\n"); 
				return true;
			}
		} else {
			print("You do not have any matches\n");
			return true;
		}
	} else {
		print("You cannot do that\n");
		return true;
	}
}
