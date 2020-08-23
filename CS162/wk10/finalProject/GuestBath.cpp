/********************************************************
** Program: GuestBath.cpp
** Author: Hailey Wilder
** Description: GuestBath.cpp is the implemnation file.
********************************************************/
#include "Room.hpp" // brings in the Room.hpp specification file
#include "GuestBath.hpp" // brings in the GuestBath.hpp specification file
#include "Player.hpp" // brings in the Player.hpp specification file
#include "Inventory.hpp" // brings in the Inventory.hpp specification file
#include <iostream>
#include <cstdio>

/********************************************************
 ** Function: enterRoom ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/
GameStatus GuestBath::enterRoom(Player *player)
{
    int choice;
	char answer;
    Item itemName;
    
    do
    {
        //Check timer
        if(player->outOfTime())
            return OUT_OF_TIME;
        
        //Output room description and menu options
        std::cout << "\nYou are in the " << name << ". \n";
		
		if(!rfIDCard)
		{
			do{
				// Clear the buffer
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cout << "\nSomething rectangle is sticking out from the towels.\n";
				std::cout << "Do you want to pickup the rectangle object within the towels (y/n)? ";
				answer = getchar();
		
				if (answer == 'y' || answer == 'Y')
				{
					if(player->getInventory()->getSize() > 2)
						std::cout << "\nYou can't pick it up. Your hands are full.\n";
					else
					{
						rfIDCard = true;
						player->getInventory()->addItem(RF_ID_Card);
						std::cout << "\nYou took the RF ID Card.\n";
					}
				}
			 
				else if (answer == 'n' || answer == 'N')
				{
					std::cout << "\nOk, left the rectangle item alone.\n";
				}	
			} while (!((answer == 'n' || answer == 'N') || (answer == 'y' || answer == 'Y')));
		}
		else
			std::cout << "HINT: Nothing new!\n";
        
        printMenu();
        std::cin >> choice;
        
        switch(choice)
        {              
            //Go to sitting area
            case 1:
                player->setLocation(left);
                break;
                
            //Go to dungeon
            case 2:
                player->setLocation(up);
                break;
				
			 //Go to the door
            case 3:
                player->setLocation(down);
                break;
				
			 //Go to master room
            case 4:
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
void GuestBath::printMenu()
{
	std::cout << "\nWhere to go next:\n";
    std::cout << "1. Go to sitting area\n";
	std::cout << "2. Go to dungeon\n";
	std::cout << "3. Go to the door\n";
	std::cout << "4. Go to master bedroom\n";
    std::cout << "5. Use an item/Inventory\n";
    std::cout << "Selection: ";
}