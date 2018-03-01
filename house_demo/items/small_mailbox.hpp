#ifndef ITEM_SMALL_MAILBOX_HPP
#define ITEM_SMALL_MAILBOX_HPP

#include "../../item.hpp"
#include "../../parse.hpp"

class Small_Mailbox : public Item {
public:
	Small_Mailbox();
	std::string get_name();
	std::string perform_action(Parse parse);
private:
	bool is_open = false;
	std::string name = "mailbox";

	std::string open(Parse parse);
};

#endif
