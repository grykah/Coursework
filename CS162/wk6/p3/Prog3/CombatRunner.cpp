/*********************************************************************
** Program Filename: CombatRunner.cpp
** Author: Hailey Wilder
** Date: 2/19/15
** Description: Contains the implementation of the CombatRunner class
**              member functions.
*********************************************************************/

#include "CombatRunner.hpp"
#include <iostream>


/*********************************************************************
** Function: CombatRunner::CombatRunner()
** Description: Constructs a CombatRunner from two pointers to
**              Creature objects and a desired number of battles
**              between those Creatures.
** Parameters: p1           pointer to the first Creature
**             p2           pointer to the second Creature
**             num_sims     number of battles
** Pre-Conditions: p1 and p2 are not null, num_sims > 0
** Post-Conditions: all instance fields initialized
*********************************************************************/

CombatRunner::CombatRunner(Creature *p1, Creature *p2, int num_sims)
{
    this->p1 = p1;
    this->p2 = p2;
    this->total_sims = num_sims;

    // we're on the first simulated battle
    this->cur_sim = 1;
}


/*********************************************************************
** Function: CombatRunner::run_simulation()
** Description: Plays a single combat battle between p1 and p2.  If
**              P1 wins, returns true.  Otherwise, returns false.
** Parameters: none
** Pre-Conditions: p1 and p2 are not null, total_sims > 0
** Post-Conditions: a bool indicating the winner is returned,
**                  both Creatures are restored to their initial
**                  states
*********************************************************************/

bool CombatRunner::run_simulation()
{
    bool p1_hp = false;
    bool p2_hp = false;

    if (p1->get_name() == "HarryPotter")
        p1_hp = true;
    if (p2->get_name() == "HarryPotter")
        p2_hp = true;

    bool p1_special_cut = false;
    bool p2_special_cut = false;

    // each iteration is a turn
    while (true)
    {
        // determine whether p1 has cut opponent's special attack/defense
        if (p1_hp)
			p1_special_cut = (dynamic_cast<HarryPotter*>(p1))->get_special();
			//p1_special_cut = (dynamic_cast<Medusa*>(p1))->get_special();
		

        // determine whether p2 has cut opponent's special attack/defense
        if (p2_hp)
			p2_special_cut = (dynamic_cast<HarryPotter*>(p2))->get_special();
			//p2_special_cut = (dynamic_cast<Medusa*>(p2))->get_special();

        // player 1 attacks player 2
        int p1_attack = p1->attack();
        int p2_defense = p2->defend();

        // apply damage

        // if opponent is a hp, cancel out the special attack/defense cut
        if (p1_hp && p2_special_cut)
            p2->take_damage(p1_attack * 2, p2_defense);
        else
            p2->take_damage(p1_attack, p2_defense);

        if (p2->is_dead())
        {
            // restore stats and special abilities for next round
            p1->revive();
            p2->revive();

            return P1_WON;
        }

        // player 2 attacks player 1
        int p2_attack = p2->attack();
        int p1_defense = p1->defend();

        // apply damage

        // if opponent is a hp, cancel out the special attack/defense cut
        if (p2_hp && p1_special_cut)
            p1->take_damage(p2_attack * 2, p1_defense);
        else
            p1->take_damage(p2_attack, p1_defense);
        
        if (p1->is_dead())
        {
            // restore stats and special abilities for next round
            p1->revive();
            p2->revive();

            return P2_WON;
        }
    }
}


/*********************************************************************
** Function: CombatRunner::get_result()
** Description: Plays total_sims simulated battles between p1 and p2,
**              then returns the number of battles p1 won.
** Parameters: none
** Pre-Conditions: p1 and p2 are not null, total_sims > 0
** Post-Conditions: cur_sim = total_sims + 1, returns the number of
**                  battles won by p1
*********************************************************************/

int CombatRunner::get_result()
{
    int p1_num_wins = 0;

    // run all the simulations
    while (cur_sim <= total_sims)
    {
        // each time p1 wins, tally it
        if (run_simulation() == P1_WON)
            ++p1_num_wins;

        // onto the next simulation
        ++cur_sim;
    }

    return p1_num_wins;
}