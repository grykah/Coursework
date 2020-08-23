/************************************************************************************
** Program: ant_visitor.h
** Author: Hailey Wilder
** Description: Ant header implementation
*************************************************************************************/

#ifndef ANT_VISITOR_H_
#define ANT_VISITOR_H_

#include <stdlib.h>

#include "visitor.h"

class AntVisitor : public Visitor { 
 public: // public class: steps and progress
  AntVisitor(int steps, int show_progress_step)
      : steps_(steps),
        show_progress_step_(show_progress_step),
        x_(0),
        y_(0),
        x_direction_(0),
        y_direction_(1) {}

  virtual void Visit(class Grid *grid);

 private: // private class: variables herein, direction, 
		  // coordinate updates, movement, and print
  int steps_, show_progress_step_,
      x_, y_, x_direction_, y_direction_,
      length_, width_;

  void Clear() const { system("clear"); }
  void Turn(int direction);
  int GetNewCoordinate(int coordinate, int direction, int limit);
  void MoveForward();
  void PrintCurrentState(Grid *grid, int iteration);
};

#endif  // ANT_VISITOR_H_