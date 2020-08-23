/******************************************************
** Program: scissors.hpp
** Author: Group 20
** Date: 02/21/2017
** Description: scissors class subtool
** Input: none
** Output: none
******************************************************/

#ifndef SCISSORS_HPP
#define SCISSORS_HPP
#include "tool.hpp"
#include <stdio.h>

class Scissors : public Tool {
protected:

public:
	Scissors();
	~Scissors();
	bool fight(Tool);
	Scissors(int);
	void operator=(const Scissors &other);
	Scissors(const Scissors &);
};

#endif