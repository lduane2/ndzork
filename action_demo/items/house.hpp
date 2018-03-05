#ifndef ITEM_HOUSE_HPP
#define ITEM_HOUSE_HPP

#include "../../item.hpp"

class House : public Item {
public:
	std::string get_name();
	std::string get_descr();
private:
	std::string name = "house";
	std::string description = "The house is a beautiful colonial house which is painted white. It is clear that the owners must have been extremely wealthy";
};

#endif
