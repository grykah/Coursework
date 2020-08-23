/**********************************************************
** Author: Hailey Wilder
** Date: 10/17/16
** Description: count iterations required to reach 1 from
**              an initial value given specific conditions.
**				conditions -- even: divide by 2,
**							  odd: multiply by 3 and +1
**********************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int hailstone(int initVal) {

  int count = 0;  // iterations so far

  // loop until the number = 1
  while (initVal != 1) {
    // if even, divide it by 2
    if (initVal % 2 == 0) {
      initVal /= 2;
    } else {
      // if odd, multiply it by 3 and add 1
      initVal = initVal * 3 + 1;
    }
    // increment the counter
    count++;
  }

  return count;
}

/*
//test of function declared above
int main() {

    cout << hailstone(3) << endl;
    cout << hailstone(2) << endl;
    cout << hailstone(10) << endl;

    return 0;
}
*/
