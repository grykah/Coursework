/**********************************************************
** Author: Hailey Wilder
** Date: 10/26/16
** Description: Main file for calling Point and LineSegment
** called geomMain.cpp
**********************************************************/

#include "LineSegment.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Point p1(-1.5, 0.0);
  Point p2(1.5, 4.0);
  LineSegment ls1(p1, p2);
  double length = ls1.length();
  double slope = ls1.slope();

  cout << "Point1: (" << p1.getXCoord() << ", "
       << p1.getYCoord() << ")" << endl;
  cout << "Point2: (" << p2.getXCoord() << ", "
       << p2.getYCoord() << ")" << endl;
  cout << "Length of Segment: " << length << endl;
  cout << "Slope of Segment: " << slope << endl;

  return 0;
}
