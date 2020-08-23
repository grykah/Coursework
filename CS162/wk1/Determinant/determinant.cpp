/************************************************************************************
** Program: determinant.cpp
** Author: Hailey Wilder
** Description: Find the determinant.
*************************************************************************************/
#include <iostream>
#include "determinant.h"

int determinant(int arr[][3], int sizeSq)
{
	int det = 0;
	
	if (sizeSq == 2)
	{
		det = ((arr[0][0])*(arr[1][1])) - ((arr[0][1])*(arr[1][0]));
	}
	
	else if (sizeSq == 3)
	{
		det = ((arr[0][0])*((arr[1][1])*(arr[2][2]) - (arr[1][2])*(arr[2][1]))) - 
		((arr[0][1])*((arr[1][0])*(arr[2][2]) - (arr[1][2])*(arr[2][0]))) +  
		((arr[0][2])*((arr[1][0])*(arr[2][1]) - (arr[1][1])*(arr[2][0])));
	}
	return det; 
};