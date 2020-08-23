/********************************************************
** Program: main.cpp
** Author: Hailey Wilder
** Description: Final project - A text based game. 
********************************************************/
#include <iostream>
#include <cstdlib> // Library used to refresh screen
#include <unistd.h> // usleep () function
#include "Game.hpp" // brings in the Game.hpp specification file
#include "Room.hpp" // brings in the Room.hpp specifiation file

int main()
{
	int choice; //

    Game start; 
	system("clear"); // clear the screen
    std::cout << "========================FINAL PROJECT========================" << std::endl;
	std::cout << "\t\t**********Haunted House**********" << std::endl;  
	
	std::cout << "\t\tMM.:MM" << std::endl; 	
	std::cout << "\t\tMM.:MM" << std::endl; 	
	std::cout << "\t\tMM.:MM" << std::endl; 	
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh" << std::endl;            
    std::cout << "\t\thMMMMMMMMMM        MMMMMMMMMMMh" << std::endl;           
    std::cout << "\t\thMMMMMMMMMM        MMMMMMMMMMMh" << std::endl;           
    std::cout << "\t\thMMMMMMMMMM        MMMMMMMMMMMh" << std::endl;           
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh" << std::endl;         
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh" << std::endl;          
    std::cout << "\t\thMM       MMMMMMMMMM       MMMh" << std::endl; 
    std::cout << "\t\thMM       MMMMMMMMMM       MMMh" << std::endl;
    std::cout << "\t\thMM       MMMMMMMMMM       MMMh" << std::endl;	
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh" << std::endl;           
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh" << std::endl;          
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh" << std::endl;          
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh" << std::endl;          
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMM------MMMh" << std::endl;          
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMM------MMMh" << std::endl; 
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMM------MMMh" << std::endl; 
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMM-*----MMMh" << std::endl; 
    std::cout << "\t\thMMMMMMMMMMMMMMMMMMMM------MMMh" << std::endl; 	
       
               
	
	std::cout << "MAIN MENU" << std::endl;
	std::cout << "1. Enter the HAUNTED HOUSE (New Game)" << std::endl;
	std::cout << "2. EXIT" << std::endl;
	std::cout << "Selection: ";
	std::cin >> choice;
	while(std::cin.fail() || choice <= 0 || choice >= 3) // Makes sure that there is a valid input
	{
		std::cout << "Error, Selection:" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> choice;
	}
	
	// Clear the buffer
	std::cin.clear();
	std::cin.ignore(256,'\n');
	
	switch (choice)
	{
		case 1:
			system("clear"); // clear the screen
			std::cout << "Welcome to the Haunted House!" << std::endl;
			std::cout << "\nYou walk up to an house...\n" << std::endl;
			std::cout << "where you expect to find your first computer programming contract position! " 
					  << "Of course you were thrilled to have the opportunity to get some experience, " 
					  << "so you excepted the position despite having to go out into the countryside " 
					  << " to someone's house.  Now that you have arrived, it does seem a bit run down... " << std::endl;
			std::cout << "\nPress ENTER to CONTINUE\n";
			std::cin.get();
			std::cout << "But, hey, experience is experience, right?\n" << std::endl;
			std::cout << "Getting a post-bacc isn't cheap and paid experience is good experience! " 
					  << "You go up to the door, give a sturdy knock, and it creeeeaks open. " 
					  << "Well, that's strange.  You walk in and look around for signs of life or a computer. "
					  << "And, naturally, the door slams shut behind you. " 
					  << "You try to pull the handle, but some sort of security system has engaged... GREAT" << std::endl;
			std::cout << "\nPress ENTER to CONTINUE\n";
			std::cin.get();
			std::cout << "Spooky Voice: Heheheh!  Let's see you escape my haunted house now! " << std::endl;
			std::cout << "You'll have to search all my haunted rooms and find three of the house's secrets in order to escape. \n"; 
			std::cout << "\nPress ENTER to CONTINUE";
			std::cin.get();
			start.start();
			break;
		case 2:
			std::cout << "Good for you... Stay away from Haunted Houses!" << std::endl;
			return 0;
	}
    return 0;
}