/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Hailey Wilder
 ** Date: 2/19/17
 ** Description: This program runs some simple tests on the Stack and
 **              Queue classes and prints the results.
 ** Input: none
 ** Output: std::cout, results of operations on Stack and Queue objects
 *********************************************************************/

#include <iostream>

#include "Stack.hpp"
#include "Queue.hpp"

int main()
{
    int arr[];
	std::string contEnter = "y";
	Stack usIn;

	int choice; // var for menu selection

	std::cout << std::endl << "Welcome to Lab 6!" << std::endl;

	do 
	{
		std::cout << "Please make a selection: " << std::endl;
		std::cout << "1) Add an item" << std::endl;
		std::cout << "2) Remove an item" << std::endl;
		std::cout << "3) Print list" << std::endl;
		std::cout << "4) Exit" << std::endl;
		std::cout << "Choice: ";

		std::cin >> choice;

		// check for valid input
		while (choice < 1 || choice > 4 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n'); // Adding cin.ignore() to the next line clears / ignores the newline from the stream.
			std::cout << "Invalid  Selection! Choose an option from the menu above." << std::endl;
			std::cout << "Choice: ";
			std::cin >> choice;
		

		switch (choice)
		{

			case 1: 
			{
				std::cout << "Enter a number: \n\n";
				cin >> usIn;
				usIn.add(arr[]);
		
				std::cout << "Do you want another num (y or n)? \n\n";
				cin >> contEnter;
		
			}
			
			case 2:
			{
				std::cout << "Remove a number (y/n)? \n\n";
				cin >> usIn;
				usIn.remove();
							
			}
			
			case 3:
			{
				print usIn;
			}
			
			case 4:
			{
				std::cout << "***Goodbye!***" << std::endl;
				return 0;
			}
		}
		}
	}
	
}