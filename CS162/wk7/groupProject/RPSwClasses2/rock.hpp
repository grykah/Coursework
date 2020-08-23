/******************************************************
** Program: rock.hpp
** Author: Group 20
** Date: 02/21/2017
** Description: rock class subtool
** Input: none
** Output: none
******************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP
#include "tool.hpp"
#include <stdio.h>
class Rock : public Tool {
protected:

public:
	Rock();
	~Rock();
	Rock(const Rock &);
	bool fight(Tool);	
	Rock(int);
	void operator=(const Rock &other);
};

#endif