/**********************************************************
** Author: Hailey Wilder
** Date: 10/11/16
** Description: Determines the max and min values of all those given by user
**********************************************************/

#include <iostream> 

using std::cin;
using std::cout;
using std::endl;

int main() {

  int curValue,   // stores latest int
      minNum,   // min value
      maxNum,   // max value
      usrInts;  // number of ints user to enter

  // request number of ints user will enter
  cout << "How many integers would you like to enter?" << endl;
  cin >> usrInts;

  //  if user enters greater >= 1
  if (usrInts > 0) {
    
    // then prompt for the ints
    cout << "Please enter " << usrInts
         << (usrInts > 1 ? " integers." : " integer.") << endl;

    // loop over usrInts get all the ints
    for (int i = 0; i < usrInts; i++) {
      cin >> curValue;
      // assign first int value to min and max (to initialize)
      if (i == 0) {
        minNum = maxNum = curValue;
      }
      // min/max initialized previously, so 
      // compare with most recently ints &
      // update values as required
      else {
        if (curValue < minNum) {
          minNum = curValue;
        } else if (curValue > maxNum) {
          maxNum = curValue;
        }
      }
    }

    // return results
    cout << "min: " << minNum << endl
         << "max: " << maxNum << endl;
  }

  return 0;
}