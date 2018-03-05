#ifndef ZORK_HPP
#define ZORK_HPP

#include "../game.hpp"
#include "../command.hpp"

#include <string>
#include <unordered_map>
#include <initializer_list>

class Zork : public Game {
public:
	Zork();
	~Zork();
	void loop();
private:
	void handle(Command command);
	void demons();
	bool ended = false;
	int score;
	int max_score = 350;
	int moves;
	std::string get_rank();

	Map * build_map();

	void build_actions();
	std::unordered_map<std::string,
										 bool(Zork::*)(Command)> verb2handler;
	void add_handler(std::string verb,
									 std::initializer_list<std::string> synonyms,
									 bool(Zork::*handler)(Command command));
	void add_handler(std::string verb,
									 bool(Zork::*handler)(Command command));

	bool look(Command command);
	bool close(Command command);
	bool open(Command command);
	bool quit(Command command);
};

#endif
