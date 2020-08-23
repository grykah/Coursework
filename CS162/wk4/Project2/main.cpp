/****************************************************************************** 
** Program Filename: main.cpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: This is the main for the grocery list that displays the menu.
** This program allows to input grocery items to a list, and allows to remove
** particular items as desired. 
*******************************************************************************/

#include <iostream>
#include <string>
#include "list.hpp" //list class specification file 
#include "item.hpp" //item class specificaiton file

int main()
{
	int choice; // var for menu selection
	List itemList; // creates a List variable

	std::cout << std::endl << "Welcome to Assignment 2:\nGrocery Shopping List!" << std::endl;

	do 
	{
		std::cout << "Please make a selection: " << std::endl;
		std::cout << "1) Add an item to the grocery list" << std::endl;
		std::cout << "2) Delete an item from the grocery list" << std::endl;
		std::cout << "3) Print grocery list" << std::endl;
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

			case 1: // Add item to grocery list
			{
				std::string name;
				std::string unit;
				int numToBuy;
				double unitPrice;

				std::cout << std::endl;
				std::cout << "***Option 1: Add an item to the grocery list***" << std::endl << std::endl;
				std::cout << "Enter the Item's name: " << std::endl;
				std::cin.clear(); // clears error flag if any
				std::cin.ignore(256, '\n'); // ignores next line from the stream
				std::getline(std::cin, name); // this method allows spaces

				std::cout << "Enter Item's unit (i.e. can, lbs, or oz): " << std::endl;
				std::getline(std::cin, unit);

				std::cout << "Enter the quantity needed: " << std::endl;
				std::cin >> numToBuy;
				// checks to see if user enters a valid qty number.
				while (numToBuy <= 0 || std::cin.fail())
					{
						std::cin.clear(); // clears error flags if any
						std::cin.ignore(256, '\n'); // ignores next line from the stream
						std::cout << "Quantity has to be greater than 0! " << std::endl;
						std::cout << "Enter the quantity needed: " << std::endl;
						std::cin >> numToBuy;
					}

				std::cout << "Enter item's price per unit (do not enter $ symbol): " << std::endl;
				std::cin >> unitPrice;
				std::cout << std::endl;
				// checks to see if the user enters a valid price
				while (unitPrice < 0 || std::cin.fail())
					{
						std::cin.clear(); // clears error flags if any
						std::cin.ignore(256, '\n'); // ignores next line from the stream
						std::cout << "Unit price has to be equal or greater than $0.00! " << std::endl;
						std::cout << "Enter item's price per unit (do not enter $ symbol): " << std::endl;
						std::cin >> unitPrice;
						std::cout << std::endl;
					}
				Item item(name, unit, numToBuy, unitPrice);
				// this uses the overloaded "==" operator to compare to see if the item name already exist in the list
				if (itemList == name) // will not add if item name is in the list
				{
					std::cout << "\nThis item name already exsist and was not added to the list!\nTo update the list please delete (option 2) duplicate item and add it again.\n" << std::endl; 					
				}
				else // will add item to the list 
				itemList.addItem(item);
	
				break;
			}

		
		case 2: // Delete item from the list
		{
			int item; 

			std::cout << std::endl;
			std::cout << "***Option 2: Delete an item from the grocery list***" << std::endl << std::endl;
			if (itemList.getCount() == 0) // checks to see if there is any items by grabbing the counter variable value from the itemList object
			{
				std::cout << "No items in the grocery list to delete!" << std::endl << std::endl;
					break;
			}
			itemList.printList(); // prints out current list
			std::cout << "Please enter the item number that you would like to delete: ";
			std::cin >> item;
			//checks user input to make sure they entered an item that is in the list. 
			while (item > itemList.getCount() || item < 0 || std::cin.fail())
			{
				std::cout << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cout << "Invalid item selection!" << std::endl;
				std::cout << "Please enter the item number that you would like to delete: ";
				std::cin >> item;
			}

			item -= 1; // subtract 1 before sending it to the member function
			std::cout << std::endl;

			itemList.deleteItem(item); // deletes item from the dynamic array 
			std::cout << "Item removed successfully! " << std::endl << std::endl;
		
			break;
		}

		case 3: //print grocery list
		{
			std::cout << std::endl;
			std::cout << "***Option 3: Print grocery list***" << std::endl;
			std::cout << std::endl;
			itemList.printList(); // calls the pintList member function
			break;
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
}
