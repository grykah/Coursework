/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Hailey Wilder
 ** Date: 1/29/17
 ** Description: This program plays a Game using the Die and LoadedDie
 **              classes.
 ** Input: std::cin (use LoadedDie or Die and how many rounds)
 ** Output: std::cout (the Game output including final winner)
 *********************************************************************/

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // seed
    std::srand(std::time(0));

    std::cout << "Do you want Player 1 to use a loaded die? (y/n)\n";
    char c;
    std::cin >> c;
    bool p1_loaded = (c == 'y' || c == 'Y') ? true : false;
    std::cout << "Do you want Player 2 to use a loaded die? (y/n)\n";
    std::cin >> c;
    bool p2_loaded = (c == 'y' || c == 'Y') ? true : false;

    std::cout<< "How many sides should the die have? \n";
	int num_dice_sides;
	
	// wait to get valid input, clear invalid
	
	do
    {
		std::cin >> num_dice_sides;
        if (std::cin.fail())
        {
            std::cin.clear();
			std::cout << "Invalid input, try again.";  //hw not working
            std::cin.ignore(5000, '\n');
        }
    } while (num_dice_sides < 1);
		

	std::cout << "How many rounds should the game last? \n ";
    int rounds_to_play = -1;
	
    // wait to get valid input, clear invalid
	
    do
    {
		std::cin >> rounds_to_play;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(5000, '\n');
        }
    } while (rounds_to_play < 1);

    // build and run a game
    Game g(rounds_to_play, num_dice_sides, p1_loaded, p2_loaded);
    g.play_game();

    return 0;
}