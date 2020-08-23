/**************************************************************************************
** Program Filename: HarryPotter.cpp
** Author: Hailey Wilder
** Description: HarryPotter.cpp is the is the implementation of HarryPotter.hpp file. 
***************************************************************************************/
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Dice.hpp"
#include "HarryPotter.hpp"

/*********************************************************************
** Function: HarryPotter()
** Description: Constructor that sets the name and team number.   
** Parameters: string name, int team number
*********************************************************************/ 
HarryPotter::HarryPotter(std::string name, int teamN) 
{
	creatureName = name; // to help distinguish the characters // new add
	attackDieSides = 6; // the number sides in a attack dice
	nAttackRolls = 2; // the number of times the attack dice will be rolled
	defenseDieSides = 6; // the number of sides in a defense dice
	nDefenseRolls = 2; // the number of time the defense dice will be rolled
	armor = 0; // constant value
	strengthPoints = 10; // life meter
	lives = 2; // harry potter will have two lives how lucky is he
	team = teamN; // new add
	alive = true; // set the creature to alive
};

/*********************************************************************
** Function: Defend()
** Description: Determines Harry Potter special defend startegy.   
** Parameters: int attackPoints from opponent (attacker)
*********************************************************************/ 
void HarryPotter::Defend(int attackPoints)
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
	
	if (strengthPoints <= 0 && lives > 1) // when harry potter dies it gets a new life 
	{
		strengthPoints = 20; 
		lives = 1;
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
** Description: Sets the creatures settings to degfault 
** Parameters: None
*********************************************************************/
void HarryPotter::Reset()
{
	creatureName = "Harry Potter"; // to help distinguish the characters
	attackDieSides = 6; // the number sides in a attack dice
	nAttackRolls = 2; // the number of times the attack dice will be rolled
	defenseDieSides = 6; // the number of sides in a defense dice
	nDefenseRolls = 2; // the number of time the defense dice will be rolled
	armor = 0; // constant value
	strengthPoints = 10; // life meter
	lives = 2; // harry potter will have two lives how lucky is he
	alive = true;
};


