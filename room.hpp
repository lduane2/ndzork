#ifndef ROOM_HPP
#define ROOM_HPP

#include "object.hpp"
#include "item.hpp"
#include "actor.hpp"
#include <vector>

class Room : public Object {
public:
	virtual ~Room();
	// void enter();
	// void exit();
	std::vector<Item *> get_items();
	std::vector<Actor *> get_actors();
	std::vector<Room *> get_adj_rooms();
protected:
	std::vector<Item *> items;
	std::vector<Actor *> actors;
	std::vector<Room *> adj_rooms;
};

#endif
