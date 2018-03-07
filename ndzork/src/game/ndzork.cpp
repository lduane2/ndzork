#include "../../include/game/ndzork.hpp"

#include "../../include/parse/parse.hpp"
#include "../../include/game/gameio.hpp"

#include "../../include/actors/luke.hpp"
#include "../../include/rooms/jesus_statue.hpp"
#include "../../include/rooms/main_circle.hpp"
#include "../../include/actors/jank.hpp"


#include <random>

NDZork::NDZork() : Game(new Jesus_Statue(),
												new Luke()),
									 score(0), moves(0) {
	map = build_map();
	parser = Parser(map);
	build_actions();
    move_number = 0;
}

NDZork::~NDZork() {
}

void NDZork::loop() {
	Parse p;
	while(!ended) {
		print(">");
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
	Object *dobj = c.get_dobj();
	Object *iobj = c.get_iobj();
	error("verb  = ", c.get_verb(), "\n");
	error("actor = ", c.get_actor()->get_name(), "\n");
	error("room  = ", c.get_room()->get_name(), "\n");
	error("dobj  = ", (dobj) ? dobj->get_name() : "nullptr", "\n");
	error("iobj  = ", (iobj) ? iobj->get_name() : "nullptr", "\n");

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

	Room * jesus_statue = spawn_point;

	// Formula for adding a new room to the map
	Room * mainCircle = new Main_Circle();
	map->add_room(mainCircle);
    
    jenkins = new Jank();    
    jenkins_location = mainCircle;
    mainCircle->add_actor(jenkins);
	jesus_statue->add_adj_room("south", mainCircle);
	mainCircle->add_adj_room("north", jesus_statue);

	return map;
}

void NDZork::build_actions() {
	add_handler("look", {"describe", "examine"}, &NDZork::look);
	add_handler("quit", {"q", "goodbye"}, &NDZork::quit);
	add_handler("light", &NDZork::light);
	add_handler("take", &NDZork::take);
	add_handler("put", {"drop"},  &NDZork::put);
	add_handler("inv", {"items", "inventory"}, &NDZork::inv);
	add_handler("extinguish", {"extenguish", "putout"}, &NDZork::extinguish);
	add_handler("go", { "travel", "walk", "run", "dance", "slither", "shimmy", "move", "logroll", "crawl", "moonwalk", "apparate", "fly", "materialize"}, &NDZork::go);
    add_handler("shake", &NDZork::shake);
}

void NDZork::add_handler(std::string verb,
												 std::initializer_list<std::string> synonyms,
												 bool(NDZork::*handler)(Command command))
{
	verb2handler[verb] = handler;
	parser.add_verb(verb, synonyms);
	for (auto syn : synonyms) {
		verb2handler[syn] = handler;
	}
}

void NDZork::add_handler(std::string verb,
												 bool(NDZork::*handler)(Command command))
{
	add_handler(verb, {}, handler);
}

void NDZork::demons() {
    /// jenkins
    move_number++;
    //jenkins->demon();
    if ((move_number % 4) ==1) {
        auto dir_map = jenkins_location->get_dir_table();
        auto room = dir_map.begin();
        std::advance( room, (rand() %dir_map.size()) );
        jenkins_location->remove_actor(jenkins);
        if (jenkins_location ==  player_location) {
            print("jenkins quickly ducks out, leaving you behind\n");
        }
        jenkins_location=room->second;
        jenkins_location->add_actor(jenkins);
        if (jenkins_location ==  player_location) {
            print("Father Jenkins, head of the university, approaches you from almost out of no where\n");
        }
    }
    
    if (jenkins_location == player_location)
        {
            print("jenkins shifts his wait nervously as if he has somewhere to be but doesnt quite know where.\n");
        }

}
