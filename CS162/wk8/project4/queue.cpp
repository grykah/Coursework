/*********************************************************************
** File Name: queue.cpp
** Author: Hailey Wilder
** Description: queue.cpp is the implementation file for queue.hpp 
*********************************************************************/
#include <iostream>
#include <vector>
#include "queue.hpp"
#include "Creature.hpp"
#include "structure.hpp"

/*********************************************************************
** Function: ~Queue()
** Description: releases memory not used anymore 
** Parameters: None
*********************************************************************/
Queue::~Queue()
{
	Node *nodePtr = head;
	while(nodePtr != NULL)
	{
		Node *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

/*********************************************************************
** Function: add()
** Description: addes a crature object to the queue
** Parameters: Pointer to a crature object
*********************************************************************/
void Queue::add(Creature *c)
{
	Node *nodePtr = tail;
	tail = new Node(c);

	if(head == NULL)
		head = tail;
	else
		nodePtr->next = tail;

	size += 1;
}

/*********************************************************************
** Function: getSize()
** Description: returns the number of objects in the queue
** Parameters: none
*********************************************************************/
int Queue::getSize()
{
	return size;
}

/*********************************************************************
** Function: remove()
** Description: removes a creature object from the queue
** Parameters: none
*********************************************************************/
Creature* Queue::remove()
{
	size -= 1;
	return Structure::remove();
}

/*********************************************************************
** Function: sorts()
** Description: sorts cratures objects in the queue from least to 
** highest. 
** Parameters: none
*********************************************************************/
void Queue::sort()
{
    std::vector <Creature*> fighters;
    int start, minIndex, minValue;
    
    //Add all fighters to a vector
    while(!isEmpty())
        fighters.push_back(Queue::remove());
    
    //Start sort
    for(start = 0; start < (fighters.size() - 1); start++)
    {
        minIndex = start;
        minValue = fighters.at(start)->getStrengthPoints();
        
        for(int i = start + 1; i < fighters.size(); i++)
        {
            if(fighters.at(i)->getStrengthPoints() < minValue)
            {
                minValue = fighters.at(i)->getStrengthPoints();
                minIndex = i;
            }
        }
        Creature *temp = fighters.at(minIndex);
        fighters.at(minIndex) = fighters.at(start);
        fighters.at(start) = temp;
    }
    
    //Put al fighters back into Queue
    for(int i = 0; i < fighters.size(); i++)
        Queue::add(fighters.at(i));
}
