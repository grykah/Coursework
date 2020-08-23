/********************************************************
** Program: SittingArea.cpp
** Author: Hailey Wilder
** Description: SittingArea.cpp implementation file.
********************************************************/
#include "Room.hpp" // Brings in the Room.hpp specification file
#include "SittingArea.hpp" // Brings in the SittingArea.hpp specification file
#include "Player.hpp" // Brings in the Player.hpp specification file
#include "Inventory.hpp" // Brings in the Inventory.hpp specification file
#include <iostream>
#include <cstdio>

/********************************************************
 ** Function: enterRoom ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/
GameStatus SittingArea::enterRoom(Player *player)
{
    int choice;
	char answer;
	Item itemName;
    
   do
   {
	   // Clear the buffer
		std::cin.clear();
		std::cin.ignore(256,'\n');
        //Check timer
        if(player->outOfTime())
            return OUT_OF_TIME;
        
        //Output Room description and menu options
        
        std::cout << "\nYou are currently in the " << name << ", and there is middle table.";
		if(!nameBadge)
		{
			do{
				std::cout << "\nDo you want to pickup the name badge from the table (y/n)?  ";
				answer = getchar();
		
				if (answer == 'y' || answer == 'Y')
				{
					if(player->getInventory()->getSize() > 2)
						std::cout << "\nYou can't pick it up. Your hands are full.\n";
					else
					{
						nameBadge = true;
						player->getInventory()->addItem(Name_Badge);
						std::cout << "\nYou took the name badge.\n";
					}
				}
			 
				else if (answer == 'n' || answer == 'N')
				{
					std::cout << "\nOk, left the name badge alone.\n";
				}	
			} while (!((answer == 'n' || answer == 'N') || (answer == 'y' || answer == 'Y')));
		}
		else
			std::cout << "\nHINT: Nothing new!\n";
		
			printMenu();
			std::cin >> choice;
        
			switch(choice)
			{
				//Go to dungeon
				case 1:
					std::cin.clear();
					std::cin.ignore(256,'\n');
					player->setLocation(up);
					break;
				
				//Go to guest bath
				case 2:
					std::cin.clear();
					std::cin.ignore(256,'\n');
					player->setLocation(down);
					break;
				
				//Go to guest door
				case 3:
					std::cin.clear();
					std::cin.ignore(256,'\n');
					player->setLocation(left);
					break;
				
				//Go to guest master bedroom
				case 4:
					std::cin.clear();
					std::cin.ignore(256,'\n');
					player->setLocation(right);
					break;
					
				//Use an item
				case 5:
                itemName = player->getInventory()->useItem();
                if(itemName != NO_ITEM)
                {
                    std::cout << "You dont have any items.\n";
                }
                break;
                
				//Invalid choice
				default:
					std::cout << "\nInvalid choice!\n";
					break;
			}
        
        //Check timer
        if(player->outOfTime())
            return OUT_OF_TIME;
    }while (choice < 1 || choice > 5);
    
    return KEEP_PLAYING;
}


/********************************************************
 ** Function: printMenu()
 ** Description: Shows menu on where to go next.
 ** Parameters: None
 ********************************************************/
void SittingArea::printMenu()
{
	std::cout << "\nWhere to go next:\n";
    std::cout << "1. Go to dungeon\n";
	std::cout << "2. Go to guest bath\n";
	std::cout << "3. Go to the door\n";
	std::cout << "4. Go to master bedroom\n";
    std::cout << "5. Use an item/Inventory\n";
    std::cout << "Selection: ";
}
