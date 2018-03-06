#include "zork.hpp"

#include "rooms/west_of_house.hpp"
#include "actors/adventurer.hpp"
#include "../parse.hpp"
#include "../gameio.hpp"

// Must build map here!
Zork::Zork() : Game(new West_Of_House(),
										new Adventurer()),
							 score(0), moves(0) {
	map = build_map();
	parser = Parser(map);
	build_actions();
}

Zork::~Zork() {
}

void Zork::loop() {
	Parse p;
	while(!ended) {
		p = parser.parse(get_input_line());

		Object *dobj = str2obj(p.get_dobj());
		Object *iobj = str2obj(p.get_iobj());
		Command command(p.get_verb(), player_location,
										player, dobj, iobj, this);

		handle(command);
	}
}

void Zork::handle(Command c) {
	// Logging. Delete before turning in
	// Object *dobj = c.get_dobj();
	// Object *iobj = c.get_iobj();
	// error("verb  = ", c.get_verb(), "\n");
	// error("actor = ", c.get_actor()->get_name(), "\n");
	// error("room  = ", c.get_room()->get_name(), "\n");
	// error("dobj  = ", (dobj) ? dobj->get_name() : "nullptr", "\n");
	// error("iobj  = ", (iobj) ? iobj->get_name() : "nullptr", "\n");

	// Actor
	if (c.get_actor()->handle(c)) {
		demons();
		return;
	}

	// Indirect Object
	if (c.get_iobj() && c.get_iobj()->handle(c)) {
		c.get_room()->handle(c);
		demons();
		return;
	}

	// Direct Object
	if (c.get_dobj() && c.get_dobj()->handle(c)) {
		c.get_room()->handle(c);
		demons();
		return;
	}

	// Verb
	auto verb_lookup = verb2handler.find(c.get_verb());
	if (verb_lookup != verb2handler.end()) {
		auto handler = (*verb_lookup).second;
		if ((this->*handler)(c)) {
			c.get_room()->handle(c);
			demons();
			return;
		}
	}

	// Room
	if (c.get_room()->handle(c)) {
		demons();
		return;
	}

	// Background Tasks
	demons();

	// Nobody handled it completely
	print("I don't know how to do that\n");
}

Map * Zork::build_map() {
	Map *map = new Map();
	spawn_point->add_actor(player);
	map->add_room(spawn_point);
	return map;
}

void Zork::build_actions() {
	add_handler("look", {"describe"}, &Zork::look);
	add_handler("close", &Zork::close);
	add_handler("open", &Zork::open);
	add_handler("quit", {"q", "goodbye"}, &Zork::quit);
    add_handler("yell", {"scream"}, &Zork::yell);
    add_handler("light", &Zork::light);
}

void Zork::add_handler(std::string verb,
											 std::initializer_list<std::string> synonyms,
											 bool(Zork::*handler)(Command command))
{
	verb2handler[verb] = handler;
	parser.add_verb(verb);
	for (auto syn : synonyms) {
		verb2handler[syn] = handler;
		parser.add_verb(syn);
	}
}

void Zork::add_handler(std::string verb,
											bool(Zork::*handler)(Command command))
{
	add_handler(verb, {}, handler);
}

void Zork::demons() {
}

std::string Zork::get_rank() {
	double pct = (double)score / (double)max_score;
	if      (pct > 1)           return "Cheater";
	else if (pct >= 0.99999999) return "Dungeon Master";
	else if (pct >= 0.95000000) return "Wizard";
	else if (pct >= 0.89999999) return "Master";
	else if (pct >= 0.79999999) return "Winner";
	else if (pct >= 0.60000000) return "Hacker";
	else if (pct >= 0.39999999) return "Adventurer";
	else if (pct >= 0.19999999) return "Junior Adventurer";
	else if (pct >= 0.09999999) return "Novice Adventurer";
	else if (pct >= 0.04999999) return "Amateur Adventurer";
	else if (pct >= 0.0)        return "Beginner";

	return "Incompetent";
}
