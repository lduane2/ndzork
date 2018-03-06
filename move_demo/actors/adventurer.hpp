#ifndef ADVENTURER_HPP
#define ADVENTURER_HPP

#include "../../actor.hpp"

class Adventurer : public Actor {
public:
	Adventurer();
	std::string get_name();
	std::string get_descr();
private:
	std::string name = "Adventurer";
};

#endif
