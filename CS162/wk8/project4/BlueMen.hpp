/**************************************************************************************
** Program Filename: BlueMen.hpp
** Author: Hailey Wilder
** Description: BlueMen.hpp is the specification file for BlueMen.cpp that creates
** a BlueMen creature object.
***************************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include <string>
#include "Creature.hpp"

class BlueMen : public Creature // inherits from the Creasture base class
{	
	public:
	BlueMen(std::string name, int teamN); // constructor
	void Defend(int); // overrides Creature's Defend functions since it is diffrent stratgegy
	void Reset(); // resets objects to defaults
};
#endif
