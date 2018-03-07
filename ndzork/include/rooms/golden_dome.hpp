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
	std::string description = "Before you lies the master of your fate: the University of Notre Dame administration building. Adorning the top is an enormous golden dome; the Jewel of South Bend. Since it is cloudy, the dome doesnt look all that shiny. From the east floats a vague smell of food that you cannot quite specify. To the west there's a hint of smoke in the air.";
};

#endif
