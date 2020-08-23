/************************************************************************************
** Program: visitor.h
** Author: Hailey Wilder
** Description: Visitor class definition 
*************************************************************************************/

#ifndef VISITOR_H_
#define VISITOR_H_
// for grid
class Visitor {
 public:
  virtual ~Visitor() {}
  virtual void Visit(class Grid *grid) = 0;
};

#endif  // VISITOR_H_