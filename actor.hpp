#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "object.hpp"
#include "item.hpp"
#include <vector>

class Actor : public Object {
public:
	virtual ~Actor();
	std::vector<Item *> get_items();
private:
	std::vector<Item *> items;
};

#endif
