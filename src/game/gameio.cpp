#include "../../include/game/gameio.hpp"

#include <algorithm>

#include <readline/readline.h>
#include <readline/history.h>

void _print(std::ostream& /*ostream*/)
{}


std::string get_input_line() {
	std::string input(readline("\n>"));
	if (!input.empty())
		add_history(input.c_str());

	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	return input;
}
