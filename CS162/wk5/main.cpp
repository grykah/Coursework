/****************************************************************************** 
** Program Filename: main.cpp
** Author: Hailey Wilder
** Description: This program provides three recursion functions. 
*******************************************************************************/
#include <iostream>
#include <string>
#include "recursions.hpp" // brings in the recursions functions

int main()
{
	int selection; // used for menu selection 
	std::string userString; // used for the string being reversed
	int array [10]; // used for the summation of the array elements
	int rows; // used for the calulation of items of a triangle based on the rows

	std::cout << "\nLab 5: Recursive Functions \n";

  do{
	std::cout << "Please choose a recursive function:\n 1. Reverse a string\n 2. Calculate the sum of an array\n 3. Calculate the triangular number\n 4. Exit\n" << std::endl; 
	std::cout << "Enter your selection: " << std::endl; 
	std::cin >> selection;

	if (selection == 1)
	{
		std::cout << "Enter a string to reverse it: ";
		//std::cin >> userString; 
		//use below to get a sentence rather than word (difference being spaces)
		std::cin.clear(); // clears error flag if any
		std::cin.ignore(256, '\n'); // ignores next line from the stream
		std::getline(std::cin, userString); // this method allows spaces
		std::cout << "Reversed: " << stringReverse(userString) << std::endl << std::endl; // sends the userString variable to the stringReversed function and prints it to console. 	
	}
	
	else if (selection == 2)
	{
		int counts = 0;
		std::cout << "Enter 10 numbers into the array. To sum less than " << std::endl;
		std::cout << "ten numbers, enter any alpha character to exit.\n" << std::endl;

		do{ 

			std::cout << "Enter " << counts+1 << " number: " << std::endl;
			std::cin >> array[counts];
			counts++;

		  }while (!std::cin.fail() && (counts < 10)); // checks to see if a alpha character has been entered or if there has been 10 numbers entered to exit the loop

		std::cin.clear();
		std::cin.ignore(256, '\n'); // Adding cin.ignore() to the next line clears / ignores the newline from the stream.     

		std::cout << "The sum is: " << arraySum(array, counts) << std::endl << std::endl; // sends the array and number of elements to the arraySum function and prints it to console

	}
	
	else if (selection == 3) 
	{
		std::cout << "Enter the number of rows of that form the triangle: " << std::endl;
		std::cin >> rows;
		std::cout << "The triangular number is: " << triangle(rows) << std::endl << std::endl; // sends the int row to the triangle function and prints it to console
	}

	else if (selection == 4)
	{
		std::cout << "Goodbye!" << std::endl << std::endl;
		return 0;//exits the program
	}

	else
		std::cout << "Wrong selection, try again." << std::endl << std::endl;

  } while ( selection > 0 && selection < 4);

	return 0;
}