/************************************************************************************
** Program: main.cpp
** Author: Hailey Wilder
** Description: main file 
*************************************************************************************/

#include <stdio.h>

#include "grid.h"
#include "ant_visitor.h"
// calls all and prints instructions to get user input
int main(int argc, char *argv[]) {
  int length, width, iterations, show_progress_step;

  printf("Length (eg-25): ");
  scanf("%d", &length);

  printf("Width (eg-50): ");
  scanf("%d", &width);

  printf("Iterations (eg-100): ");
  scanf("%d", &iterations);

  printf("Iteration to start showing progress (eg-1): ");
  scanf("%d", &show_progress_step);

  Grid grid(length, width);
  AntVisitor ant(iterations, show_progress_step);
  grid.Accept(&ant);

  return 0;
}