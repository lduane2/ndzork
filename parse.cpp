#include "parse.hpp"

Parse::Parse(){
}

Parse::Parse(std::string action, std::string dirobj, std::string indobj) :
	action(action), dirobj(dirobj), indobj(indobj) {
}

std::string Parse::get_action() {
	return action;
}
std::string Parse::get_dirobj() {
	return dirobj;
}
std::string Parse::get_indobj() {
	return indobj;
}
