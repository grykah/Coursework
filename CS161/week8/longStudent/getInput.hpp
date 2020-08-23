#ifndef GETINPUT_H
#define GETINPUT_H
#include <string>
#include "student.hpp"

void getArtifacts(int artifactCount, int points[], int weights[]);
void getStudents(int studentCount, student students[]);
void getScores(int scoreCount, int studentCount, int artifactCount, student students[], int points[], int weights[]);

#endif