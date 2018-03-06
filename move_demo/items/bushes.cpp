#include "bushes.hpp"

#include "../../gameio.hpp"
#include "leaflet.hpp"

Mailbox::Mailbox() {
	add_item(new Leaflet());
}

std::string Mailbox::get_name() {
	return name;
}

std::string Mailbox::get_descr() {
	std::string descr;
	if (!is_open) {
		return "The "+get_name()+" is closed.";
	}

	if (get_items().empty()) {
		descr = "The "+get_name()+" is empty.";
	}
	else {
		descr = "The "+get_name()+" contains:\n";
		for (auto item : get_items()) {
			descr += "  A "+item->get_name()+".\n";
		}
	}
	return descr;
}

bool Mailbox::handle(Command c) {
	std::string verb(c.get_verb());
	if (c.get_dobj() == this) {
		if      (verb == "open") return open();
		else if (verb == "close") return close();
	}

	return Item::handle(c);
}

bool Mailbox::open() {
	if (is_open) {
		print("It is already open.\n");
	}
	else {
		is_open = true;
		if (!get_items().empty()) {
			print("Searching the bush reveals a "+(*get_items().begin())->get_name()+".\n");
		}
		else {
			print("Opened.\n");
		}
	}
	return true;
}

bool Mailbox::close() {
	if (is_open) {
		is_open = false;
		print("Closed.\n");
	}
	else {
		print("It is already closed.\n");
	}
	return true;
}
