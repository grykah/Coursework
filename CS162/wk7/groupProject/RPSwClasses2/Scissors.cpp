/******************************************************
** Program: scissors.cpp
** Author: Group 20
** Date: 02/21/2017
** Description: implementation of scissors 
** Input: none
** Output: none
******************************************************/

#include "scissors.hpp"

Scissors::Scissors() {
	strength = 1;
	type = 's';
}

Scissors::Scissors(int val) {
	strength = val;
	type = 's';
}

bool Scissors::fight(Tool AI) {
	int temp = strength;
	if (AI.getType() == 'p') {
		temp = strength * 2;
	}
	else if (AI.getType() == 'r') {
		temp = strength / 2;
	}
	return temp > AI.getStrength();
}

void Scissors::operator=(const Scissors &other) {
	strength = other.strength;
	type = other.type;
}

Scissors::Scissors(const Scissors &other) {
	strength = other.strength;
	type = other.type;
}

Scissors::~Scissors() {

}