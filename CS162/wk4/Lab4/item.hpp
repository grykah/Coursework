/******************************************************************************
** Program Filename: item.hpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: item.hpp is the specification file for collecting item info.
*******************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
    private:
        std::string name; 						// name
        std::string address; 					// address
        std::string age; 							// age
        std::string GPA; 							// student GPA
        std::string instructorRating; 				// instructor rating 

    public:
		Item(); 										 		// default constructor
        Item(std::string, std::string, std::string); 			// overloaded constructor: name and address or name, age, GPA/rating
        std::string getName(); 						 			// passes current name
        std::string getAddress(); 								// passes current address
        std::string getAge(); 						// passes current age
        std::string getGPA(); 						// passes current student GPA
        std::string getinstructorRating(); 			// passes current instructor rating
		void printP();							// print item information for people
        void printB(); 							// print item information for buildings
};

#endif