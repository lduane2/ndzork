#ifndef GAME_HPP
#define GAME_HPP

#include "../object.hpp"
#include "../parse/parser.hpp"
#include "../map.hpp"
#include "../actors/actor.hpp"
#include "../rooms/room.hpp"

#include <string>

class Game {
public:
	Game(Room *spawn_point, Actor *player);
	std::string get_name();
	virtual ~Game();
	virtual void loop() = 0;
	virtual void lose_game() = 0;
	virtual void win_game() = 0;
protected:
	Room *spawn_point;
	Actor *player;
	Map *map;
	Room *player_location;
	Parser parser;

	int move_number = 0;
	virtual Map * build_map() = 0;
	virtual void build_actions() = 0;

	Object * str2obj(std::string s);
};

#endif
