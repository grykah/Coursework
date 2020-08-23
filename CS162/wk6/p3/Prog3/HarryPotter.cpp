/*********************************************************************
** Program Filename: HarryPotter.cpp
** Author: Hailey Wilder
** Date: 2/19/17
** Description: Contains the implementation of the HarryPotter class
**              member functions.
*********************************************************************/

#include "HarryPotter.hpp"


/*********************************************************************
** Function: HarryPotter::HarryPotter()
** Description: Constructs a HarryPotter object, intializing all member
**              variables inherited from the Creature class and
**              specials to false.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all member variables are initialized
*********************************************************************/

HarryPotter::HarryPotter()
{
    // base class member variables
    armor = 0;
    strength = 20;
    name = "HarryPotter";

	// HarryPotter class member variable
    //specials = false;
}


/*********************************************************************
** Function: HarryPotter::attack()
** Description: Determines if special is used.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: specials = true; extra life.
*********************************************************************/

int HarryPotter::attack()
{
    int dice = 2;
    int sides = 6;
    int sum = sum_dice(dice, sides);

    

    return sum;
}


/*********************************************************************
** Function: HarryPotter::defend()
** Description: Determines the amount of the defense for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the result of a die roll is returned
*********************************************************************/

int HarryPotter::defend()
{
    int dice = 2;
    int sides = 6;

    return sum_dice(dice, sides);
}


/*********************************************************************
** Function: HarryPotter::take_damage()
** Description: Special defense.
** Parameters: attack   enemy's attack for this turn
**             defense  this Creature's defense for this turn
** Pre-Conditions: attack and defense are non-negative, strength > 0
** Post-Conditions: strength reduced by damage calculated, amount of
**                  damage done returned
*********************************************************************/

int HarryPotter::take_damage(int attack, int defense)
{
//    // improve defense
//    if (defense == 0)
//        defense == 20;
	return Creature::take_damage(attack, defense);
}


/*********************************************************************
** Function: HarryPotter::revive()
** Description: Restores some or potentially all health and increases
**              this Creature's points.  Additionally, it sets
**              specials to false.
** Parameters: none
** Pre-Conditions: this Creature KOed an opponent
** Post-Conditions: strength is restored to its original value,
**                  specials is false
*********************************************************************/


void HarryPotter::revive()
{
    int heal = rand() % 5 + 2;
    int raw_strength = strength + heal;
    if (raw_strength > 12)
        strength = 12;
    else
        strength = raw_strength;

    points += 10;
}


/*********************************************************************
** Function: HarryPotter::get_special()
** Description: Returns whether this HarryPotter has used special
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true if the opponent's hit with special
*********************************************************************/

bool HarryPotter::get_special()
{
//    return specials;
}
