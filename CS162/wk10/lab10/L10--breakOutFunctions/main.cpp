/*********************************************************************************************
** Program: main.cpp
** Author: Hailey Wilder
** Date: 03/15/17
** Description: Fibonacci recursion vs iteration & code reuse.
** Reference: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
** Reference: http://www.cplusplus.com/reference/ctime/clock/
**********************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
#include <ctime> // used to measure time
#include <time.h> // clock_t, clock, CLOCKS_PER_SEC
#include <sys/time.h> // used for timespec

using namespace std;

// function prototypes
long rfactorial(int n);
long factorialHelper(int n, int result);
long factorial(int);
timespec diff(timespec start, timespec end); // returns time in ns

int main() {

	timespec time1; // start time 
	timespec time2; // end time
	int n; // sequence number variable
	int f; // factorial number variable

	std::cout << "\n************Welcome to Lab 10: Recursion vs Iteration & Code Reuse!************\n";

	cout << "\nEnter the sequence number in the Fibonacci that you would like to find? " << endl;
	cin >> n;

	cout << "Finding the " << n << "'th " << "Fibonacci number...." << endl;
	cout << "Calling Recursive Fibonacci implementation" << endl;
   	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	FibonacciR fr(n); // Create a FibonacciR object and sending the Fibonacci sequence number
	fr.PrintFibonacci(); // print the results
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << "Run Time: " << diff(time1,time2).tv_nsec << " ns" << endl;

	cout << "\nCalling Non-Recursive Fibonacci implementation" << endl;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	FibonacciNR fnr(n); // Create a FibonacciNR object and sending the Fibonacci sequence number
	fnr.PrintFibonacci(); // print the results
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << "Run Time: " << diff(time1,time2).tv_nsec << " ns" << endl; 

	cout << "\nFactorial calculator, enter a number: ";
	cin >> f;

	cout << "\nCalling Tail Recursive Factorial Function..." << endl;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	factorial(f);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << "Run Time: " << diff(time1,time2).tv_nsec << " ns" << endl;

	cout << "\nCalling Not Tail Recursive Factorial Function..." << endl;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	rfactorial(f);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << "Run Time: " << diff(time1,time2).tv_nsec << " ns" << endl;
	
	return 0;
}

long rfactorial(int n) //from the instructions, not tail recursive
{
	if (n == 1)
		return 1;
	else
		return  n * rfactorial(n - 1);
}

long factorialHelper(int n, int result) //from the instructions, tail recursive
{
	if (n == 1)
		return result;
	else
		return factorialHelper(n - 1, n*result);
}

long factorial(int n) //solves for factorial n
{
	return factorialHelper(n, 1);
}

timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}