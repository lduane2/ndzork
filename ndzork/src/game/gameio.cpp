#include "../../include/game/gameio.hpp"

void print()
{}


std::string get_input_line() {
	std::string input;

    nocbreak();
    echo();
    int ch = getch();
    while ( ch != '\n')
    {
        input.push_back(ch);
        ch = getch();
    }
	//std::getline(std::cin, input, '\n');



	return input;
}
