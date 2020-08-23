/**************************
// Author: Hailey Wilder, ID: 932-952-670
// Date: 10/4/16
// Description: Average 5 numbers given by user and return the result.
***************************/
#include <iostream>
using namespace std;

int main()
{
	double in1, in2, in3, in4, in5, avg;
	
	//request from the user, values to be averaged
	cout << "Please provide 5 numbers:\n";
	cin >> in1;
	cin >> in2;
	cin >> in3;
	cin >> in4;
	cin >> in5;
	
	//average numbers
	avg = (in1 + in2 + in3 + in4 + in5)/5;
	
	//return result
	cout << "\n" << "The average of these numbers is: " << "\n" << avg << endl;
	//program end
	return 0;	
}
