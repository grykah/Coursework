/*********************************************************************
** File Name: stack.cpp
** Author: Hailey Wilder
** Description: stack.cpp is the implementation file for stack.hpp 
*********************************************************************/
#include <iostream>
#include "stack.hpp"
#include "structure.hpp"
#include "Creature.hpp"

/*********************************************************************
** Function: ~Stack()
** Description: releases memory not used anymore 
** Parameters: None
*********************************************************************/
Stack::~Stack()
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
** Description: adds creature object on top of the stack.
** Parameters: Creature pointer oject
*********************************************************************/
void Stack::add(Creature *player)
{
	if(head == NULL)
		head = new Node(player);
	else
	{
		Node *nodePtr = head;
		head = new Node(player);
		head->next = nodePtr;
	}
}
