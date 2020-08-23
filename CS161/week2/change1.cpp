/**************************
// Author: Hailey Wilder, ID: 932-952-670
// Date: 10/4/16
// Description: Determine the amount of change for a user provide denomination (provided in cents).
***************************/
#include <iostream>
using namespace std;

int main()
{
	int cents;
	const Q, D, N, P;
	int temp, resQ, resD, resN, resP;
	
	// Get input from user.
	cout << "Please enter an amount in cents less than a dollar.";
	cin >> cents;
	
	//Determine the number of coins.
	temp = cents % Q;
	resQ = temp;
	temp = resQ % D;
	resD = temp;
	temp = resD % N;
	resN = temp;
	temp = resN % P;
	temp = resP;
	
	//Report result
	cout << "\n" << "Q" << "resQ" << "endl";
	cout << "\n" << "D" << "resD" << "endl";
	cout << "\n" << "N" << "resN" << "endl";
	cout << "\n" << "P" << "resP" << "endl";

	// program end
	return 0;	
}