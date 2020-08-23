/***********************************************************
** Name: Hailey Wilder
** Date: 11/16/16
** Description: gets name and score and uses stdDev.cpp
***********************************************************/


#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;
#include "Student.hpp"


/***********************************************************
** Description: gets student info
** Parameters: takes none returns name, score, or stdDev 
** respectively
***********************************************************/
Student :: Student()
{
    name = "";
    score = 0;
	
}
Student :: Student(string name, double score, double sDev)
{
    this -> name = name;
    this -> score = score;
}

void Student :: setStudent(string name, double score, double sDev)
{
    this -> name = name;
    this -> score = score;
}

string Student :: getName()
{
    return name;
}


double Student :: getscore()
{
    return score;
}

double Student :: getstdDev()
{
	/*
	double size;
	double average;
	double sum;
	double sum2;//sum squared
	double temp;
	double stddev; //standard deviation

	cout << endl << "Enter size of sequence: ";
	cin >> size;
	
	for(int i = 0; i<size; i++){

		//number = rand()%(upper)+lower;
		//cout << setprecision(4) << number << ".00, ";
		cout << "Enter number in set: "<< endl;
		cin >> number;
		sum += number;
		sum2 = (number*number)+sum2;
	}

	average = sum/size;
	stddev = sqrt(sum2/size-average*average);
	
	//cout << endl << endl << "Average: " << average << endl;
	//cout << "Standard Deviation: " << sdev << endl;
	*/
	
	init()
	setStats()
	
	return stdDev;
}

void Student :: print()
{
    cout << "Name: " << name << endl;
    cout << "Score: " << score << endl;
	cout << "Standard Dev: " << stdDev << endl;
}

/*
int main()
{
    Student s;
    string name;
    double score;

    cout << "Enter name ";
    cin >> name;
    cout << "Enter score ";
    cin >> score;

    s.setStudent(name, score, sDev);
    s.print();
	
    return 0;
}
*/