#ifndef ITEM_HPP
#define ITEM_HPP

#include "command.hpp"
#include "object.hpp"

#include <unordered_set>

class Item : public Object {
public:
	virtual ~Item();
 	std::unordered_set<Item *> get_items();
	void add_item(Item *item);
	void remove_item(Item *item);

	virtual bool handle(Command command);

private:
	std::unordered_set<Item *> items;
};

#endif
