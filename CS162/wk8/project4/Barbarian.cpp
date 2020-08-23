/**************************************************************************************
** Program Filename: Barbarian.cpp
** Author: Hailey Wilder
** Description: Barbarian.cpp is the is the implementation of Barbarian.hpp file. 
***************************************************************************************/
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Dice.hpp"
#include "Barbarian.hpp"

/*********************************************************************
** Function: Barbarian()
** Description: Constructor that assigns custom name and team number.  
** Parameters: String name, int teamN
*********************************************************************/ 
Barbarian::Barbarian(std::string name, int teamN)
{
	creatureName = name; // to help distinguish the characters // add new
	attackDieSides = 6; // the number sides in a attack dice
	nAttackRolls = 2; // the number of times the attack dice will be rolled
	defenseDieSides = 6; // the number of sides in a defense dice
	nDefenseRolls = 2; // the number of time the defense dice will be rolled
	armor = 0; // constant value
	strengthPoints = 12; // life meter
	team = teamN; // add new
	alive = true;
}

/*********************************************************************
** Function: Reset()
** Description: Restores creatrues settings to default   
** Parameters: none
*********************************************************************/ 
void Barbarian::Reset()
{
	creatureName = "Barbarian"; // to help distinguish the characters
	attackDieSides = 6; // the number sides in a attack dice
	nAttackRolls = 2; // the number of times the attack dice will be rolled
	defenseDieSides = 6; // the number of sides in a defense dice
	nDefenseRolls = 2; // the number of time the defense dice will be rolled
	armor = 0; // constant value
	strengthPoints = 12; // life meter
	alive = true;
}


