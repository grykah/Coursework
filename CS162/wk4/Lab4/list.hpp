/******************************************************************************
** Program Filename: list.hpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: list.hpp is the specification file that will hold all items
** inside a dynamic array in a List object.
*******************************************************************************/
#ifndef LIST_HPP
#define LIST_HPP

#include <fstream>
#include <string>
#include "item.hpp" // brings in the item class


class List
{
    private:
		int counter; 				// tracks items enterd to shopList object
    	int memSize; 				// value will increase if more memory needed
		Item *shopList; 			// points to shopList address
    
	public:
        List(); 					// default constructor
        void addItem(Item); 		// adds items to the dynamic array
        void deleteItem(int);   	// deletes item from list
        int getCount(); 			// returns # items in list
        
		void printListP();
		void printListB(); 			// prints the entire list 
		bool operator==(std::string);// overloads the "==" operator to check if item exsits in list. 
};

#endif