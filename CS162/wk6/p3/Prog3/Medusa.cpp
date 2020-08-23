/*********************************************************************
** Program Filename: Medusa.cpp
** Author: Jason Goldfine-Middleton
** Date: 11/09/15
** Description: Contains the implementation of the Medusa class
**              member functions.
*********************************************************************/

#include "Medusa.hpp"


/*********************************************************************
** Function: Medusa::Medusa()
** Description: Constructs a Medusa object, intializing all member
**              variables inherited from the Creature class.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all member variables are initialized
*********************************************************************/

Medusa::Medusa()
{
    armor = 3;
    strength = 8;
    name = "Medusa";
	
	// Medusa class member variable
    //specials = false;
}


/*********************************************************************
** Function: Medusa::attack()
** Description: Determines the amount of the attack for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sum of dice rolls is returned
*********************************************************************/

int Medusa::attack()
{
    int dice = 2;
    int sides = 6;
    int sum = sum_dice(dice, sides);

	// the Medusa special
    //if (sum == 12)
    //    specials = true;
	return sum;
}


/*********************************************************************
** Function: Medusa::defend()
** Description: Determines the amount of the defense for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the result of a die roll is returned
*********************************************************************/

int Medusa::defend()
{
    int dice = 1;
    int sides = 6;

    return sum_dice(dice, sides);
}

/*********************************************************************
** Function: Medusa::take_damage()
** Description: Calculates the damage taken in the current turn,
**              reduces strength accordingly, then returns the damage.
**              If the enemy's Achilles tendon was cut, his attack is
**              cut by 50%.
** Parameters: attack   enemy's attack for this turn
**             defense  this Creature's defense for this turn
** Pre-Conditions: attack and defense are non-negative, strength > 0
** Post-Conditions: strength reduced by damage calculated, amount of
**                  damage done returned
*********************************************************************/
/*
int Medusa::take_damage(int attack, int defense)
{
    // kill enemy with special
    if (specials)
        attack *= 99999;

    return Creature::take_damage(attack, defense);
}
*/
/*********************************************************************
** Function: Medusa::revive()
** Description: Restores some or potentially all health and increases
**              this Creature's points.
** Parameters: none
** Pre-Conditions: this Creature KOed an opponent
** Post-Conditions: strength is restored by a random amount
*********************************************************************/

void Medusa::revive()
{
    int heal = rand() % 7 + 6;
    int raw_strength = strength + heal;
    if (raw_strength > 8)
        strength = 8;
    else
        strength = raw_strength;

    points += 2;    
}

/*********************************************************************
** Function: Medusa::get_special()
** Description: Returns whether this Medusa has used special.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true if the opponent's hit with special
*********************************************************************/
/*
bool Medusa::get_special()
{
    return specials;
}
*/