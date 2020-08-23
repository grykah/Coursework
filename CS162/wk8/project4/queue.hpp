/*********************************************************************
** File Name: queue.hpp
** Author: Hailey Wilder
** Description: queue.hpp is the specification file for queue.cpp 
*********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include "structure.hpp"
#include "Creature.hpp"

class Queue : public Structure // inherists from the Structure base class
{
	private:
		Node *tail;
		int size;

	public:
		Queue()
		{
			head = NULL;
			tail = NULL;
			size = 0;
		}

		~Queue();
		void add(Creature *c);
		int getSize();
		Creature* remove();
		void sort();
};

#endif
