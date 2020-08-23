/********************************************************************************************
** Program: Queue.hpp
** Author: Hailey Wilder
** Date: 02/21/2017
** Description: This program implements an abstract data type using linked structures. 
*********************************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
    private:
        struct QueueNode
        {
            public:
		// item will hold the integer value
                int item;
                // points to the node to the right
                QueueNode *next;
                // points to the node to the left
                QueueNode *prev;
        };
        
        // front points to the front of the queue
        QueueNode *front;
        // back points to the back of the queue
        QueueNode *back;
        
    public:
        Queue(); // Consructor
        ~Queue(); // destructor

        void addBack(int item); // inserts new node with item
        int getFront(); // returns the front node
        int removeFront(); // basically just sets the node to -1 and returns the node
	void printFrontElement(); // prints the front element in the queue
	void displayStackContents(); // traveres the linked list to display the integers
};

#endif
