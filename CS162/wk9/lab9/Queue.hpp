/*****************************************************************************
** Program: Queue.hpp
** Author: Hailey Wilder
** Description: Queue.hpp is the spcification file header for the Queue class.
******************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <queue>
#include <iostream>
#include "Dice.hpp" // brings in the die lab I did earlier

class Queue 
{
	private:
	double count;
	int randomRoll;
	double sum;
	std::queue<int> buffer; // initialize a queue to push and pop values

	public:
	Queue (); // constructor
	void simulate(int, int, int);
};

#endif
