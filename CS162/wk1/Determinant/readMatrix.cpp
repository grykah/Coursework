/*********************************************************************************
** Program: readMatrix.cpp
** Author: Hailey Wilder
** Description: implements readMatrix
**********************************************************************************/
#include <iostream>
#include "readMatrix.h"

void readMatrix(int **ar, int sizeSq)
{	//takes values until table is full, depending on matrix size
	for (int j = 0; j < sizeSq; j++)
		for (int i = 0; i < sizeSq; i++)
		{
			std::cout << "Enter value " << j << ": \n";
			std::cin >> ar[j][i];
		}
		
	return;
};