/********************************************************************************************
** Program: Queue.cpp
** Author: Hailey Wilder
** Date: 02/21/2017
** Description: This program implements an abstract data type using linked structures. 
*********************************************************************************************/

#include <cstdlib>  // for NULL
#include <string>   // for std::string
#include <iostream> // for debug and output
#include "Queue.hpp" // imports the specfication file for this implementation file


/*********************************************************************
** Function: Queue()
** Description: The constructor that creates a first node to point to itself
** Parameters: None
*********************************************************************/ 

Queue::Queue()
{  
    QueueNode *first; // create pointer to an QueueNode
    first = new QueueNode(); // store the address of the new QueueNode memory allocation
    (*first).item = -1; // derefrence the pointer and store -1 sentinal 
    (*first).next = first; // defrefnce the pointer and assign the address of first to the next pointer
    (*first).prev = first; // derefrence the pointer and assign the address of first to the prev pointer

    front = first; // store the address of first in QueueNode front 
    back = first; // store the address of first in Queuenode back
}


/*********************************************************************
** Function: ~Queue()
** Description: Destructor that releases memory not being used anymore. 
** Parameters: None
*********************************************************************/ 

Queue::~Queue()
{
    QueueNode *present; // start at first node
    back = front->next;

    while (back != front) // destroy all the QueueNodes until we reach NULL
    {
        present = back;
        back = present->next;

        delete present;
    }

    delete back;    // delete last node

    front = NULL;
    back = NULL;
    present = NULL;
}


/*********************************************************************
** Function: addBack()
** Description: creates a new QueueNode and adds it to the back of the linked list.  
** Parameters: int number
*********************************************************************/ 

void Queue::addBack(int item)
{
    // next node after back [back node] -> [next node]
    QueueNode *upcoming = back->next;

    // Check to see if the next node is set to -1 sentinal (empty)
    if (upcoming->item == -1)
    {
        upcoming->item = item; // store the integer
        return;
    }

    // else, make a new node and insert it between back and upcoming
    
    	QueueNode *newNode = new QueueNode; // create a new QueueNode
    	newNode->item = item; // store the int value to the new node
    	newNode->prev = back; // make this new node point to the previous node 
    	newNode->next = upcoming; // make this new node point to the next node
        std::cout << "\n";
    

    // update the Queue's QueueNode back and after pointers
    back->next = newNode; // adds new node after the back node 
    upcoming->prev = newNode;
    back = newNode;
   
}


/*********************************************************************
** Function: getFront()
** Description: only displays the front element in the linked list and returns the value integer. If -1 is returned the linked list is empty.  
** Parameters: None
*********************************************************************/ 

int Queue::getFront()
{
    int out = front->item;

    return out;
}

/*********************************************************************
** Function: removeFront()
** Description: takes out the first value in the queue and returns it back.  
** Parameters: None
*********************************************************************/ 

int Queue::removeFront()
{
    int val = front->item;
   
    front->item = -1; // delete old node, by applying the sentiniel value

    front = front->next; // move to next element

    return val;
}

/*********************************************************************
** Function: printFronElement()
** Description: takes out the first value in the queue and returns it back.  
** Parameters: None
*********************************************************************/ 

void Queue::printFrontElement()
{
	std::cout << "Frist value in the stack: " << front->item << "\n" << std::endl;
}

/*********************************************************************
** Function: displayStackContents()
** Description: traverses the linked list structer to display. 
** Parameters: None
*********************************************************************/ 

void Queue::displayStackContents()
{
	QueueNode* location;
	location = front;
	std::cout << "Queue Contents: ";
	do
	{
		location = location->prev;
		if (location->item != -1)
			std::cout << location->item << " ";
		
	}while(location != front);
	
	std::cout << "\n\n";
	
}
	
