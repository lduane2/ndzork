#ifndef ITEM_STONES_HPP
#define ITEM_STONES_HPP

#include "item.hpp"
#include "../command.hpp"

class Stones : public Item {
public:
	std::string get_name();
	std::string get_descr();
	bool handle(Command command);

private:
	std::string name = "stones";
};

#endif