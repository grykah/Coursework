/*********************************************************************
 ** Program Filename: LoadedDie.cpp
 ** Author: Hailey Wilder
 ** Date: 1/29/17
 ** Description: LoadedDie class implementation file.
 ** Input: n/a
 ** Output: n/a
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LoadedDie.h"  // hw updated

/*********************************************************************
 ** Function: LoadedDie()
 ** Description: 
 ** Parameters: num_sides
 *********************************************************************/
LoadedDie::LoadedDie(int y) : Die(y) // hw updated
{
}

/*********************************************************************
 ** Function: set_sides()
 ** Description: Sets die sides
 ** Parameters: num_sides
 *********************************************************************/
void LoadedDie::set_sides(int y)   // hw updated
{
	num_sides = y;  // hw updated
	cout<<"there are this many sides on the die "<< num_sides<<endl; // hw updated

}

/*********************************************************************
 ** Function: die_roll()
 ** Description: Gives die loaded rolls
 ** Parameters: none
 *********************************************************************/
int LoadedDie::die_roll()    // hw updated
{
	if (rand() % 2 ==0)
		{	
			int t =0;
			t=rand() % 4 + 3;
			cout<<"the loaded roll was "<< t <<endl;
			return t;
			
			

		 	
		}
	
	else{
			int h=0;
			h=rand() % num_sides + 1; // hw updated loaded_sides
                                                  // to num_sides
			cout<<"the loaded roll was "<<h<<endl;
			return h;
		}
}