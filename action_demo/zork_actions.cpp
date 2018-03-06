#include "zork.hpp"

#include "../gameio.hpp"

bool Zork::look(Command /*c*/) {
	return false;
}

bool Zork::close(Command c) {
	if (c.get_dobj() == nullptr) {
		print("Close what?\n");
		return true;
	}
	return false;
}

bool Zork::open(Command c) {
	if (c.get_dobj() == nullptr) {
		print("Open what?\n");
		return true;
	}
	return false;
}

bool Zork::quit(Command /*c*/) {
	print("Your score is ", score, " (total of ", max_score, "), in ", moves, ".\n");
	print("This gives you a rank of ", get_rank(), ".\n");
	print("Do you wish to leave the game? (Y is affirmative): ");
	std::string input(get_input_line());
	if ((input[0] == 'y' || input[0] == 'Y') &&
			(input.length() == 1)) {
		ended = true;
	}
	else {
		print("Ok.\n");
	}
	return true;
}


bool Zork::yell(Command /*c*/) {
    print("YAAAAAARGGGGGHHH!\n");
    return true;
}

bool Zork::light(Command c) {
	if (c.get_dobj() == nullptr) {
		print("Light what?\n");
		return true;
	}
	return false;
}