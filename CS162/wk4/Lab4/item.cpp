/******************************************************************************
** Program Filename: item.cpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: item.cpp is the implementation file for all item info.
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
    this->address = " ";

};

/*********************************************************************
** Function: Item()
** Description: when an instacne of this class is created it sets the values to the parameters that passed in.
** Parameters: name, address
*********************************************************************/ 
Item::Item(std::string name, std::string address, std::string rank)
{
    this->name = name;
    this->address = address;
	this->age = age;

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
std::string Item::getAddress()
{
    return address;
}

/*********************************************************************
** Function: getNumToBuy()
** Description: returns numToBuy value when called.
** Parameters: None
*********************************************************************/ 
std::string Item::getAge()
{
    return age;
}

/*********************************************************************
** Function: getUnitPrice()
** Description: returns unitPrice value when called.
** Parameters: None
*********************************************************************/
std::string Item::getGPA()
{
    return GPA;
}

/*********************************************************************
** Function: getNumToBuy()
** Description: returns total value when called.
** Parameters: None
*********************************************************************/
std::string Item::getinstructorRating()
{
    return instructorRating;
}


/*********************************************************************
** Function: printP()
** Description: prints to console the people's details when called.
** Parameters: None
*********************************************************************/
void Item::printP()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
	std::cout << "Rating: " << GPA << instructorRating << std::endl;

}

/*********************************************************************
** Function: printB()
** Description: prints to console the building's details when called.
** Parameters: None
*********************************************************************/
void Item::printB()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
	
}
