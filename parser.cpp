#include "parser.hpp"
#include "room.hpp"
#include "item.hpp"
#include "actor.hpp"

#include <sstream>

Parser::Parser(Map *map) {
	// Get room names from map
	for (auto room : map->get_rooms()) {
		rooms.insert(room->get_name());
		for (auto action : room->defined_actions) {
			actions.insert(action);
		}

		// Get item names from room
		for (auto item : room->get_items()) {
			items.insert(item->get_name());
			for (auto action : item->defined_actions) {
				actions.insert(action);
			}
		}

		// Get actor names from room
		for (auto actor : room->get_actors()) {
			actors.insert(actor->get_name());
			for (auto action : actor->defined_actions) {
				actions.insert(action);
			}
			// Get item names from actor
			for (auto item : actor->get_items()) {
				items.insert(item->get_name());
				for (auto action : item->defined_actions) {
					actions.insert(action);
				}
			}
		}
	}

}

Parse Parser::parse(std::string input) {
	std::string action, dobj, iobj;
	std::stringstream words(input);
	std::string word;
	while (words >> word) {
		if (actions.find(word) != actions.end()) {
			action = word;
			break;
		}
	}

	while (words >> word) {
		if (actors.find(word) != actors.end()) {
			dobj = word;
			break;
		}
		else if (items.find(word) != items.end()) {
			dobj = word;
			break;
		}
		else if (rooms.find(word) != rooms.end()) {
			dobj = word;
			break;
		}
	}

	while (words >> word) {
		if (actors.find(word) != actors.end()) {
			iobj = word;
			break;
		}
		else if (items.find(word) != items.end()) {
			iobj = word;
			break;
		}
		else if (rooms.find(word) != rooms.end()) {
			iobj = word;
			break;
		}
	}

	return Parse(action, dobj, iobj);
}
