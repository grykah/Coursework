/******************************************************************************
** Program Filename: item.hpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: item.hpp is the specification file that creates an item.
*******************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
    private:
        std::string name; 							// item name 
        std::string address; 							// units e.g. can, box, pounds or ounces
        double numToBuy; 							// quantity
        double unitPrice; 							// item price
        double total; 								// stores the item total cost = numToBuy x unitPrice; 

    public:
	Item(); 										 // default constructor
        Item(std::string, std::string); // overloaded constructor
        std::string getName(); 						 // passes current item name
        std::string getUnit(); 						// passes current item unit
        double getNumToBuy(); 						// passes current item quantity
        double getUnitPrice(); 						// passes current item price
        double getTotal(); 							// passes current item total price
        void print(); 								// print item information
};

#endif