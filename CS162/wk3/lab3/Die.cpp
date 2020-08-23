/*********************************************************************
 ** Program Filename: Die.cpp
 ** Author: Hailey Wilder
 ** Date: 1/29/17
 ** Description: Die class implementation file.  
 ** Input: n/a
 ** Output: n/a
 *********************************************************************/

#include "Die.h"
#include <cstdlib>  // for rand()
#include <iostream> // for std::cout


/*********************************************************************
 ** Function: Die()
 ** Description: Constructs a balanced Die. All sides positive for die
 ** 			 created and number of sides determined
 ** Parameters: sides - number of sides
 *********************************************************************/

Die::Die(int sides)
{
    num_sides = sides;
}


/*********************************************************************
 ** Function: ~Die()
 ** Description: Destroys Die. 
 ** Parameters: none
 *********************************************************************/

Die::~Die()
{
    // do nothing
}

/*********************************************************************
 ** Function: die_roll()
 ** Description: Rolls the Die, returning a value between 1 and the
 **              number of sides.  strand() must be run first then an 
 ** 			 int between 1 and number of sides is returned. 
 ** Parameters: none
 *********************************************************************/

int Die::die_roll()
{
    int roll = rand() % num_sides + 1;
    std::cout << "the die roll was " << roll << '\n';
    return roll;
}