/**********************************************************
** Author: Hailey Wilder
** Date: 10/17/16
** Description: Determine distance fallen given time falling.
**********************************************************/
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

double fallDistance(double fallTime) {

  const double G = 9.8;  // approximate of acceleration of gravity const.
  double dist;       // calculated dist object falls

  // use the formula d = (1/2)gt^2
  dist = 0.5 * G * fallTime * fallTime;

  return dist;
}

/*
// test of function declared above
double main()
{
   cout << fallDistance(3) << endl;

   return 0;
}
*/
