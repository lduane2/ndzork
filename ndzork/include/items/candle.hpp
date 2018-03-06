#ifndef ITEM_CANDLE_HPP
#define ITEM_CANDLE_HPP

#include "item.hpp"
#include "../command.hpp"

class Candle : public Item {
public:
	std::string get_name();
	std::string get_descr();
	bool handle(Command command);

private:
	bool is_lit = false;
	std::string name = "candle";

	//Actions
	bool light();
};

#endif