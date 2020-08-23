/***************************************************************************
** Program: Dice.hpp
** Author: Hailey Wilder
** Description: Dice.hpp is the spcification file header for the dice class.
****************************************************************************/
#ifndef DICE_HPP
#define DICE_HPP

class Dice
{
protected: // allows subclassed to access these member variables or functions
	int sides;

public:
	Dice(); // default constructor
	Dice(int); // overload constructor
	int rollDie(); // rolls a fair dice when called between 0 and N
};

#endif 