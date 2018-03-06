#ifndef ROOM_MAIN_CIRCLE_HPP
#define ROOM_MAIN_CIRCLE_HPP

#include "../../room.hpp"

#include <string>

class Main_Circle : public Room {
public:
	Main_Circle();
	std::string get_name();
	std::string get_descr();
private:
	std::string name = "Main";
	std::string description = "You are standing in an green space surrounded by a traffic circle.  Taxis and Ubers occassionaly come and go, maing this a peaceful,yet busy, area.";

	bool handle(Command c);
};

#endif
