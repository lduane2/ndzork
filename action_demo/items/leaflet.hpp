#ifndef ITEM_LEAFLET_HPP
#define ITEM_LEAFLET_HPP

#include "../../item.hpp"
#include "../../command.hpp"

class Leaflet : public Item {
public:
	Leaflet();
	std::string get_name();
	std::string get_descr();
	bool handle(Command command);
private:
	std::string name = "leaflet";
	std::string description = "\"WELCOME TO ZORK!\n\nZORK is a game of adventure, danger, and low cunning. In it you will explore some of the most amazing territory ever seen by mortals. No computer should be without one!\"\n";
};

#endif
