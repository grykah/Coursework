#ifndef CUTOUTPUT_H
#define CUTOUTPUT_H
#include <string>
#include "student.hpp"

void getCuts(float cutPoints[]);
void passOutput(int k, student students[], float cutPoints[]);
void gradeOutput(int k, student students[], float cutPoints[]);

#endif