/**************************
// Author: Hailey Wilder, ID: 932-952-670
// Date: 10/4/16
// Description: Convert temperature from Celsius to Fahrenheit.
***************************/
#include <iostream>
using namespace std;

int main()
{
	float cel, fah;
	
	//get input from user
	cout << "Enter temperature (C): " << "\n";
	cin >> cel;
	
	//convert from C to F
	fah = ((static_cast<double>(9)/5) * cel) + 32;
	
	//return result
	cout << "\n" << "The temperature in Fahrenheit is : " << "\n" << fah << endl;

	// program end
	return 0;	
}
