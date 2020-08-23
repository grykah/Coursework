/******************************************************
** Program: rock.cpp
** Author: Group 20
** Date: 02/21/2017
** Description: implementation of rock 
** Input: none
** Output: none
******************************************************/

#include "rock.hpp"

Rock::Rock() {
	strength = 1;
	type = 'r';
}

Rock::Rock(int val) {
	strength = val;
	type = 'r';
}

bool Rock::fight(Tool AI) {
	int temp = strength;
	if (AI.getType() == 's') {
		temp = strength * 2;
	}
	else if (AI.getType() == 'p') {
		temp = strength / 2;
	}
	return temp > AI.getStrength();
}

void Rock::operator=(const Rock &other) {
	strength = other.strength;
	type = other.type;
}

Rock::Rock(const Rock &other) {
	strength = other.strength;
	type = other.type;
}

Rock::~Rock() {
}