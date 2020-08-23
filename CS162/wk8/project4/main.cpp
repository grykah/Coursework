/**************************************************************************************
** Program Filename: main.cpp
** Author: Hailey Wilder
** Description: main.cpp is tournament fighting game between two players that choose 
** thier own creature lineup teams. This is Assignment 4 - Containers. 
***************************************************************************************/
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Dice.hpp"
#include "queue.hpp"
#include "stack.hpp"

int main()
{
	int numCreatures;
	int round = 1;
	int creatureChoice;
	std::string customName;
	int player1Pts = 0;
	int player2Pts = 0;
	int choice;
	
	Queue player1;
	Queue player2;
	Stack losers;
	Creature *fighter;
	Creature *player1Fighter;
	Creature *player2Fighter;
	
	std::cout << "\n*****Welcome to Assignment 4: Creatures Tournament Game!*****\n" << std::endl;
	
	std::cout << "How many Creatures will each player use? ";
	std::cin >> numCreatures;
	// validate the input
	while (numCreatures <= 0 || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(256, '\n'); // Adding cin.ignore() to the next line clears / ignores the newline from the stream.
		std::cout << "Invalid input! Please enter a whole number: " << std::endl;
		std::cin >> numCreatures;
	}

	for (int a = 0; a < 2; a++) // max of two for loops since there is only two player by default
	{
		for (int x = 0; x < numCreatures; x++) // the number of for loops depends on the numbers of ceatures each player will use
		{
			std::cout << "\nPlayer " << a+1 << ": Choose your Creatures lineup! (creature " << x+1 << ")\n";
			
			std::cout << "1. Medusa\n";
			std::cout << "2. Barbarian\n";
			std::cout << "3. Vampire\n";
			std::cout << "4. Blue Men\n";
			std::cout << "5. Harry Potter\n";
			std::cout << "Choice: ";
			std::cin >> creatureChoice;
			//checks the input to see if it is valid selection
			while (creatureChoice < 1 || creatureChoice > 5 || std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(256, '\n'); // Adding cin.ignore() to the next line clears / ignores the newline from the stream.
				std::cout << "Invalid  Selection! Choose an option from the menu above i.e. <1> for Medusa." << std::endl;
				std::cout << "Choice: ";
				std::cin >> creatureChoice;
			}
			std::cout << "Enter a custom name for the creature: ";
			std::cin >> customName;
			
			if(creatureChoice == 1)
				fighter = new Medusa(customName, a+1); // passes the name and team number to the data type constructor
			else if(creatureChoice == 2)
				fighter = new Barbarian(customName, a+1); // passes the name and team number to the data type constructor
			else if(creatureChoice == 3)
				fighter = new Vampire(customName, a+1); // passes the name and team number to the data type constructor
			else if(creatureChoice == 4)
				fighter = new BlueMen(customName, a+1); // passes the name and team number to the data type constructor
			else if(creatureChoice == 5)
				fighter = new HarryPotter(customName, a+1); // passes the name and team number to the data type constructor

			// add the creature to players one queue list which depends on variable a
			if(a == 0)
				player1.add(fighter);
			else
				player2.add(fighter);
		}
	}

	std::cout << "\n**********LET'S START THE TOURNAMENT!!!!**********" << std::endl;
	
	 while(player1.getSize() > 0 && player2.getSize() > 0) // makes sure that each player has at least one character to continue fighting
	{
		player1Fighter = player1.remove(); // remove first creature from player1 queue
		player2Fighter = player2.remove(); // remove first creature from player2 queue
		std::cout <<"\n*****" << player1Fighter->getName() << " VS " << player2Fighter->getName() << "!!!!*****\n"; 
		std::cin.ignore();
		while (player1Fighter->isAlive() && player2Fighter->isAlive()) // creatures keep fighting until one does not have any more strength points
		{
			std::cout << "\nRound " << round << std::endl;
		
			if (player1Fighter->isAlive()) // if player 1's creature is alive it can attack
			{
				std::cout << player1Fighter->getName() << " attacks " << player2Fighter->getName() << "!" << std::endl;
				player1Fighter->Attack (player2Fighter);
			}
			
			if (player2Fighter->isAlive()) // if player 2's creature is alive it can attack
			{
				std::cout << player2Fighter->getName() << " attacks " << player1Fighter->getName() << "!" << std::endl;
				player2Fighter->Attack (player1Fighter);
			}
			round++;
			std::cout << "Press Enter to continue. " << std::endl;
			
			std::cin.get();
		}
			std::cout <<"Player 1 " << player1Fighter->getName() << " Life Meter: " << player1Fighter->getStrengthPoints() << std::endl;
			std::cout <<"Player 2 " << player2Fighter->getName() << " Life Meter: " << player2Fighter->getStrengthPoints() << std::endl;
			
			if (player1Fighter->getStrengthPoints() > player2Fighter->getStrengthPoints()) // if player 1 has more strength points player 1 wins this round
			{
				std::cout << player1Fighter->getName() << " is the winner!!!" << std::endl;
				std::cout << player2Fighter->getName() << " has died!!!" << std::endl;
				player1Fighter->heal(); // give a little strength power to the winner
				player1.add(player1Fighter); // add the winner back to the queue for future fights
				losers.add(player2Fighter); // add the loser to the stack
				player1Pts++;
				round = 0;
				std::cout << "Press Enter to continue. " << std::endl;
				std::cin.get();
			}
			else
			{
				std::cout << player2Fighter->getName() << " is the winner!!!" << std::endl; // else player 2 has more strength points and wins this round
				std::cout << player1Fighter->getName() << " has died!!!" << std::endl;
				player2Fighter->heal(); // give a little strength power to the winner
				player2.add(player2Fighter); // add the winner back to the queue for future fights
				losers.add(player1Fighter); // add the loser to the stack
				player2Pts++;
				round = 1;
				std::cout << "Press Enter to continue. " << std::endl;
				std::cin.get();
			}
	}
	
	// Now the tournamnet is over now do the statistics below
		
		if (player1.getSize() > 1)
			player1.sort(); // sort the remaining creatures from lowest to highest
		
		while(!player1.isEmpty()) // add the rest of the creatures to the loser location
			losers.add(player1.remove());
		
		if (player2.getSize() > 1)
			player2.sort(); // sort the remaining creatures from lowest to highest
		
		while(!player2.isEmpty()) // add the rest of the creatures to the loser location
			losers.add(player2.remove());
		
		// Statistics: first, second, and third places
		std::cout << "\nSCORES: \n";
		std::cout << "First Place: ";
		Creature *winner = losers.remove(); // remove the losers and display them in the next step
		int strengthPoints = winner->getStrengthPoints();
		if(strengthPoints < 0)
			strengthPoints = 0;
		std::cout << winner->getName() << " (Strength Points = " << strengthPoints << ", from Team " << winner->getTeam() << ")\n";
		// second places
		std::cout << "Second Place: ";
		winner = losers.remove();
		strengthPoints = winner->getStrengthPoints();
		if(strengthPoints < 0)
        strengthPoints = 0;
		std::cout << winner->getName() << " (Strength Points = " << strengthPoints << ", from Team " << winner->getTeam() << ")\n";
		// Third place
		if(!losers.isEmpty())
		{
			std::cout << "Third Place: ";
			winner = losers.remove();
			strengthPoints = winner->getStrengthPoints();
			if(strengthPoints < 0)
			strengthPoints = 0;
			std::cout << winner->getName() << " (Strength Points = " << strengthPoints << ", from Team " << winner->getTeam() << ")\n";
		}
		
		// Output the winning team
		std::cout << "\nTeam 1 scored " << player1Pts << " points\n";
		std::cout << "Team 2 scored " << player2Pts << " points\n";
		
		// Determine the winning team
		if(player1Pts > player2Pts)
			std::cout << "TEAM 1 WINS!!!!\n\n";
		else if(player2Pts > player1Pts)
			std:: cout << "TEAM 2 WINS!!!!\n\n";
		else if(player1Pts == player2Pts)
			std::cout << "GAME IS A TIE!!!!\n\n";
    
	
	return 0;
}

