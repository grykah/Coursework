/**********************************************************
** Author: Hailey Wilder
** Date: 10/26/16
** Description: LineSegment.cpp is the LineSegment class
**              function implementation file.
**********************************************************/

#include "LineSegment.hpp"  // link to header file


/*********************************************************************
** Description: This constructor initializes the end1 and end2
**              class member variables to the values given by the
**              first and second parameters, respectively.
*********************************************************************/ 
LineSegment::LineSegment(Point first, Point second) {
  setEnd1(first);
  setEnd2(second);
}


Point LineSegment::getEnd1() {
  return end1;
}


Point LineSegment::getEnd2() {
  return end2;
}


/*********************************************************************
** Description: This function calculates the length of LineSegment.
** Parameter: Takes points and returns LineSegment.
*********************************************************************/ 
double LineSegment::length() {
  // call the distanceTo() function from the Point class
  return end1.distanceTo(end2);
}


void LineSegment::setEnd1(Point first) {
  end1 = first;
}


void LineSegment::setEnd2(Point second) {
  end2 = second;
}


/*********************************************************************
** Description: This function calculates the slope of
**              LineSegment.  If this object represents a
**              vertical line segment, returns inf or -inf.  If the
**              line is a point nan calculated. 
** Parameter: Takes none, returns slope. 
*********************************************************************/ 
double LineSegment::slope() {
  double x1 = end1.getXCoord(),
         x2 = end2.getXCoord(),
         y1 = end1.getYCoord(),
         y2 = end2.getYCoord();

  // use the standard slope formula
  return (y2 - y1) / (x2 - x1);
}