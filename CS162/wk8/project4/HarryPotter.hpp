/**************************************************************************************
** Program Filename: HarryPotter.hpp
** Author: Hailey Wilder
** Description: HarryPotter.hpp is the specification file for HarryPotter.cpp that 
** creates a HarryPotter creature object.
***************************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include <string>
#include "Creature.hpp"

class HarryPotter : public Creature // inherits from the Creature base class
{
	public:
	int lives; // number of lives that harr potter will have
	HarryPotter(std::string name, int teamN); // construtor // new add
	void Defend(int); // overides the creature defend function
	void Reset(); // reset object to default
};
#endif