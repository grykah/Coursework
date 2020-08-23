/*********************************************************************
** Program Filename: Vampire.hpp
** Author: Hailey Wilder
** Date: 2/19/17
** Description: Contains the derived Vampire class definition and
**              member declarations.  Unlike the other derived
**              classes derived from Creature, this class has a
**              special ability that allows it to dodge attacks 50% of
**              the time.
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

class Vampire :
    public Creature
{
public:
    Vampire();
    virtual int attack();
    virtual int defend();
    virtual int take_damage(int attack, int defense);
    virtual void revive();
};

#endif