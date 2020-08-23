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

/*********************************************************************
** Function: Dice()
** Description: Default constructor that sets it to 6 sides   
** Parameters: None
*********************************************************************/
Dice::Dice() // default constructor
{
	sides = 6;
}

/*********************************************************************
** Function: Dice()
** Description: Overloaded construtor that sets the num of sides
** based on input.    
** Parameters: int numSides
*********************************************************************/
Dice::Dice(int numSides) // overload constructor that takes in the number of sides
{
	sides = numSides;
}

/*********************************************************************
** Function: rollDie()
** Description: Returns a random number back.
** Parameters: None
*********************************************************************/
int Dice::rollDie() // rolls a fair dice
{
	int rollResult;
	rollResult = rand() % sides + 1;
	return rollResult;
}