#ifndef ROOM_HPP
#define ROOM_HPP

#include "object.hpp"
#include "item.hpp"
#include "actor.hpp"
#include "command.hpp"
#include "misc.hpp"


#include <unordered_set>
#include <string>
class Room : public Object {
public:
	virtual ~Room();

	std::unordered_set<Item *> get_items();
	std::unordered_set<Actor *> get_actors();
	std::unordered_map<std::string, Room *> get_dir_table();
    std::unordered_set<Misc *> get_miscs();
    
    
	void add_item(Item *item);
	void add_actor(Actor *actor);
	void add_adj_room(std::string, Room *room);
    void add_misc(Misc *misc);

	void remove_item(Item *item);
	void remove_actor(Actor *actor);
	void remove_adj_room(Room *room);

	virtual bool handle(Command c);

protected:
	std::unordered_set<Item *> items;
	std::unordered_set<Actor *> actors;
	std::unordered_set<Room *> adj_rooms;

    std::unordered_set<Misc *> miscs;

    std::unordered_map<std::string,Room *> dir_table;

	// Actions
	virtual bool look(Command c);
};

#endif
