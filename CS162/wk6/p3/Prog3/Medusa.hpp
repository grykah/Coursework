/*********************************************************************
** Program Filename: Medusa.hpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the derived Medusa class definition and
**              member declarations.
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

class Medusa :
    public Creature
{
public:
    Medusa();
    virtual int attack();
    virtual int defend();
    virtual void revive();
};

#endif