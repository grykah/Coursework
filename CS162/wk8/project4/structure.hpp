/*************************************************************************
** File Name: structure.hpp
** Author: Hailey Wilder
** Description: structure.hpp is the implementation file for structure.hpp 
***************************************************************************/
#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP
#include <iostream>
#include "Creature.hpp"

class Structure
{
	protected:
		struct Node
		{
			Creature *player;
			Node *next;
			Node(Creature *p, Node *next1 = NULL)
			{
				player = p;
				next = next1;
			}
		};

		Node *head;

	public:
		virtual void add(Creature *player) = 0;
		virtual Creature* remove();
		bool isEmpty();
};

#endif
