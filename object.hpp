#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "parse.hpp"

#include <string>
#include <unordered_set>

class Object {
public:
	virtual ~Object();
	virtual std::string get_name() = 0;
	virtual std::string perform_action(Parse parse);
	std::unordered_set<std::string> defined_actions;
};

#endif
