/**************************************************************************************
** Program Filename: Creature.hpp
** Author: Hailey Wilder
** Description: Creature.hpp is the specification file for Creature.cpp that creates
** an interface for the diffrent types of creatures.
***************************************************************************************/
#ifndef CREATURES_HPP
#define CREATURES_HPP
#include <string>
#include <stdlib.h> 
#include "Dice.hpp" // bring in lab 3 for random numbers

class Creature
{
	protected: // allows derived class to access these elements
		std::string creatureName; // to help distinguish the characters
		int attackDieSides; // the number sides in a attack dice
		int nAttackRolls; // the number of times the attack dice will be rolled
		int defenseDieSides; // the number of sides in a defense dice
		int nDefenseRolls; // the number of time the defense dice will be rolled
		int armor; // constant value
		int strengthPoints; // life meter
		int team; // stores the players team number
	public:
		bool alive; // true = alive, false = dead
		virtual void Attack(Creature*); // this will be used by the attacker and it will need the address of the defender. Will be overriden by Medusa.
		virtual void Defend(int attackRoll); // will take the value returned by the Attack function. will be overiden by Blue Men, Vampire and Harry Potter
		virtual void Reset(); // restart the creatures when the game is complete
		std::string getName(); // returns the name of the creature 
		int getStrengthPoints(); // returns the strength points of the creature
		void heal(); // gives a little extra health after winning 
		int getTeam(); // returns the creatures team number
		bool isAlive(); // returns true or false if the creature is alive
};

#endif
