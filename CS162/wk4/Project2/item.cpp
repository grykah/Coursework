/******************************************************************************
** Program Filename: item.cpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: item.cpp is the implementation file that creates an item.
*******************************************************************************/
#include "item.hpp"// brings in the specification file
#include <iostream>
#include <string>
#include <iomanip>

/*********************************************************************
** Function: Item()
** Description: when an instacne of this class is created it sets the values to default
** Parameters: None
*********************************************************************/ 
Item::Item()
{
    this->name = " ";
    this->unit = " ";
    this->numToBuy = 0;
    this->unitPrice = 0;
    this->total = unitPrice * numToBuy;
};

/*********************************************************************
** Function: Item()
** Description: when an instacne of this class is created it sets the values to the parameters that passed in.
** Parameters: name, address
*********************************************************************/ 
Item::Item(std::string name, std::string address)
{
    this->name = name;
    this->address = address;

}

/*********************************************************************
** Function: getName()
** Description: returns name value when called.
** Parameters: None
*********************************************************************/ 
std::string Item::getName()
{
    return name;
}

/*********************************************************************
** Function: getUnit()
** Description: returns unit value when called.
** Parameters: None
*********************************************************************/ 
std::string Item::getUnit()
{
    return unit;
}

/*********************************************************************
** Function: getNumToBuy()
** Description: returns numToBuy value when called.
** Parameters: None
*********************************************************************/ 
double Item::getNumToBuy()
{
    return numToBuy;
}

/*********************************************************************
** Function: getUnitPrice()
** Description: returns unitPrice value when called.
** Parameters: None
*********************************************************************/
double Item::getUnitPrice()
{
    return unitPrice;
}

/*********************************************************************
** Function: getNumToBuy()
** Description: returns total value when called.
** Parameters: None
*********************************************************************/
double Item::getTotal()
{
    return total;
}

/*********************************************************************
** Function: print()
** Description: prints to console the item's detail when called.
** Parameters: None
*********************************************************************/
void Item::print()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Unit: " << unit << std::endl;
    std::cout << "Quantity: " << numToBuy << std::endl;
    std::cout << "Price Per Unit: $" << std::setprecision(2) << std::fixed << unitPrice << std::endl;
    std::cout << "Total: $" << std::setprecision(2) << std::fixed << total << std::endl;
}
