/******************************************************
** Program: tool.cpp
** Author: Group 20
** Date: 02/21/2017
** Description: 
** Input: none
** Output: none
******************************************************/

#include "tool.hpp"

Tool::Tool() {}

void Tool::setStrength(int x) {
	strength = x;
}

void Tool::setType(int userType) {
	type = userType;
}

int Tool::getType() {
	return type;
}

int Tool::getStrength() {
	return strength;
}

bool Tool::fight(Tool) {
	return 0;
}

Tool::~Tool() {
}

