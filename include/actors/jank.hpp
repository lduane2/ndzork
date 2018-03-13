#ifndef JANK_HPP
#define JANK_HPP

#include "../command.hpp"
#include "actor.hpp"

class Jank : public Actor {
public:
	Jank();
	std::string get_name();
	std::string get_descr();
	bool handle(Command c);
    std::string demon();
private:
	std::string name = "Jenkins";
};

#endif
