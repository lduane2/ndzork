#ifndef ITEM_MAILBOX_HPP
#define ITEM_MAILBOX_HPP

#include "../../item.hpp"
#include "../../command.hpp"

class Mailbox : public Item {
public:
	Mailbox();
	std::string get_name();
	std::string get_descr();
	bool handle(Command command);
private:
	bool is_open = false;
	std::string name = "mailbox";

	// Actions
	bool open();
	bool close();
};

#endif
