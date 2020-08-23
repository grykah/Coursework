/*********************************************************************************
** Program Filename: recursions.cpp
** Author: Hailey Wilder
** Description: recursions.cpp is the implementation file for recursions.hpp.
**********************************************************************************/
#include <iostream>
#include <string>
#include "recursions.hpp" // imports recursions header file

/********************************************************************************
 ** Function: stringReverse
 ** Description: reverses the string being passed as a parameter, and returns it 
 ** back as a string. 
 ********************************************************************************/
std::string stringReverse(std::string stringInput)
{
	// if only one character is being passed it returns it back since there is no need to reverse
	if (stringInput.length() == 1) // base case
	{
		return stringInput;
    	}	
	else
	{	
		return stringReverse(stringInput.substr(1,stringInput.length())) + stringInput.at(0); // recursive call. keeps removing the first character until it reaches the end. Then stringInput.at(0) will finish it up to display it backwards. 
		std::cout << "\n" << std::endl;
	/* Notes: stringInput.substr(p, n);  Returns a copy of a substring. The substring is n characters long and begins at position p of theString.
	stringInput.at(p); Returns the character at position p in the string.
	ex. edwin, dwin, win, in, niwde */
    	}
}

/********************************************************************************
 ** Function: arraySum
 ** Description: sums all the elements from the array it receives, and returns a
 ** sum. 
 ********************************************************************************/
int arraySum(int array[], int elements)
{
    if(elements <= 0) // base case
    {
        return 0;
    }

    else
    {
        return array[0] + arraySum(array + 1, elements-1); // recursive call
    }
}

/********************************************************************************
 ** Function: triangle
 ** Description: calculates the number of item in a triable based on the rows. 
 ********************************************************************************/
int triangle(int rows)
 {
     if (1 <= rows) // base case
           return (rows + triangle(rows-1));
 }