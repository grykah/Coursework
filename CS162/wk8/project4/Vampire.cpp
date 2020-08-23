/**************************************************************************************
** Program Filename: Vampire.cpp
** Author: Hailey Wilder
** Description: Vampire.cpp is the is the implementation of Vampire.hpp file. 
***************************************************************************************/
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Dice.hpp"
#include "Vampire.hpp"

/*********************************************************************
** Function: Vampire()
** Description: Constructor that sets the name and team number. 
** Parameters: None
*********************************************************************/
Vampire::Vampire(std::string name, int teamN) // new add
{
	creatureName = name; // to help distinguish the characters // new add
	attackDieSides = 12; // the number sides in a attack dice
	nAttackRolls = 1; // the number of times the attack dice will be rolled
	defenseDieSides = 6; // the number of sides in a defense dice
	nDefenseRolls = 1; // the number of time the defense dice will be rolled
	armor = 1; // constant value
	strengthPoints = 18; // life meter
	team = teamN; // new add
	alive = true; // sets creature to alice
}

/*********************************************************************
** Function: Defend()
** Description: Implement Vampire special defend starategey. 
** Parameters: Opponent attack points
*********************************************************************/
void Vampire::Defend(int attackPoints) // overrides Creature's Defend functions since it is diffrent
{
	Dice charm(2);
	int restult = charm.rollDie();
	if (restult != 12)
	{
		Dice dice (defenseDieSides);
		int defensePoints = 0;
	
		for (int x = 0; x < nDefenseRolls; x++)
		{
			defensePoints += dice.rollDie();
		}
		std::cout << "Defender's total defend points: " << defensePoints << std::endl;
		std::cout << "Defender's Armor: " << armor << std::endl;
		int damage = 0;
		damage = attackPoints - defensePoints - armor;
		if (damage < 0)
			damage = 0;
		
		if (damage <= 0)
		{
			strengthPoints = strengthPoints;
		}
		else
		{
			strengthPoints = strengthPoints - damage;
		}
	
		std::cout << "Damage inflicted: " << damage << std::endl;

		std::cout << "Defender's Strength Points: " << strengthPoints << std::endl;
		
		if(strengthPoints <= 0)
		{
			std::cout << "Defender is Dead!" << std::endl;
			alive = false;
		}
	}
	
	else
	{
		strengthPoints = strengthPoints;
		std::cout << "Vampire charmed the attacker!!! (no points reduced)" << std::endl;
	}
		
}

/*********************************************************************
** Function: Reset()
** Description: Resets creatures defaults
** Parameters: None
*********************************************************************/
void Vampire::Reset()
{
	creatureName = "Vampire"; // to help distinguish the characters
	attackDieSides = 12; // the number sides in a attack dice
	nAttackRolls = 1; // the number of times the attack dice will be rolled
	defenseDieSides = 6; // the number of sides in a defense dice
	nDefenseRolls = 1; // the number of time the defense dice will be rolled
	armor = 1; // constant value
	strengthPoints = 18; // life meter
	alive = true; // set creature to a live
}

