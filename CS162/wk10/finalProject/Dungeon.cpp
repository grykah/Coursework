/********************************************************
** Program: Dungeon.cpp
** Author: Hailey Wilder
** Description: Implementation for Dungeon.cpp file.
********************************************************/
#include "Room.hpp" // Brings in the Room.hpp specification file
#include "Dungeon.hpp" // Brings in the Dungeon.hpp spcification file
#include "Player.hpp" // Brings in the Player.hpp specification file
#include "Inventory.hpp" // Brings in the Inventory.hpp specification file
#include <iostream>
#include <cstdio>

/**********************************************************
 ** Function: enterRoom ()
 ** Description: Takes the user to the specified location.
 ** Parameters: Address of a Player type object
 **********************************************************/
GameStatus Dungeon::enterRoom(Player *player)
{
    int choice;
	char answer;
	Item itemName;
    
    do
    {
        //Check timer
        if(player->outOfTime())
            return OUT_OF_TIME;
        
        //Room description and action options
        std::cout << "\nYou are in the " << name << " and you noticed the big camera in the left side of the room.\n";
		if(!videoTape) // if player does not have video tape continue
		{
			do{
				std::cout << "Do you want to take out the video tape inside the camera (y/n)? ";
				answer = getchar();
		
				if (answer == 'y' || answer == 'Y')
				{
					if(player->getInventory()->getSize() > 2) // Limit the amount of items
					{
						std::cout << "\nYou can't pick it up. Your hands are full.\n";
						std::cout << "\nDo you want to remove an item (y/n)?\n";
						// Clear the buffer
						std::cin.clear();
						std::cin.ignore(256,'\n');
						answer = getchar();
					
						if (answer == 'y' || answer == 'Y')
						{
							itemName = player->getInventory()->useItem();
							player->getInventory()->removeItem(itemName);
						}
						else
						{
							std::cout << "\nOk, I warned you that your hands are full!\n";
						}
					}
					else
					{
						videoTape = true;
						player->getInventory()->addItem(Video_Tape);
						std::cout << "\nYou took the video tape.\n";
					}
				}
			 
				else if (answer == 'n' || answer == 'N')
				{
					std::cout << "\nOk, left the video tape alone.\n";
				}	
			} while (!((answer == 'n' || answer == 'N') || (answer == 'y' || answer == 'Y')));
		}
		else
			std::cout << "HINT: Nothing new!\n";
		
		printMenu();
		std::cin >> choice;
		
        switch(choice)
        {
            //Go upstairs to sitting area
            case 1:
                player->setLocation(left);
                break;
				
			//Go to guest bath	
			 case 2:
                player->setLocation(up);
                break;
				
			//Go to the door	
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
                std::cout << "\nInvalid Choice!\n";
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
void Dungeon::printMenu()
{
	std::cout << "\nWhere to go next:\n";
    std::cout << "1. Go to sitting area\n";
	std::cout << "2. Go to guest bath\n";
	std::cout << "3. Go to the door\n";
	std::cout << "4. Go to master bedroom\n";
    std::cout << "5. Use an item/Inventory\n";
    std::cout << "Selection: ";
}
