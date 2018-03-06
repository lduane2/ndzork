#include "../../include/game/gameio.hpp"

std::string get_input_line() {
	std::string input;
	std::getline(std::cin, input, '\n');
	return input;
}
