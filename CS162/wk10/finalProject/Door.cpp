/********************************************************
** Program: Door.cpp
** Author: Hailey Wilder
** Description: Door class implemenation file.
********************************************************/
#include "Room.hpp" // Brings in the Room.hpp specification file
#include "Door.hpp" // Brings in the Door.hpp specification file
#include "Player.hpp" // Brings in the Player.hpp specification file
#include "Inventory.hpp" // Brings in the Inventory.hpp specification file
#include <iostream>
#include <string>

/********************************************************
 ** Function: enterRoom ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/
GameStatus Door::enterRoom(Player *player)
{
    int choice;
	Item itemName;
	std::string inputPwd;
    
    do
    {
        //Check timer
        if(player->outOfTime())
            return OUT_OF_TIME;
        
        //Output room description and menu options

        std::cout << "\nYou are at the " << name << ".\n";
		std::cout << "Intercom Speaker: Enter password: \n";
		std::cin >> inputPwd;
		// Clear the buffer
		std::cin.clear();
		std::cin.ignore(256,'\n');
		if (!inputPwd.compare("1234"))
		{
			std::cout << "\nIntercom Speaker: Password Confirmed! \n";
			std::cout << "Intercom Speaker: Scan your badge. \n";
			
			itemName = player->getInventory()->useItem();
			
			if(itemName == Name_Badge)
			{
				std::cout << "Intercom Speaker: Bage confirmed! \n";
				std::cout << "Intercom Speaker: Scan your RF ID Card. \n";
				itemName = player->getInventory()->useItem();
			
				if(itemName == RF_ID_Card)
				{
					std::cout << "Intercom Speaker: RF ID Card Confirmed! \n";
					openDoor = true;
					return ESCAPED;
				}
				else
					std::cout << "Intercom Speaker: RF ID Card Denied! \n";
			}
			else
				std::cout << "Intercom Speaker: Badge Denied!. \n";
		}
		else
			std::cout << "Intercom Speaker: Password incorrect! \nHINT: Play video tape.\n";
        
        printMenu();
        std::cin >> choice;
        
        switch(choice)
        {
            //Go to sitting room
            case 1:
                player->setLocation(left);
                break;
            
            //Go to dungeon
            case 2:
                player->setLocation(up);
                break;
				
			//Go to guest bath
            case 3:
                player->setLocation(down);
                break;
				
			//Go to master bedroom
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
void Door::printMenu()
{
	std::cout << "\nWhere to go next:\n";
    std::cout << "1. Go to sitting area\n";
	std::cout << "2. Go to dungeon\n";
	std::cout << "3. Go to guest bath\n";
	std::cout << "4. Go to master bedroom\n";
    std::cout << "5. Use an item/Inventory\n";
    std::cout << "Selection: ";
}
