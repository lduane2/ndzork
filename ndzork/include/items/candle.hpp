#ifndef ITEM_CANDLE_HPP
#define ITEM_CANDLE_HPP

#include "item.hpp"
#include "../command.hpp"
#include "../../include/actors/actor.hpp"
#include "../../include/rooms/room.hpp"

class Candle : public Item {
public:
	std::string get_name();
	std::string get_descr();
	bool is_takeable();
	bool handle(Command command);

private:
	bool is_lit = false;
	std::string name = "candle";

	//Actions
	bool put(Command command);
	bool light(Command command);
	bool extinguish();
};

#endif
