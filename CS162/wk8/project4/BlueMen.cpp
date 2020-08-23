/**************************************************************************************
** Program Filename: BlueMen.cpp
** Author: Hailey Wilder
** Description: BlueMen.cpp is the is the implementation of BlueMen.hpp file. 
***************************************************************************************/
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Dice.hpp"
#include "BlueMen.hpp"

/*********************************************************************
** Function: BlueMen()
** Description: Constructor that assigns custom name and team number.  
** Parameters: String name, int teamN
*********************************************************************/ 
BlueMen::BlueMen(std::string name, int teamN)
{
	creatureName = name; // to help distinguish the characters
	attackDieSides = 10; // the number sides in a attack dice
	nAttackRolls = 2; // the number of times the attack dice will be rolled
	defenseDieSides = 6; // the number of sides in a defense dice
	nDefenseRolls = 3; // the number of time the defense dice will be rolled
	armor = 3; // constant value
	strengthPoints = 12; // life meter
	team = teamN; // Team number
	alive = true; // set the creature to alive when created
};

/*********************************************************************
** Function: Defend()
** Description: Determines Blue Men defend startegy.   
** Parameters: int attackPoints from opponent (attacker)
*********************************************************************/ 
void BlueMen::Defend(int attackPoints)
{
	Dice dice (defenseDieSides);
	int defensePoints = 0;
	
	for (int x = 0; x < nDefenseRolls; x++)
	{
		defensePoints += dice.rollDie();
	}
	std::cout << "Defender points: " << defensePoints << std::endl;
	int damage = 0;
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
		
		if (strengthPoints <= 8 && strengthPoints > 4) // strength points between 4 and 8 points subtract one defense roll
		{
			nDefenseRolls = 2;
			std::cout << "Subraacted one from the defense roll: " << nDefenseRolls << std::endl;
		}
		if (strengthPoints <= 4 && strengthPoints > 0) // strength points between 0 and 4 points subtract one defense roll
		{
			nDefenseRolls = 1;
			std::cout << "Subraacted one from the defense roll: " << nDefenseRolls << std::endl;
		}
		std::cout << "defense rolls:  " << nDefenseRolls << std::endl;
	}
	
	std::cout << "Damage inflicted: " << damage << std::endl;

	std::cout << "Defender's Strength Points: " << strengthPoints << std::endl;
	
	if(strengthPoints <= 0)
    {
		std::cout << "Defender is dead!" << std::endl;
        alive = false;
    }
};

/*********************************************************************
** Function: Reset()
** Description: Restores creatrues settings to default   
** Parameters: none
*********************************************************************/ 
void BlueMen::Reset()
{
	creatureName = "Blue Men"; // to help distinguish the characters
	attackDieSides = 10; // the number sides in a attack dice
	nAttackRolls = 2; // the number of times the attack dice will be rolled
	defenseDieSides = 6; // the number of sides in a defense dice
	nDefenseRolls = 3; // the number of time the defense dice will be rolled
	armor = 3; // constant value
	strengthPoints = 12; // life meter
	alive = true;
};