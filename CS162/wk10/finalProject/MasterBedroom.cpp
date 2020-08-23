/************************************************************
** Program: MasterBedroom.cpp
** Author: Hailey Wilder
** Description: MasterBedroom.cpp is the implementaion file.
*************************************************************/
#include "Room.hpp" // Brings in the Room.hpp specification file
#include "MasterBedroom.hpp" // Brings in the masterBedroom.hpp specification file
#include "Player.hpp" // Brings in the Player.hpp specification file
#include "Inventory.hpp" // Brings in the Inventory.hpp specification file
#include <iostream>
#include <cstdio>

/********************************************************
 ** Function: enterRoom ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 ********************************************************/
GameStatus MasterBedroom::enterRoom(Player *player)
{
    int choice;
    Item itemName;
	char answer;
    
    do
    {
        //Check timer
        if(player->outOfTime())
            return OUT_OF_TIME;
        
        //Output room description and menu options
        
        std::cout << "\nYou are in the " << name << " where there is a big bed, TV, and a video tape player.\n";
		
		if(!videoTapePlayer)
		{	
			do{
				
				std::cout << "Do you want to use the video tape player (y/n)? ";
				//Clear buffer
				std::cin.clear();
				std::cin.ignore(256,'\n');
				answer = getchar();
			
				if (answer == 'y' || answer == 'Y')
				{
						// Clear buffer
						std::cin.clear();
						std::cin.ignore(256,'\n');
					    itemName = player->getInventory()->useItem();
    
					if(itemName == Video_Tape)
					{
						//player->getInventory()->addItem(Name_Badge);
						player->getInventory()->removeItem(Video_Tape);
        
						std::cout << "\nPlaying video tape: It's displaying code 1234 in the TV screen.\n";
						std::cout << "\nYou don't have the video tape any more in your items list since it stayed in the video player.\n";
						videoTapePlayer = true;
					}
					else if (itemName != NO_ITEM)
						std::cout << "\nYou dont have a video tape!\n";
							//std::cout << "\nPlaying video tape: It's displaying code: 1234.\n";
				}
			 
				else if (answer == 'n' || answer == 'N')
				{
					// Clear buffer
					std::cin.clear();
					std::cin.ignore(256,'\n');
					std::cout << "\nOk, left the video tape player alone.\n";
				}	
			} while (!((answer == 'n' || answer == 'N') || (answer == 'y' || answer == 'Y')));
		}
		else
			std::cout << "\nHINT: Nothing new, but the TV is still displaying code: 1234!\n";
		
        printMenu();
		std::cin >> choice;
        
        switch(choice)
        {
            //Go to sitting area
            case 1:
                player->setLocation(right);
                break;
            
            //Go to dungeon
            case 2:
                player->setLocation(up);
                break;
                
            //Go to guest bath
            case 3:
                player->setLocation(down);
                break;
                
            //Go to the door
            case 4:
                player->setLocation(left);
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
void MasterBedroom::printMenu()
{
	std::cout << "\nWhere to go next:\n";
    std::cout << "1. Go to sitting area\n";
	std::cout << "2. Go to dungeon\n";
	std::cout << "3. Go to guest bath\n";
	std::cout << "4. Go to the door\n";
    std::cout << "5. Use an item/Inventory\n";
    std::cout << "Selection: ";
}
