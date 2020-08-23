/********************************************************************************************
** Program: main.hpp
** Author: Hailey Wilder
** Date: 3/6/17
** Description: This program uses the STL (stack/queue). 
*********************************************************************************************/
#include <cstdlib>
#include <iostream>
#include <string>
#include <queue> // queue::push/pop
#include "Dice.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
// Refernce: http://www.cplusplus.com/reference/queue/queue/
// Refernce: http://www.cplusplus.com/reference/stack/stack/

int main()
{
    Queue myQueue;
    int rounds; // holds the number of rounds
    int chance; // percentage chance that a value will be entered to the queue
    int rmChance; // percentage chance that a value will NOT be entered to the queue
    std::string word; // holds the string to create a palindrome
    int choice;
    
    std::cout << "\n************Welcome to Lab 9: STL Containers (queue/stack)!************\n";

    while (choice != 3) 
    {
	std::cout << "\nMenu:" << std::endl;
	std::cout << "1. Queue test" << std::endl;
	std::cout << "2. Stack test (palindrome)" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Choice: ";
	std::cin >> choice;
	//checks the input to see if it is valid selection
	while (choice < 1 || choice > 3 || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(256, '\n'); 
		std::cout << "Invalid  Selection! Choose an option from the menu above i.e. <1> for Queue Test." << std::endl;
		std::cout << "Choice: ";
		std::cin >> choice;
	}

	switch (choice) 
	{
	   case 1:
	   {
    		std::cout << "\nEnter the chance, in percent, of an item arriving (0-100): ";
    		std::cin >> chance;
		//checks the input to see if it is valid selection
		while (chance < 0 || chance > 100 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid! i.e. <50> for 50%." << std::endl;
			std::cout << "Enter: ";
			std::cin >> chance;
		}

    		std::cout << "Enter the chance, in percent, of an item being removed (0-100): ";
    		std::cin >> rmChance;
		//checks the input to see if it is valid selection
		while (rmChance < 0 || rmChance > 100 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid! i.e. <50> for 50%." << std::endl;
			std::cout << "Enter: ";
			std::cin >> rmChance;
		}
    		std::cout << "Enter the number of turns for this rounds: ";
    		std::cin >> rounds;
		//checks the input to see if it is valid selection
		while (rounds < 0 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid! i.e. <50> for 50 turns." << std::endl;
			std::cout << "Enter: ";
			std::cin >> rounds;
		}

    		myQueue.simulate (rounds, chance, rmChance);
		break;
	   }	      
	  
	  case 2:
	  {
		std::cout << "\nEnter a string: ";
		std::cin >> word;
		Stack myStack(word);
		std::string result = myStack.palindrome();
		std::cout << "palindrome: " << result << std::endl;
		
		break;
	  }
	
	  case 3:
		std::cout << "Bye Bye!\n";
       }
   }
    return 0;
}

