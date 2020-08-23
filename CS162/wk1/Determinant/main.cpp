/************************************************************************
** Program: main.cpp
** Author: Hailey Wilder
** Description: main using the readMatrix and determinant as specified 
** 				in programming requirements 
************************************************************************/
#include <iostream>
#include "readMatrix.h"				//calls readMatrix 
#include "determinant.h"			//calls determinant

int main()
{
	int selection;					//later used to select the 2 or 3 matrix
	int rows = 0;
	int cols = 0;
	int determinantValue = 0;
	
	std::cout << "\n**Determinant Calculator** \n";
	std::cout << "Matrix type:\n 1. \"2x2\"\n 2. \"3x3\"\n" << std::endl; 
	std::cin >> selection; 			//takes user selection 

	if (selection == 1)
	{
		rows = 2;
		cols = 2;
		
	}
	
	else if (selection == 2)
	{
		rows = 3;
		cols = 3;
	}
	
	else 
	{
		std::cout << "Not recognized, please try later." << std::endl;
		return 0;					//exits the program
	}
	
	int **arr; 						//to pointers
	arr = new int *[rows];			//create rows array
	for (int i = 0; i < rows; i++)  //create columns
		arr[i] = new int [cols];    //points to a single array of colunms
		
	readMatrix (arr, rows);			//calls the readmatrix function 
		
	std::cout << "\nRESULTS\nYou Entered: \n";
	
	int detArr [3][3];//create another array + copy original array + avoid unwanted modification
			
	for(int x = 0; x < rows; x++)  	// loop 3 times for three rows
		{
			std::cout << "Row " << x << ": ";
			for(int y=0; y < rows; y++)  // loop for the three columns
			{
				std::cout << arr[x][y] << " ";  // display the current element out of the array
				detArr [x][y] = arr[x][y];
			}
			std::cout << std::endl;  //when the inner loop is done, go to a new line
		}
			
	determinantValue = determinant (detArr, rows);//calculates the determinant
	std::cout << "\nDeterminant = " << determinantValue << "\n";
	
	return 0;
}