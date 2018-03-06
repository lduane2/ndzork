#ifndef GAMEIO_HPP
#define GAMEIO_HPP

#include <string>
#include <iostream>

template<typename T>
void _print(std::ostream& ostream, T t) {
	ostream << t;
}

template<typename T, typename... Args>
void _print(std::ostream& ostream, T first, Args... args) {
	ostream << first;
	_print(ostream, args...);
}

template<typename... Args>
void print(Args... args) {
	_print(std::cout, args...);
}

template<typename... Args>
void error(Args... args) {
	_print(std::cerr, args...);
}

std::string get_input_line();

#endif
