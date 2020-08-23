/*********************************************************************
** Program: Queue.cpp
** Author: Hailey Wilder
** Description: Queue.cpp is the implemntation file for Queue class.
*********************************************************************/
#include <queue>
#include <iostream>
#include "Queue.hpp"

/*********************************************************************
** Function: Queue()
** Description: The constructor that sets count and sum.
** Parameters: None
*********************************************************************/ 
Queue::Queue()
{	
	count = 1;
	sum = 0;
}

/*********************************************************************
** Function: simulate()
** Description: calculates the buffer average during each turn.
** Parameters: int simS (turns), int chH(chances of adding), 
** int rmChH (chances or removing)
*********************************************************************/ 
void Queue::simulate(int simsS, int chH, int rmChH)
{
	Dice randomNum(100); // creates a 100 sided dice to roll number between 0-100
	for (int x = 0; x < simsS; x++)
	{
		std::cout << "**********Turn #: " << count << "**********\n";
		randomRoll = randomNum.rollDie(); // random number

		if (randomRoll <= chH) // push the number to the queue if random number is below chH
		{
			buffer.push(randomRoll); // adds item to queue
			sum += buffer.size(); // gets queue size
		}

		if (randomRoll <= rmChH) // pop the number from the queue if random number is below rmChH
		{
			if (!buffer.empty())
			{
				buffer.pop(); // removes item from queue
				sum += buffer.size(); // gets queue size
			}
		} 
		std::cout << "Buffer Average: " << sum/count << "\n";
		count++;
	}
}


