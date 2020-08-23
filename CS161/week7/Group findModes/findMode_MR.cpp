/*********************************************************************
** Author: Michael Ross
** Date: 11-2-16
** Description: Assignment 7 - findMode function. A function that 
		identifies the mode (or modes) from an integer set and 
		returns the result.
*********************************************************************/

#include <vector>
#include <algorithm>
using namespace std;

/***************************************************************
  *						  findMode							  *
  *  Takes an array of integers as an input.  Returns a		  *
  *  result vector containing the mode value(s) from the	  *
  *  input set, sorted in ascending order.					  *
****************************************************************/

vector<int> findMode(int numbers[], int size)
{
	int highestFrequency = 0;
	int index = 0;
	vector<int> results;
	
	// First loop: determine what the highest frequency is
	for (int i = 0; i < size; i++)
	{
		int currentValue = numbers[i];
		int currentFrequency = 0;
		
		for (int j = 0; j < size; j++)
		{
			if (numbers[j] == currentValue)
			{
				currentFrequency++;
			}
			
			if (currentFrequency > highestFrequency)
			{
				highestFrequency = currentFrequency;
			}
		}
	}
	
	// Second loop: identify numbers in the array that have the max frequency
	for (int i = 0; i < size; i++)
	{
		int currentValue = numbers[i];
		int currentFrequency = 0;
		
		for (int j = 0; j < size; j++)
		{
			if (numbers[j] == currentValue)
			{
				currentFrequency++;
			}
		}
		
		// If this is a mode number, check if it already exists in 
		// the results vector
		if (currentFrequency == highestFrequency)
		{
			bool isDuplicate = false;

			for (int k = 0; k < results.size(); k++)
			{
				if (numbers[i] == results.at(k))
				{
					isDuplicate = true;
				}
			}

			// If the mode is not in the results vector, push it 
			// into the vector
			if (!isDuplicate)
			{
				results.push_back(numbers[i]);
			}
		}
	}
	
	// Sort the results vector in ascending order
	std::sort(results.begin(), results.end());

	return results;
}