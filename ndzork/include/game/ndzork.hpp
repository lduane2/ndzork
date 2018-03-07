#ifndef NDZORK_HPP
#define NDZORK_HPP

#include "game.hpp"
#include "../command.hpp"

#include <string>
#include <unordered_map>
#include <initializer_list>

//#include "../actors/jank.hpp"

class NDZork : public Game {
public:
	NDZork();
	~NDZork();
	void loop();
	void lose_game();
	void win_game();
private:
	// Jank * jenkins;
	// Room * jenkins_location;

	void handle(Command command);
	void demons();
	bool ended = false;
	int score;
	int max_score = 100;
	int moves;

	//actions in ndzork_actions.cpp
	bool look(Command command);
	bool light(Command command);
	bool quit(Command command);
	bool take(Command command);
	bool put(Command command);
	bool inv(Command command);
	bool go(Command command);
	bool extinguish(Command command);
	bool shake(Command command);
	bool touch(Command command);
	bool climb(Command command);

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
