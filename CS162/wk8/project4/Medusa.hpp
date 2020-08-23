/**************************************************************************************
** Program Filename: Medusa.hpp
** Author: Hailey Wilder
** Description: Medusa.hpp is the specification file for Medusa.cpp that creates
** a Medusa creature object.
***************************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include <string>
#include "Creature.hpp"

class Medusa : public Creature // inherits from the base Creature class
{
	public:
		Medusa(std::string name, int teamN); // constructor
		void Attack(Creature *opponent); // overrides Creatures attack function
		void Reset(); // reset object to defualts
};
#endif
