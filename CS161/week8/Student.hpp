/***********************************************************
** Name: Hailey Wilder
** Date: 11/16/16
** Description: hpp for student.cpp
***********************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "stdDev.cpp"
using namespace std;

class Student
{
    private:
		string name;
        double score; 
        double sDev
		
    public:
        Student();
        Student(string name, double score, double sDev);
		
        void setStudent(string name, double score, double sDev);
        
		string getName();
		double score();
        double sDev();
        void print();
};
#endif