/**********************************************************
** Program: Inventory.cpp
** Author: Hailey Wilder
** Description: Inventory.cpp is the implemenation file.
***********************************************************/
#include "Inventory.hpp" // Brings in the Inventory.hpp specification file
#include "Room.hpp" // Brings in the Room.hpp specification file
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

/********************************************************
 ** Function: addItem () 
 ** Description: adds item to inventory.
 ** Parameters: itemName
 ********************************************************/
void Inventory::addItem(Item itemName)
{
    items.push_back(itemName);
}


/********************************************************
 ** Function: removeItem ()
 ** Description: removes an item from inventory
 ** Parameters: itemName
 ********************************************************/
void Inventory::removeItem(Item itemName)
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items.at(i) == itemName)
            items.erase(items.begin() + i);
    }
}


/********************************************************
 ** Function: useItem ()
 ** Description: disp inventory and chose item.
 ** Parameters: None
 ********************************************************/
Item Inventory::useItem()
{
    unsigned int idx;
    int choice;
    
    if (items.size() == 0)
    {
        std::cout << "\nYou don't have any items.\n";
        return NO_ITEM;
    }
    
    do
    {
        //Display the items
        std::cout << "\nItems you have:\n";
        for(idx = 0; idx < items.size(); idx++)
        {
            std::cout << "   " << idx + 1 << ". ";
            printItem(items.at(idx));
        }
        
        //Get a choice from user and error check
        std::cout << "   " << idx + 1 << ". Go back\n"
                  << "     -> ";
        std::cin >> choice;
        
        if(std::cin.fail())
        {
			// Clear the buffer
			std::cin.clear();
			std::cin.ignore(256,'\n');
            choice = -1;
        }
        
        std::cin.ignore(999, '\n');
        
        if (choice < 1 || choice > items.size() + 1)
            std::cout << "\nTime is running out!\n";
        
    }while (choice < 1 || choice > items.size() + 1);
    
    //Return choice, if any
    if (choice <= items.size())
        return items.at(choice - 1);
    
    return NO_ITEM;
}

/********************************************************
 ** Function: getSize ()
 ** Description: returns size of inventory
 ** Parameters: None
 ********************************************************/
int Inventory::getSize()
{
    return items.size();
}

/********************************************************
 ** Function: printItem ()
 ** Description: Prints items descriptions/
 ** Parameters: itemName
 ********************************************************/
void Inventory::printItem(Item itemName)
{
    switch(itemName)
    {
        case Video_Tape:
            std::cout << "Video Tape\n";
            break;
            
        case Name_Badge:
            std::cout << "Name Badge\n";
            break;
            
        case RF_ID_Card:
            std::cout << "RF_ID_Card";
            break;
            
        case NO_ITEM:
            break;
    }
}