#ifndef ROOM_HPP
#define ROOM_HPP

#include "../object.hpp"
#include "../command.hpp"
#include "../items/item.hpp"
#include "../actors/actor.hpp"

#include <unordered_set>

class Room : public Object {
public:
	virtual ~Room();

	std::unordered_set<Item *> get_items();
	std::unordered_set<Actor *> get_actors();
	std::unordered_set<Room *> get_adj_rooms();

	void add_item(Item *item);
	void add_actor(Actor *actor);
	void add_adj_room(Room *room);

	void remove_item(Item *item);
	void remove_actor(Actor *actor);
	void remove_adj_room(Room *room);

	virtual bool handle(Command c);

protected:
	std::unordered_set<Item *> items;
	std::unordered_set<Actor *> actors;
	std::unordered_set<Room *> adj_rooms;

	virtual bool look(Command c);
};

#endif
