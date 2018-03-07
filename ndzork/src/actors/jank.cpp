#include "../../include/actors/jank.hpp"
#include "../../include/game/gameio.hpp"

Jank::Jank() {
}

std::string Jank::get_name() {
	return name;
}

std::string Jank::get_descr() {
	
    return "a shifty figure, but on closer inspection it appears to be father jenkins!";
}

std::string Jank::demon() {


    return "jenkins shifts his weight nervously as if he needs to be somewhere\n";

    //return true;
}


bool Jank::handle(Command c) {
    std::string verb = c.get_verb();
    if (verb == "look"){
        if (c.get_dobj()->get_name() == this->get_name()) {
            print(get_descr(),"\n");
            return true;
        }
    }

    if (verb == "shake"){
    
    print("A handshake has never left you this dissapointed before.\n");    
    return true;
    }
	return Actor::handle(c);
}
