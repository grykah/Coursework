/**************************************************************************************
** Program Filename: Creature.cpp
** Author: Hailey Wilder
** Description: Creature.cpp is the is the implementation of Creature.hpp file. 
***************************************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h> 
#include "Creature.hpp"
#include "Dice.hpp"

/*********************************************************************
** Function: Attack()
** Description: Brings in the pointer to the oppenent and change to
** the strenghth points. 
** Parameters: Pointer to a creature
*********************************************************************/ 
void Creature::Attack(Creature *opponent)
{
	Dice dice (attackDieSides);
	int attackPoints = 0;

	for (int x = 0;  x < nAttackRolls; x ++)
	{
		attackPoints += dice.rollDie();
	}
	std::cout << "Attacker's total attack points: " << attackPoints << std::endl;
    opponent->Defend(attackPoints);
}

/*********************************************************************
** Function: Defend()
** Description: takes in the attack points from oppnenet to see if
** there is any damage infliction based on defender roll. 
** Parameters: int attackPoints from oppnenet
*********************************************************************/ 
void Creature::Defend(int attackPoints)
{
	Dice dice (defenseDieSides);
	int defensePoints = 0;
	int damage = 0;
	
	for (int x = 0; x < nDefenseRolls; x++)
	{
		defensePoints += dice.rollDie();
	}
	std::cout << "Defender's total defend points: " << defensePoints << std::endl;
	damage = attackPoints - defensePoints - armor;
	// this avoids to show negative numbers
	if (damage < 0)
			damage = 0;
	
	if (damage <= 0)
	{
		strengthPoints = strengthPoints;
	}
	else
	{
		strengthPoints = strengthPoints - damage;
		// this avoids to show negative numbers
		if (strengthPoints < 0)
			strengthPoints = 0;
	}
	
	std::cout << "Defender's Armor: " << armor << std::endl;
	std::cout << "Damage inflicted: " << damage << std::endl;
	std::cout << "Defender's Strength Points: " << strengthPoints << std::endl;
	
	if(strengthPoints <= 0)
    {
		std::cout << "Defender is Dead!" << std::endl;
        alive = false;
    }
 }
 
/*********************************************************************
** Function: Reset()
** Description: Restores creatures settings to default. This is just
** an interface. 
** Parameters: None
*********************************************************************/ 
void Creature::Reset(){}

/*********************************************************************
** Function: getName()
** Description: Returns the creatures name. 
** Parameters: None
*********************************************************************/ 
std::string Creature::getName()
{
	return creatureName;
}

/*********************************************************************
** Function: getStrengthPoints()
** Description: Returns the creatures strength points available. 
** Parameters: None
*********************************************************************/ 
int Creature::getStrengthPoints()
{
    return strengthPoints;
}

/*********************************************************************
** Function: heal()
** Description: Increases the winners strehgth points when called.  
** Parameters: None
*********************************************************************/ 
void Creature::heal()
{
	strengthPoints = strengthPoints * (1 + (rand() % 6 * .1));
}

/*********************************************************************
** Function: getTeam()
** Description: Returns creatures rteam number.  
** Parameters: None
*********************************************************************/ 
int Creature::getTeam()
{
	return team;

}

/*********************************************************************
** Function: isAlive()
** Description: Tells if the creature is still alive or dead. 
** Parameters: None
*********************************************************************/ 
bool Creature::isAlive()
{
    return alive;
}
