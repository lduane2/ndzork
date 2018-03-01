#ifndef ITEM_HOUSE_HPP
#define ITEM_HOUSE_HPP

#include "../../item.hpp"

class House : public Item {
public:
	std::string get_name();
private:
	std::string name = "house";
};

#endif
