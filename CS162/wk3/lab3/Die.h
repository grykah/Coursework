/*********************************************************************
 ** Program Filename: Die.hpp
 ** Author: Hailey Wilder
 ** Date: 1/29/17
 ** Description: Die class specification file.  The die can be rolled 
 **				 to produce a any value between 1 and the number of sides. 
 ** 			 Each side has an equal probability of occurring from a roll. 
 ** Input: n/a
 ** Output: n/a
 *********************************************************************/

#ifndef DIE_H
#define DIE_H

class Die
{
    protected:
        // number of sides on Die and also the max value
        int num_sides;

    public:
        // constructor that takes the number of sides as a parameter
        Die(int sides);

        // virtual destructor
        virtual ~Die();

        // returns a value between 1 and the number of sides
        virtual int die_roll();
};

#endif