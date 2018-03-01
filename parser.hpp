#ifndef PARSER_HPP
#define PARSER_HPP

#include "map.hpp"
#include "parse.hpp"

#include <string>
#include <unordered_set>

class Parser {
public:
	Parser(Map *map);
	Parse parse(std::string input);
private:
	std::unordered_set<std::string> actions;
	std::unordered_set<std::string> actors;
	std::unordered_set<std::string> items;
	std::unordered_set<std::string> rooms;
};

#endif
