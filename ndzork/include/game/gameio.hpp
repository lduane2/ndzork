#ifndef GAMEIO_HPP
#define GAMEIO_HPP

#include <string>
#include <stdio.h>
#include <iostream>

#include <ncurses.h>
void print();

template<typename T, typename... Args>
void print(T first, Args... args) {
	std::string s(first);
	printw("%s", s.c_str());
    refresh();
	print(args...);
}

std::string get_input_line();

#endif
