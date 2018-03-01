#ifndef PARSE_HPP
#define PARSE_HPP

#include <string>

class Parse {
public:
	Parse();
	Parse(std::string action, std::string dirobj, std::string indobj);
	std::string get_action();
	std::string get_dirobj();
	std::string get_indobj();
private:
	std::string action;
	std::string dirobj;
	std::string indobj;
};

#endif
