#ifndef ROOM_WEST_OF_HOUSE_HPP
#define ROOM_WEST_OF_HOUSE_HPP

#include "../../room.hpp"

#include <string>

class West_Of_House : public Room {
public:
	West_Of_House();
	std::string get_name();
private:
	std::string name = "West of House";
};

#endif
