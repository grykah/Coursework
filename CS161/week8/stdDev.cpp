/***********************************************************
** Name: Hailey Wilder
** Date: 11/16/16
** Description: Calculates Standard deviation
***********************************************************/

#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double size;
double average;
double sum;
double sum2;//sum squared
double temp;
double sdev; //standard deviation


void init(){ //Gets numbers and calculates average and standard deviation

	float number;

    cout << endl << "Enter size of sequence: ";
	cin >> size;

	for(int i = 0; i<size; i++){


		cout << "Enter number in set: "<< endl;
		cin >> number;
		sum += number;
		sum2 = (number*number)+sum2;
	}

	average = sum/size;
}

void setStats(){ //sets all the statistics and shows the average and standard deviation


	sdev = sqrt(sum2/size-average*average);
	cout << endl << endl << "Average: " << average << endl;
	cout << "Standard Deviation: " << sdev << endl;
}


int main(){

	init();
	setStats();


	return 0;
}
