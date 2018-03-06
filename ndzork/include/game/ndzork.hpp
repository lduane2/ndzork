#ifndef NDZORK_HPP
#define NDZORK_HPP

#include "game.hpp"
#include "../command.hpp"

#include <string>
#include <unordered_map>
#include <initializer_list>

class NDZork : public Game {
public:
	NDZork();
	~NDZork();
	void loop();
private:
	void handle(Command command);
	void demons();
	bool ended = false;
	int score;
	int max_score = 100;
	int moves;

	Map * build_map();

	void build_actions();
	std::unordered_map<std::string,
										 bool(NDZork::*)(Command)> verb2handler;
	void add_handler(std::string verb,
									 std::initializer_list<std::string> synonyms,
									 bool(NDZork::*handler)(Command command));
	void add_handler(std::string verb,
									 bool(NDZork::*handler)(Command command));
};

#endif
