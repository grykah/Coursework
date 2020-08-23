/**********************************************************
** Author: Hailey Wilder
** Date: 10/17/16
** Description: Sort 3 ints from low to high.
**********************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void smallSort(int &frst, int &scnd, int &thrd) {
  int tmp;  //temporary storage variable

  // switch the frst two numbers if they are out of order
  if (frst > scnd) {
    tmp = scnd;
    scnd = frst;
    frst = tmp;
  }

  // compare the resulting scnd number with the thrd number,
  // switch if necessary
  if (scnd > thrd) {
    tmp = thrd;
    thrd = scnd;
    scnd = tmp;

    // now compare the frst and resulting scnd number,
    // switch if necessary
    // all 3 pair comparisons have been done, so we're done
    if (frst > scnd) {
      tmp = scnd;
      scnd = frst;
      frst = tmp;
    }
  }
}

/*
// test of function declared above
int main() {
    int var1 = 10;
    int var2 = -8;
    int var3 = 5;
    smallSort(var1, var2, var3);
    cout << var1 << ", " << var2 << ", " << var3 << endl;

    return 0;
}
*/
