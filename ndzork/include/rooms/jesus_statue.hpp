#ifndef ROOM_JESUS_STATUE_HPP
#define ROOM_JESUS_STATUE_HPP

#include "room.hpp"

#include <string>

class Jesus_Statue : public Room {
public:
	Jesus_Statue();
	std::string get_name();
	std::string get_descr();
private:
};

#endif
