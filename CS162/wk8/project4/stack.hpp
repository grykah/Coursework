/*********************************************************************
** File Name: stack.hpp
** Author: Hailey Wilder
** Description: stack.hpp is the specification file for stack.cpp 
*********************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include "structure.hpp"
#include "Creature.hpp"

class Stack : public Structure // Inherits from the Structure base class
{
	public:
		Stack() { head = NULL; } // construcor
		~Stack(); // destructor
		void add(Creature *c);
};

#endif
