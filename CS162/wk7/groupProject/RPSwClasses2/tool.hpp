/******************************************************
** Program: tool.hpp
** Author: Group 20
** Date: 02/21/2017
** Description: 
** Input: none
** Output: none
******************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP
#include <stdio.h>

class Tool {
protected:
	int strength;
	char type;
public:
	Tool();
	void setStrength(int);
	virtual bool fight(Tool);
	virtual ~Tool();
	void setType(int);
	int getType();
	int getStrength();
};

#endif

