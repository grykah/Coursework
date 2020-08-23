/*********************************************************************
** Program: Stack.cpp
** Author: Hailey Wilder
** Description: Stack.cpp is the implemntation file for Stack class.
*********************************************************************/
#include <stack>
#include <iostream>
#include <string>
#include <cstring>
#include "Stack.hpp"

/*********************************************************************
** Function: Stack()
** Description: receives string and converts it to chars to puch to 
** myStack.
** Parameters: string word
*********************************************************************/ 
Stack::Stack(std::string word)
{	
	sentString = word;
	char *y = new char[word.length()+1]; // creates a char array dynamically
	std::strcpy(y, word.c_str());

	for (int x = 0; x < word.length(); x++)
	{
		myStack.push(y[x]); // pushing each char to the stack
	}
	
	delete [] y; // deallocates the memeory
}

/*********************************************************************
** Function: palindrome()
** Description: Creates any string to a palindrome and returns it. 
** Parameters: N/A
*********************************************************************/ 
std::string Stack::palindrome()
{
	std::string palin; // will store the palindrome string to return

	while (!myStack.empty()) // contines until stack is empty
	{
		palin += myStack.top(); // concatenation
		myStack.pop(); // removes char
	}
	
	palin = sentString + palin; // concatenation

	return palin;
}

