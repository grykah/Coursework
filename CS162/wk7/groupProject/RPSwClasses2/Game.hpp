/******************************************************
** Program: Game.hpp
** Author: Group 20
** Date: 02/21/2017
** Description: Game class
** Input: none
** Output: none
******************************************************/

#ifndef Game_HPP
#define Game_HPP
#include "tool.hpp"
#include <stdio.h>

class Game {
protected:
	Tool *human;
	Tool *computer;
	Tool* Toolinput();
	Tool* CompPick();
	void MatchCheck();
	void chooseStrength();	
	int humanWins;
	int compWins;
	int ties;
	int rockStrength;
	int paperStrength;
	int scissorsStrength;

public:
	Game();
	~Game();
	Game(const Game &other);
	void operator=(const Game &other);
	int GamePlay();
};

#endif