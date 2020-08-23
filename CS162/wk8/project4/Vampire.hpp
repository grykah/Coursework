/**************************************************************************************
** Program Filename: Vampire.hpp
** Author: Hailey Wilder
** Description: Vampire.hpp is the specification file for Vampire.cpp that creates
** a Vampire creature object.
***************************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include <string>
#include "Creature.hpp"

class Vampire : public Creature // inherits from the Creature base class
{
	public:
	Vampire(std::string name, int teamN); // Constructor
	void Defend(int); // overrides Creature's Defend functions since it is diffrent
	void Reset(); // reset objects to defaults
}; 
#endif