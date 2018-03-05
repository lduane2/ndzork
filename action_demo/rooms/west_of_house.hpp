#ifndef ROOM_WEST_OF_HOUSE_HPP
#define ROOM_WEST_OF_HOUSE_HPP

#include "../../room.hpp"

#include <string>

class West_Of_House : public Room {
public:
	West_Of_House();
	std::string get_name();
	std::string get_descr();
private:
	std::string name = "West of House";
	std::string description = "You are standing in an open field west of a white house, with a boarded front door.";

	bool handle(Command c);
};

#endif
