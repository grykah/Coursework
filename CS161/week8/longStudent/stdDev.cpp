//
/***********************************************************
** Name: Hailey Wilder
** Date: 11/16/16
** Description: Calculates Standard deviation and zscore of
** input numbers (or optionally random numbers with slight
** modification)
***********************************************************/

#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// float seed;
double size;
int upper;
int lower;
double average;
double sum;
double sum2;//sum squared
double temp;
double sdev; //standard deviation
double zscore;


void init(){ //Gets numbers and calculates average and standard deviation

	// float seed;
	float number;
	// system("CLS");

	//cout << "Enter seed for random generator: ";
	//cin >> seed;
	//srand(seed);
	cout << endl << "Enter size of sequence: ";
	cin >> size;
	//cout << endl << "Enter lower bound: ";
	//cin >> lower;
	//cout << endl << "Enter upper bound: ";
	//cin >> upper;
	//system("CLS");
	//cout << "Numbers: ";

	for(int i = 0; i<size; i++){

		//number = rand()%(upper)+lower;
		//cout << setprecision(4) << number << ".00, ";
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
/*
void calcZ(){
	system("CLS");
	double x;
	cout << endl << "Enter a value to calculate Z-Score: ";
	cin >> x;
	zscore = ((x-average)/sdev);
	cout << setprecision(3) << endl << "Z-Score: " << zscore;
}
*/
/*
bool repeat(){

	int input;
	cout << endl << endl<< "Input your choice " << endl <<  "1)Calculate another Z-Score"<< endl << "2)Quit " << endl << ">> ";
	cin >> input;
	if(input == 1){
		return true;
	} else{
		return false;
	}
}
*/
int main(){

	init();
	setStats();

	//do{
	//	calcZ();

	//}while(repeat());


	return 0;
}
