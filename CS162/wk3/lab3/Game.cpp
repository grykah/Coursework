/*********************************************************************
 ** Program Filename: Game.cpp
 ** Author: Hailey Wilder
 ** Date: 1/29/17
 ** Description: This is the Game class implementation file.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#include "Game.h"
#include "Die.h"
#include "LoadedDie.h"

/*********************************************************************
 ** Function: Game::Game()
 ** Description: The constructor for a new Game.  rounds and sides 
 **				 must be greater than 0 when a new game is created.
 ** Parameters: rounds_to_play  number of rounds
 **             num_dice_sides  number of sides per Die
 **             p1_loaded       true if Player 1 uses a LoadedDie
 **             p2_loaded       true if Player 2 uses a LoadedDie
 *********************************************************************/

Game::Game(int rounds_to_play, int num_dice_sides,
        bool p1_loaded, bool p2_loaded) :
    max_rounds(rounds_to_play)
{
    round = 1;
    score_p1 = score_p2 = 0;

    p1 = p1_loaded ? new LoadedDie(num_dice_sides) : 
                     new Die(num_dice_sides);
    p2 = p2_loaded ? new LoadedDie(num_dice_sides) :
                     new Die(num_dice_sides);

}


/*********************************************************************
 ** Function: Game::~Game()
 ** Description: Destructs the game, freeing the memory used by the Die
 **              pointers.  Players are removed from memory.
 ** Parameters: none
 *********************************************************************/

Game::~Game()
{
    delete p1;
    delete p2;
}


/*********************************************************************
 ** Function: Game::play_round()
 ** Description: Plays a single round of the Game, printing out the
 **              value of each player's roll and the new scores of the
 **              two players. Round is incremented and scores printed.
 **				 srand() gets run here.
 ** Parameters: none
 *********************************************************************/

void Game::play_round()
{
    std::cout << "Round " << round << ":\n\tPlayer 1: ";

    int roll_p1 = p1->die_roll();
    std::cout << "\tPlayer 2: ";
    int roll_p2 = p2->die_roll();

    std::cout << "\n";

    if (roll_p1 > roll_p2)
        ++score_p1;
    else if (roll_p1 < roll_p2)
        ++score_p2;

    std::cout << "Player 1 score: " << score_p1 << '\t' <<
                 "Player 2 score: " << score_p2 << '\n';

    ++round;
}


/*********************************************************************
 ** Function: Game::play_game()
 ** Description: Plays an entire game with max_round rounds, printing
 **              the resulting scores of each player every round, and
 **              noting the winner after all rounds are done. srand()
 ** 			 must be run first.  Game is played here and results
 **				 captured.
 ** Parameters: none
 *********************************************************************/

void Game::play_game()
{
    std::cout << "Starting new game.\n\n";

    while (round <= max_rounds)
        play_round();

    print_game_result();
}


/*********************************************************************
 ** Function: Game::print_game_result()
 ** Description: Prints the final result of this Game. rounds = max_rounds
 ** 			 + 1.  Result printed as win or draw.
 ** Parameters: none
 *********************************************************************/

void Game::print_game_result()
{
    std::cout << "Result: ";
    if (score_p1 > score_p2)
        std::cout << "Player 1 wins!\n";
    else if (score_p1 < score_p2)
        std::cout << "Player 2 wins!\n";
    else
        std::cout << "It's a draw!\n";
}