#include "../parse.hpp"
#include "../parser.hpp"
#include "../map.hpp"
#include "rooms/west_of_house.hpp"

#include <iostream>
#include <string>
int main() {
	Map map;
	map.add_room(new West_Of_House());

	std::string input;
	Parser parser(&map);
	Parse p;
	std::cout << "action   dobj   iobj" << std::endl;
	while (1) {
		std::getline(std::cin, input, '\n');
		p = parser.parse(input);
		std::cout << p.get_action() << " " << p.get_dirobj() << " " << p.get_indobj() << std::endl;
	}

}
