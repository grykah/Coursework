/**********************************************************************************************************************************************
Author: Andrew Schapper
Date: November 9, 2016
Description: This program takes in the desired amount of integers the user puts in and outputs the mode of that set of numbers. It will also sort the output in acsending order. 
***********************************************************************************************************************************************/
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>


using namespace std;

vector<int> GetMode(vector<int> inputValues)
{
	int count = 0;
	int maxNum = 0;
	int currentNumber = inputValues.at(0);

	// if the program gets to this point then it contains a mode so we should print one to the screen.
	cout << "Mode(s): " << endl;

	sort(inputValues.begin(), inputValues.end());
	
	// this is where we will sort the array
	vector<int> modes;

	for (int i = 0; i < inputValues.size(); i++)
	{

		if (currentNumber == inputValues.at(i))
		{
			count++;

			if (count > maxNum)
			{
				
				maxNum = count;
			}
		}
		else
		{
			if (count > maxNum)
			{
				maxNum = count;
			}
			currentNumber = inputValues.at(i);
			count = 1;
		}
	}

	count = 0;
	currentNumber = inputValues.at(0);

	//This is where we actually place values in our modes array
	for (int i = 0; i < inputValues.size(); i++)
	{
		if (currentNumber == inputValues.at(i))
		{
			count++;
			if (count == maxNum)
			{
				modes.push_back(currentNumber);
			}
		}
		else
		{
			currentNumber = inputValues.at(i);
			count = 1;

			//Handle maxNum of 1
			if (count == maxNum)
			{
				modes.push_back(currentNumber);
			}
		}
	}

	return modes;
}

//A function that makes sure that we have a valid integer in a string

bool SafeStoI(string input, int &convertedValue)
{
	char* stopVal;
	long userNumber = strtol(input.c_str(), &stopVal, 10);

	if (*stopVal != '\0')
	{
		cout << "Invalid integer." << endl;
		return false;
	}
	else if (userNumber > INT_MAX)
	{
		//Strtol is great, but we want to make sure that the number is in range
		cout << "number too big." << endl;
		return false;
	}
	else
	{
		convertedValue = static_cast<int>(userNumber);
		return true;
	}
}

/*
int main()
{
	vector<int> numbers;
	int numberCounter = 0;

	cout << "Enter integers to add them to the vector. When you are done, simply enter a blank line." << endl;
	do
	{
		string userInput;
		int numberToAppend;

		cout << "Number " << numberCounter << ": ";
		getline(cin, userInput);

		if (userInput.size() == 0)
		{
			break;
		}
		else

			if (SafeStoI(userInput, numberToAppend))
			{
				numbers.push_back(numberToAppend);
				numberCounter++;
			}
			else
			{
				continue;
			}
	}
	 while (true);

	if (numbers.size() > 0)
	{
		vector<int> modes = GetMode(numbers);

		for (int i = 0; i < modes.size(); i++)
		{
			cout << modes.at(i) << endl;
		}
	}
	else
	{
		cout << "No numbers entered. No mode calculated." << endl;
	}

	return 0;
}
*/