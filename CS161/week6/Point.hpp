/**********************************************************
** Author: Hailey Wilder
** Date: 10/26/16
** Description: Point.hpp is the Point class specification
**              file.
**
**              A Point is defined by two coordinates, both
**              double values, which determine its
**              location.  One Point object's distance from
**              another may be calculated.
**********************************************************/

#ifndef POINT_HPP
#define POINT_HPP

class Point {
  private:
    double xCoord,
           yCoord;
  public:
    Point();
    Point(double,double);
    double distanceTo(const Point&);
    double getXCoord();
    double getYCoord();
    void setXCoord(double);
    void setYCoord(double);
};

#endif