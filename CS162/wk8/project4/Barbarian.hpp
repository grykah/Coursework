/**************************************************************************************
** Program Filename: Barbarian.hpp
** Author: Hailey Wilder
** Description: Barbarian.hpp is the specification file for Barbarian.cpp that creates
** a Barbarian creature object.
***************************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <string>
#include "Creature.hpp"

class Barbarian : public Creature // inherits from creature
{
	public:
	Barbarian(std::string name, int teamN); // constuctor
	void Reset(); // resets object to default
};

#endif
