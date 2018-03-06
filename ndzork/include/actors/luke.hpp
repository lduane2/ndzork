#ifndef LUKE_HPP
#define LUKE_HPP

#include "actor.hpp"

class Luke : public Actor {
public:
	Luke();
	std::string get_name();
	std::string get_descr();
private:
};

#endif
