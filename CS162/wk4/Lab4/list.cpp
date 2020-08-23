/******************************************************************************
** Program Filename: list.cpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: list.cpp is the implementation file that will hold all items
** inside a List dynamic array obeject.
*******************************************************************************/
#include <iostream>
#include <strings.h>
#include <iomanip>
#include "item.hpp" //items specifications
#include "list.hpp" //list specifications

/*********************************************************************
** Function: List()
** Description: when an instacne of this class is created it sets the values to default.
** Parameters: None
*********************************************************************/ 
List::List() 
{
	counter = 0; // will keep track of items being enterd to the shopList dynamic array
    	memSize = 4; // this value will increase if more memory is needed to be allocated
	shopList = new Item [memSize]; 
	// shopList points to the first item address in the array of 'memSize'. Initalized to 4 slots
}

/*********************************************************************
** Function: List()
** Description: adds the Item variable passed to the List array vaiable
** Parameters: Item item
*********************************************************************/
void List::addItem(Item item)
{

   	if (counter < memSize) // it will store items to list up to 'memSize'
	{
		shopList [counter] = item; // store the item to the shopping list
		counter++; // increase the counter
	}
	else // this will increase the memory up to 4 array slots if array is already full	
	{
		
		// create another array to temporarly transfer the items before increasing the memory allocation for shopList
		Item *shopListCpy = new Item [memSize]; 
			
		for (int x = 0; x < memSize; x++) // transfering items to new array
		{
			shopListCpy [x] = shopList [x];
		}
			
		memSize += 4; // increase the memory size by 4
			
		shopList = new Item[memSize]; // actaually increased memory allocation here
			
		// transfer back the items to the original array shopList
		for (int y = 0; y < counter; y++)
		{
			shopList [y] = shopListCpy [y]; // transfering items to old array
		}
			
		delete [] shopListCpy; // release the memory allocation 
		shopList [counter] = item; // store the item to the shopping list
		counter++;
	} 
}

/*********************************************************************
** Function: getCount()
** Description: returns the counter variable (dynamic array size) when called.
** Parameters: None
*********************************************************************/
int List::getCount()
{
    return counter;
}



/*********************************************************************
** Function: deleteItem()
** Description: Removes a specific item from the List shopList array. 
** Parameters: int index
*********************************************************************/
void List::deleteItem(int index)
{
	Item *shopListCpy = new Item [counter]; // copy list to new array to remove the item selected
	
	for (int x = 0; x < index; x++) // tranfersing files to the new array up to the index. Index does not get copied over. 
	{
		shopListCpy[x] = shopList[x]; 
	}
	for (int x = (index+1); x < counter; x++) // continue copying to new array but skips the index 
	{
		shopListCpy[x-1] = shopList[x];
	}
	counter--; // subtract one from the counter
	for (int x = 0; x < counter; x++) // copy new array the original array which does not include the specified idex array
	{
		shopList[x] = shopListCpy[x];
	}

	delete [] shopListCpy; // release memory allocation

}

/*********************************************************************
** Function: printListP()
** Description: prints list and the grand total when called
** Parameters: None
*********************************************************************/
void List::printListP()
{
    for(int i = 0; i < counter; i++)
    {
        std::cout << "People: " << i + 1 << ": " << std::endl;
        shopList[i].printP();
        std::cout << std::endl;
    }
}

/*********************************************************************
** Function: printListB()
** Description: prints list and the grand total when called
** Parameters: None
*********************************************************************/
void List::printListB()
{
    for(int i = 0; i < counter; i++)
    {
        std::cout << "Buildings: " << i + 1 << ": " << std::endl;
        shopList[i].printB();
        std::cout << std::endl;
    }

	//std::cout << "The grocery list total is: $" << std::setprecision(2) << std::fixed << getTotalCost() << std::endl << std::endl;
}

/*********************************************************************
** Function: operator==()
** Description: compares the string passed to the List shopList name to see if already exist. 
** Parameters: string a
*********************************************************************/
bool List::operator==(std::string a)
{
	for (int x = 0; x < counter; x++)
	{
		if (this->shopList[x].getName() == a)
		{	
			return true;
		}
	}
	return false;
}







