/******************************************************************************
** Program Filename: 
** Author: Hailey Wilder
** Date: 2/2/17
** Description: main file using Person and University
*******************************************************************************/
using namespace std;
#include <iostream>
#include <string>
#include "Person.hpp" //Person class specification file 
#include "University.hpp" //University class specificaiton file

int main() {
	int choice; // var for menu selection
	//List itemList; // creates a List variable
	List BuildingList;  //creates building list
	List EmployeeList;  //creates employee list
	
	std::cout << std::endl << "Welcome to Lab 4:\nOregon State University Directory!" << std::endl;

	do 
	{   // menu options -- enter choice 1-4
		std::cout << "Please make a selection: " << std::endl;
		std::cout << "1) Print employee list " << std::endl;
		std::cout << "2) Print building list " << std::endl;
		std::cout << "3) Do_work" << std::endl;
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
		}

		switch (choice)
		{

		case 1: //print personnel list
		{
			std::cout << std::endl;
			std::cout << "***Option 1: Print employee list***" << std::endl;
			std::cout << std::endl;
			EmployeeList.printList(); // calls the pintList member function
			break;
		}
		
		case 2: // print building list
		{
			std::string name;
			std::string address;
			
			std::cout << std::endl;
			std::cout << "***Option : Print building list***" << std::endl;
			std::cout << std::endl;
			
			std::cout << "Enter building name: " << std::endl;
			std::cin.clear(); // clears error flag if any
			std::cin.ignore(256, '\n'); // ignores next line from the stream
			std::getline(std::cin, name); // this method allows spaces
			
			std::cout << "Enter building address: " << std::endl;
			std::cin.clear(); // clears error flag if any
			std::cin.ignore(256, '\n'); // ignores next line from the stream
			std::getline(std::cin, address); // this method allows spaces
			
			Item build(name, address);
			// this uses the overloaded "==" operator to compare to see if the item name already exist in the list
			if (BuildingList == name) // will not add if item name is in the list
			{
				std::cout << "\nThis item name already exsist and was not added to the list!\nTo update the list please delete (option 2) duplicate item and add it again.\n" << std::endl; 					
			}
			else // will add item to the list 
			BuildingList.addItem(build);
			
			Item b1("Building 1", "11 S St, OR 55555");
			BuildingList.addItem(b1);
			
			BuildingList.printList(); // calls the pintList member function
			break;
		}
		
		case 3: //do_work -- instructor/student
		{
			EmployeeList.printList();
			std::cout << std::endl;
			std::cout << "***Option 3: Choose a person to do work.***" << std::endl << std::endl;
			std::cout << "Enter a number: " << std::endl;
			std::cin.clear(); // clears error flag if any
			std::cin.ignore(256, '\n'); // ignores next line from the stream
			//std::getline(std::cin, name); // this method allows spaces

			
		}

		case 4: //exit out of the program
		{
			std::cout << "***Goodbye!***" << std::endl;
			return 0;
		}

		default:
		{
			break;
		}
		}
		
	} while (true);

	return 0;
}