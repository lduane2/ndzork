#include "small_mailbox.hpp"

Small_Mailbox::Small_Mailbox() {
	defined_actions.insert("open");
}

std::string Small_Mailbox::get_name() {
	return name;
}

std::string Small_Mailbox::perform_action(Parse parse) {
	std::string action = parse.get_action();
	if (action == "open") {
		return open(parse);
	}
	else {
		return "You can't do that to a " + get_name() + ".";
	}
}

std::string Small_Mailbox::open(Parse parse) {
	std::string indobj = parse.get_indobj();
	if (indobj != "") {
		return "You can't open a " + get_name() + " using " + indobj + ".";
	}

	if (is_open) {
		return "It is already open!";
	}
	else {
		is_open = false;
		return "The " + get_name() +" is now shut.";
	}
}

