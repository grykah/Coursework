/***************************************************************************
* * Author: Robert Brempelis
* * Date: 11/9/16
* * Description: findMode takes int array and arry size and returns 
* *					vector with modes
***************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> findMode(int startNums[], int size)
{
	std::vector<int> modes;
	int previousNum, currentCount, maxCount;

	std::sort(startNums, startNums + size);

	previousNum = startNums[0];
	currentCount = 1;
	maxCount = 0;

	for(int m = 1; m < size; m++)
	{
		if (startNums[m] == previousNum)
		{
			currentCount++;
		}
		else
		{
			if (currentCount > maxCount)
			{
				maxCount = currentCount;
				currentCount = 0;
			}
		}
		previousNum = startNums[m];
	}

	previousNum = startNums[0];
	currentCount = 0;


	for(int n = 0; n < size; n++)
	{
		if (startNums[n] == previousNum)
		{
			currentCount++;
		}
		else
		{
			currentCount = 1;
			previousNum = startNums[n];
		}
		if (currentCount == maxCount)
		{
			modes.push_back(startNums[n]);
		}
				
	}

	return modes;
}


/*
int main()
{
	int array[] = { 10, 13, 1, 16, 17 };
	int size = 5;
	std::vector<int> val;

	val = findMode(array, size);

	for (int m = 0; m < val.size(); m++)
		std::cout << val[m] << std::endl;

	return 0;
}
*/