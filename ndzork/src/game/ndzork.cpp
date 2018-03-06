#include "../../include/game/ndzork.hpp"

#include "../../include/parse/parse.hpp"
#include "../../include/game/gameio.hpp"

#include "../../include/actors/luke.hpp"
#include "../../include/rooms/jesus_statue.hpp"

NDZork::NDZork() : Game(new Jesus_Statue(),
												new Luke()),
									 score(0), moves(0) {
	map = build_map();
	parser = Parser(map);
	build_actions();
}

NDZork::~NDZork() {
}

void NDZork::loop() {
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

void NDZork::handle(Command c) {
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

Map * NDZork::build_map() {
	Map *map = new Map();
	spawn_point->add_actor(player);
	map->add_room(spawn_point);
	return map;
}

void NDZork::build_actions() {
	
}

void NDZork::add_handler(std::string verb,
												 std::initializer_list<std::string> synonyms,
												 bool(NDZork::*handler)(Command command))
{
	verb2handler[verb] = handler;
	parser.add_verb(verb);
	for (auto syn : synonyms) {
		verb2handler[syn] = handler;
		parser.add_verb(syn);
	}
}

void NDZork::add_handler(std::string verb,
												 bool(NDZork::*handler)(Command command))
{
	add_handler(verb, {}, handler);
}

void NDZork::demons() {
}
