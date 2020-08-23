/*********************************************************************
** Program Filename: Vampire.cpp
** Author: Hailey WIlder
** Date: 2/19/17
** Description: Contains the implementation of the Vampire class
**              member functions.
*********************************************************************/

#include "Vampire.hpp"


/*********************************************************************
** Function: Vampire::Vampire()
** Description: Constructs a Vampire object, intializing all member
**              variables inherited from the Creature class.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all member variables are initialized
*********************************************************************/

Vampire::Vampire()
{
    armor = 1;
    strength = 18;
    name = "Vampire";
}


/*********************************************************************
** Function: Vampire::attack()
** Description: Determines the amount of the attack for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sum of dice rolls is returned
*********************************************************************/

int Vampire::attack()
{
    int dice = 1;
    int sides = 12;
    int sum = sum_dice(dice, sides);

    return sum;
}


/*********************************************************************
** Function: Vampire::defend()
** Description: Determines the amount of the defense for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the result of a die roll is returned
*********************************************************************/

int Vampire::defend()
{
    int dice = 1;
    int sides = 6;

    return sum_dice(dice, sides);
}


/*********************************************************************
** Function: Vampire::take_damage()
** Description: Calculates the damage taken in the current turn,
**              reduces strength accordingly, then returns the damage.
**              50% of the time no damage is done.
** Parameters: attack   enemy's attack for this turn
**             defense  this Creature's defense for this turn
** Pre-Conditions: attack and defense are non-negative, strength > 0
** Post-Conditions: strength reduced by damage calculated, amount of
**                  damage done returned
*********************************************************************/

int Vampire::take_damage(int attack, int defense)
{
    // if Vampire avoids the attack, apply no damage and return 0
    if (rand() % 2)
        return 0;

    return Creature::take_damage(attack, defense);
}


/*********************************************************************
** Function: Vampire::revive()
** Description: Restores some or potentially all health and increases
**              this Creature's points.
** Parameters: none
** Pre-Conditions: this Creature KOed an opponent
** Post-Conditions: strength is restored by a random amount
*********************************************************************/

void Vampire::revive()
{
    int heal = rand() % 7 + 2;
    int raw_strength = strength + heal;
    if (raw_strength > 18)
        strength = 18;
    else
        strength = raw_strength;

    points += 2;
}

