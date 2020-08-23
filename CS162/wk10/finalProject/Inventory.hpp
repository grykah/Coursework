/***********************************************************
** Program: Inventory.hpp
** Author: Hailey Wilder
** Description: Inventory.hpp is the specification class.
************************************************************/
#ifndef INVENTORY
#define INVENTORY
#include <vector> // used to ctreate a vector

enum Item { Video_Tape, Name_Badge, RF_ID_Card, NO_ITEM};

class Inventory
{
    public:
        void addItem(Item itemName);
        void removeItem(Item itemName);
        Item useItem();
        int getSize();
    
    private:
        std::vector <Item> items;
    
        void printItem(Item itemName);
};

#endif
