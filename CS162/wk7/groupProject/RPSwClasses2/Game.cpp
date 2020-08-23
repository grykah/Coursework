/******************************************************
** Program: Game.cpp
** Author: Group 20
** Date: 02/21/2017
** Description: implementation that determines game logic
** starts Gameplay()
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Game.hpp"
#include "scissors.hpp"
#include "rock.hpp"
#include "paper.hpp"
using namespace std;



void Game::chooseStrength() {
	cout << "Pick your strength for Rock";
	cin >> rockStrength;
	cout << endl;
	cout << "Pick your strength for Paper";
	cin >> paperStrength;
	cout << endl;
	cout << "Pick your strength for Scissors";
	cin >> scissorsStrength;
	cout << endl;
}

Tool* Game::CompPick() {
	int x = rand() % 3 + 1;
	if (x == 1) {
		cout << "The Computer choose Rock!" << endl;
		return new Rock(rockStrength);
	}
	else if (x == 2) {
		cout << "The Computer choose Paper!" << endl;
		return new Paper(paperStrength);
	}
	else if (x == 3) {
		cout << "The Computer choose Scissors!" << endl;
		return new Scissors(scissorsStrength);
	}
	return 0;
}


Tool* Game::Toolinput() {
	char choice;
	do {
		cout << "Choose your tool. (r-rock, p-paper, s-scissors, e-exit)" << endl;
		cin >> choice;

		if (choice == 'r') {
			return new Rock(rockStrength);
		}
		else if (choice == 'p') {
			return new Paper(paperStrength);
		}
		else if (choice == 's') {
			return new Scissors(scissorsStrength);
		}
		else if (choice == 'e') {
			return 0;
		}
		else {
			cout << "Invalid input." << endl;
		}
	} while (true);
	return 0;
}

Game::Game() {
	rockStrength = 1;
	scissorsStrength = 1;
	paperStrength = 1;
	humanWins = 0;
	compWins = 0;
	ties = 0;
}

void Game::MatchCheck() {
	if (human->fight(*computer)) {
		cout << "You Win!" << endl;
		humanWins++;
	}
	else if (computer->fight(*human)) {
		cout << "The Computer wins!" << endl;
		compWins++;
	}
	else {
		cout << "It's a Tie game." << endl;
		ties++;
	}
	cout << "Human wins: " << humanWins << endl;
	cout << "Computer wins: " << compWins << endl;
	cout << "Ties: " << ties << endl;
}


int Game::GamePlay() {
	int ModStrength;
	cout << "Welcome to Rock, Paper, Scissors! Do you want to choose different strengths for the tools?" << endl;
	cout << "1) Yes" << endl;
	cout << "2) No" << endl;
	cin >> ModStrength;

	do {
		if (ModStrength == 1) {
			chooseStrength();
		}
		human = Toolinput();
		if (human == NULL) {
			return 0;
		}
		computer = CompPick();
		MatchCheck();
		delete human;
		delete computer;
	}

	while (1);
}

void Game::operator=(const Game &other) {
	humanWins = other.humanWins;
	compWins = other.compWins;
	ties = other.ties;
	if (other.human != NULL) {
		delete other.human;
	}
	if (other.computer != NULL) {
		delete other.computer;
	}
}

Game::Game(const Game &other) {
	if (other.human == NULL) {
		human = NULL;
	}
	else if (other.human->getType() == 'r') {
		human = new Rock;
		human->setStrength(other.human->getStrength());
	}
	else if (other.human->getType() == 's') {
		human = new Scissors;
		human->setStrength(other.human->getStrength());
	}
	else if (other.human->getType() == 'p') {
		human = new Paper;
		human->setStrength(other.human->getStrength());
	}
}

Game::~Game() {
	if (human != NULL) {
		delete human;
	}
	if (computer != NULL) {
		delete computer;
	}
}