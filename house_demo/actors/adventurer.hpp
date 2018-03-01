#ifndef ADVENTURER_HPP
#define ADVENTURER_HPP

#include "../../actor.hpp"

class Adventurer : public Actor {
public:
	std::string get_name();
private:
	std::string name = "Adventurer";
};

#endif
