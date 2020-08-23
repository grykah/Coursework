/************************************************************************************
** Program: grid.cpp
** Author: Hailey Wilder
** Description: Grid production/size class definition
*************************************************************************************/

#include "grid.h"

#include <stdio.h>
// makes grid of size determined by user
void Grid::Init() { 
  grid_ = new char*[length_];
  for (int i = 0; i < length_; ++i)
    grid_[i] = new char[width_];

  for (int i = 0; i < length_; ++i) {
    for (int j = 0; j < width_; ++j)
      grid_[i][j] = '#';
  }
}

Grid::~Grid() {
  for (int i = 0; i < length_; ++i)
    delete[] grid_[i];
  delete[] grid_;
}

void Grid::Print() const {
  for (int i = 0; i < length_; ++i) {
    for (int j = 0; j < width_; ++j) {
      putchar(grid_[i][j]);
    }
    putchar('\n');
  }

  putchar('\n');
}