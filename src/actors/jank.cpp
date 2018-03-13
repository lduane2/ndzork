#include "../../include/actors/jank.hpp"
#include "../../include/game/gameio.hpp"

Jank::Jank() {
}

std::string Jank::get_name() {
	return name;
}

std::string Jank::get_descr() {
	
    return "A shifty figure, but on closer inspection it appears to be father Jenkins!";
}

std::string Jank::demon() {


    return "Jenkins shifts his weight nervously as if he needs to be somewhere.\n";

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
    
    if (verb == "give") {
        if (c.get_dobj()->get_name() == this->get_name()) {
            print("Jenkins seems excited about the idea of recieving a gift!\n");
            return true;
        }
    }

    if (verb == "talk") {
        if (c.get_dobj() == this) {

            if (c.get_iobj() != nullptr ) {
                if (c.get_iobj()->get_name() == "candle") {
                print("Jenkins replies, \"Oh, I have been looking for that candle!  can you please return it to the Grotto?\n");
                return true;
                }
                if (c.get_iobj()->get_name() == "matches") {
                print("Jenkins replies, \"I think I saw some matches near where everyone smokes at main circle.  People should really stop littering.\n");
                return true;
                }
               
            }
            print("Jenkins mumbles something to himself about the endowment.\n");
            return true;
       }     
    }

	return Actor::handle(c);
}
