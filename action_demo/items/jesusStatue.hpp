#ifndef ITEM_STATUE_HPP
#define ITEM_STATUE_HPP

#include "../../item.hpp"

class jesusStatue : public Item {
public:
	std::string get_name();
	std::string get_descr();
private:
	std::string name = "statue";
	std::string description = "The statue of Jesus is old and worn with the weather, but fills you with a strong resolve to do something meaningful in your life.";
};

#endif
