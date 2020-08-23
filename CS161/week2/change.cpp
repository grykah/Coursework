/**************************
// Author: Hailey Wilder, ID: 932-952-670
// Date: 10/4/16
// Description: Determine the amount of total for a user provide denomination (provided in cents).
***************************/
#include <iostream>
#include <math.h>  
using namespace std;

int main() 
{
    //get user input on amount of change
    double total; 	
	cout << "Please enter an amount in cents less than a dollar." << endl;
    cin >>total;
    
	//calculate the number of each coin
    int quarters = total/25;
    int dimes = (total - 25*quarters)/10;
    int nickels = (total - 25*quarters - 10*dimes)/5;
    int pennies = (total - 25*quarters - 10*dimes - 5*nickels)/1;
    
	//return the result to user
	cout << "Your change will be:" << endl;
    cout <<"Q: " << quarters << endl;
    cout <<"D: " << dimes << endl;
    cout <<"N: " << nickels << endl;
    cout <<"P: " << pennies << endl;

    return 0;
}
