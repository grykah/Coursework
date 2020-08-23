/*********************************************************************
** Program: Dice.cpp
** Author: Hailey Wilder
** Description: Dice.cpp is the implemntation file for Dice class.
*********************************************************************/
#include <iostream>
#include <cmath> // needed to do math operations
#include <ctime> // needed so that it works with rand and srand
#include <cstdlib> // needed for srand and rand
#include "Dice.hpp" // imports Dice specification files

Dice::Dice() // default constructor
{
	srand(time(NULL));
	sides = 6;
}

Dice::Dice(int numSides) // overload constructor that takes in the number of sides
{
	srand(time(NULL));
	sides = numSides;
}

int Dice::rollDie() // rolls a fair dice
{
	int rollResult;
	rollResult = (rand() % sides) + 1;
	return rollResult;
}
