/*****************************************************************************
** Program: Stack.hpp
** Author: Hailey Wilder
** Description: Stack.hpp is the spcification file header for the Stack class.
******************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include <stack>
#include <iostream>
#include <string>

class Stack 
{
	private:
	std::stack<char> myStack; // create a char type stack
	std::string sentString;

	public:
	Stack(std::string); // constructor
	std::string palindrome(); // creates the palindrome
};

#endif
