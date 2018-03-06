#include "../../include/game/ndzork.hpp"

#include "../../include/game/gameio.hpp"

bool NDZork::look(Command /*c*/){
	return false;
}

bool NDZork::light(Command c){
	if (c.get_dobj() == nullptr) {
		print("Light what?\n");
		return true;
	}
	return false;
}

bool NDZork::quit(Command /*c*/){
	print("Do you wish to leave the game? (y/n): ");
	std::string input(get_input_line());
	if((input[0] == 'y' || input[0] == 'Y') && (input.length() == 1)){
		ended = true;
	} else {
		print("Ok.\n");
	}
	return true;
}

bool NDZork::take(Command /*c*/){
	return false;
}

bool NDZork::put(Command /*c*/){
	return false;
}