#ifndef GAMEIO_HPP
#define GAMEIO_HPP

#include <string>
#include <stdio.h>
#include <iostream>

void print();

template<typename T, typename... Args>
void print(T first, Args... args) {
	std::string s(first);
	printf("%s", s.c_str());
	print(args...);
}

std::string get_input_line();

#endif
