#include "../../include/actors/actor.hpp"
#include "../../include/game/gameio.hpp"

Actor::~Actor() {
	for (auto item : get_items()) {
		delete item;
	}
}

void Actor::add_item(Item *item) {
	items.insert(item);
}

//checks if Actor has the item in inventory
bool Actor::check_item(Item *item){
	for (auto it: items){
		if (it == item){
			return true;
		}
	}
	return false;
}

void Actor::remove_item(Item *item) {
	items.erase(item);
}

std::unordered_set<Item *> Actor::get_items() {
	return items;
}

bool Actor::handle(Command c) {
	std::string verb = c.get_verb();
	if(verb == "inv"){
		//check size of inventory
		if(items.size() == 0){
			print("You have nothing in your inventory\n");
			return true;
		} else {
			print("Here is your inventory\n");
			for(auto it : items){
				print("\t", it->get_name(), "\n");
			}
			return true;
		}
	} else {
		return Object::handle(c);
	}
}

