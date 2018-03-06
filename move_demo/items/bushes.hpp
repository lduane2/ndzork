#ifndef ITEM_BUSHES_HPP
#define ITEM_BUSHES_HPP

#include "../../item.hpp"
#include "../../command.hpp"

class Bushes : public Item {
public:
	Mailbox();
	std::string get_name();
	std::string get_descr();
	bool handle(Command command);
private:
	bool is_open = false;
	std::string name = "bushes";

	// Actions
	bool open();
	bool close();
};

#endif
