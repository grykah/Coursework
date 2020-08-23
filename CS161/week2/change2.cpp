/**************************
// Author: Hailey Wilder, ID: 932-952-670
// Date: 10/4/16
// Description: Determine the amount of change for a user provide denomination (provided in cents).
***************************/
#include <iostream>
using namespace std;
#include <stdio.h>

#define DIM(array)        (sizeof(array)/sizeof(array[0]))

int makeChange(int *pAmount, int denomination)
{
    int ret = *pAmount / denomination;

    *pAmount -= ret * denomination;
    // print ret;
    //print pAmount;
    return ret;
}

int main(void)
{
    // declare float
    int money;
    //int remainingCents;
    int numCoins = 0;
    const int coinDenominations[] = { 25, 10, 5, 1 };
    const char* coinType[] = {"Q", "D", "N", "P"};

    // Get input from user.
    cout << "Please enter an amount in cents less than a dollar.";
    cin >> money;

    // Greedy Algorithm for Cents
    for (int i = 0;i < DIM(coinDenominations);i++)
        numCoins += makeChange(&money, coinDenominations[i]);

    //for (auto i = path.begin(); i != path.end(); i++)
      //cout << coinType[i] << "\n" << ret[i] << endl;

    for (int i = 0; i < DIM(coinDenominations);i++)
        for (int j = 0; j<DIM(coinType); j++)
            cout << printf(coinType[i] << ": " << coinDenominations[i]);

    cout << "The least possible steps used to make change is: " << numCoins;

    return 0;
}
