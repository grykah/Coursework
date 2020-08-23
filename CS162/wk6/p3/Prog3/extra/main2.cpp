/*********************************************************************
** Program Filename: main.cpp
** Author: Hailey Wilder
** Date: 2/19/17
** Description: This program serves as a testing driver for the
**              Creature and derived classes as well as the gameplay
**              functionality provided by the CombatRunner class. The
**              program prompts the user for how many Creatures will
**              be on each team's lineup and which character types
**              they want.
*********************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "CombatRunner.hpp"

#include "Queue.hpp"    // for storing Creature lineups

#include "utilities.hpp"    // for input validation

#include <cstdlib>      // for NULL
#include <iostream>     // for std::cout, std::cin
#include <vector>       // for std::vector


Creature* make_creature(char c);
void display_menu();


int main()
{
    // min and max creatures per side
    const int MIN_CRTS = 2;
    const int MAX_CRTS = 20;

    // lineup containers
    Queue team1;
    Queue team2;

    std::cout << "Welcome to the Dungeon Tournament!  Help us assemble " <<
                 "the lineups.\n";
    std::cout << "How many creatures will be on each team?\n";
    int num = utilities::get_valid_int_in_range(MIN_CRTS, MAX_CRTS);

    // selection var
    char c = '\0';

    // store pointer to Creatures in these vectors as well
    // so the memory can be freed later
    std::vector<Creature*> vector1;
    std::vector<Creature*> vector2;

    std::cout << "What should Player 1's lineup be?\n";
    display_menu();
    // let the user select all the Creature types
    for (int i = 0; i < num; ++i)
    {
        c = '\0';
        // only accept valid chars
        while (!(c == 'p' || c == 'r' || c == 'm' || c == 'b' || c == 'v'))
           c = std::cin.get();

        // load up the lineup and vector
        vector1.push_back(make_creature(c));
        team1.add(vector1[i]);
    }

    std::cout << "What should Player 2's lineup be?\n";
    display_menu();
    for (int i = 0; i < num; ++i)
    {
        c = '\0';
        while (!(c == 'p' || c == 'r' || c == 'm' || c == 'b' || c == 'v'))
           c = std::cin.get();

        vector2.push_back(make_creature(c));
        team2.add(vector2[i]);
    }

    // build the combat arena and start the tournament
    // printing of results happens in here
    CombatRunner cr(&team1, &team2);
    cr.print_outcome();

    // delete all the Creatures on the heap
    for (int i = 0; i < num; ++i)
    {
        delete vector1[i];
        delete vector2[i];
    }

    return 0;
}


/*********************************************************************
** Function: make_creature()
** Description: Prints the character selection options for the user.
** Parameters: c    a character representing the type of Creature
**                  to returned via pointer
** Pre-Conditions: c must be either 'hp', 'b', 'm', 'bm', or 'v'
** Post-Conditions: Returns a pointer to a new Creature object of
**                  one of the five derived true types
*********************************************************************/

Creature* make_creature(char c)
{
    switch (c)
    {
        case 'p': return new HarryPotter;
        case 'r': return new Barbarian;
        case 'm': return new Medusa;
        case 'b': return new BlueMen;
        case 'v': return new Vampire;
    }

    // error, invalid user choice
    return NULL;
}


/*********************************************************************
** Function: display_menu()
** Description: Prints the character selection options for the user.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void display_menu()
{
    std::cout << "For each creature, please enter the corresponding " <<
                 "letter.\n" <<
                 " p = HarryPotter\n" <<
                 " r = Barbarian\n" <<
                 " m = Medusa\n" <<
                 " b = Blue Men\n" <<
                 " v = Vampire\n\n";
}
