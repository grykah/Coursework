/******************************************************
** Program: main.cpp
** Author: Hailey Wilder, Andrew Schapper, Eric Durboraw
** Date: 02/20/2017
** Description:
** Input:
** Output:
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int quit;
	while(quit != -1)
	{
		srand(time(0));
		
		int userNum;
		int randomNum;
		// player options
		cout << "1. Rock" << endl;
		cout << "2. Paper" << endl;
		cout << "3. Scissors" << endl;
		cout << "-1. End Game" << endl;
		
		cin >> userNum;
		cout << endl;
		
		randomNum = (rand()%3) + 1;
		// end game
		if(userNum == -1)
		{
			return 0;
		}
		// results of tie
		if(randomNum == userNum)
		{
			cout << "Tie, " << userNum << "!" << endl;
		}
		// results of rock, paper, or scissors battle
		if((randomNum == 1 && userNum == 2) || 
		  (randomNum == 3 && userNum == 1) ||
		  (randomNum == 2 && userNum == 3))
		{
			cout << "You Win!" << endl;
		}
		else
		{
			cout << "You Lose!" << endl;
		}
		// display of computer choice
		if(randomNum == 1)
		{ 
			cout << "Computer played Rock." << endl;
		}
		else if(randomNum == 2)
		{
			cout << "Computer played Paper." << endl;
		}
		else
		{
			cout << "Computer played Scissors." << endl;
		}

	}
	
	return 0;
}