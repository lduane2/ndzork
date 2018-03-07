#ifndef ROOM_GOLDEN_DOME_HPP
#define ROOM_GOLDEN_DOME_HPP

#include "room.hpp"

#include <string>

class Golden_Dome : public Room {
public:
	Golden_Dome();
	std::string get_name();
	std::string get_descr();
	bool handle(Command c);
private:
	std::string name = "The Golden Dome";
	std::string description = "You are right underneath the Golden Dome.  Since it is cloudy, the dome doesnt look all that shiny.  There is a path to the south.";
};

#endif
