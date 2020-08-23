/*********************************************************************
 ** Program Filename: LoadedDie.h
 ** Author: Hailey Wilder
 ** Date: 1/29/17
 ** Description: LoadedDie class definition file. Increases the probability 
 ** 			 of the high value rolls to create a "loaded die"
 ** Input: n/a
 ** Output: n/a
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Die.h" // hw updated

#pragma once
using namespace std;

class LoadedDie: public Die   // hw updated
	{
		//int loaded_sides; // hw updated
	public:
                LoadedDie(int); // hw updated
		void set_sides(int);
		int die_roll(); // hw updated
	};