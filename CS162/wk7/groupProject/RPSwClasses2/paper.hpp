/******************************************************
** Program: paper.hpp
** Author: Group 20
** Date: 02/21/2017
** Description: paper class subtool
** Input: none
** Output: none
******************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP
#include "tool.hpp"
#include <stdio.h>
class Paper : public Tool {
protected:

public:
	Paper();
	Paper(const Paper &);
	bool fight(Tool);
	Paper(int);
	~Paper();
	void operator=(const Paper &other);
};
#endif