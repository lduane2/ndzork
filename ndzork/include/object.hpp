#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "command.hpp"

#include <string>

class Object {
public:
	virtual ~Object();
	virtual std::string get_name() = 0;
	virtual std::string get_full_name();
	virtual std::string get_descr() = 0;
	virtual bool handle(Command command);
};

#endif
