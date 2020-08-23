/*********************************************************************
** Program Filename: HarryPotter.hpp
** Author: Hailey Wilder
** Date: 2/19/17
** Description: Contains the derived HarryPotter class definition and
**              member declarations.  Unlike the other derived
**              classes derived from Creature, this class has a
**              special ability where, if it rolls a total of 12
**              during an attack, it cuts the opponent's attack by 50%
**              for the rest of the combat session.
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class HarryPotter :
    public Creature
{
private:
    // true if the any specials 
    bool specials;

public:
    HarryPotter();
    virtual int attack();
    virtual int defend();
    virtual int take_damage(int attack, int defense);
    virtual void revive();
    bool get_special();
};

#endif
