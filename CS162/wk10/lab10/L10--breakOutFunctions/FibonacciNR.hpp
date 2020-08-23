/*********************************************************************************************
** Program: FibonacciNR.hpp
** Author: Hailey Wilder
** Description: FibonacciNR.hpp is the specification header file.
** Reference: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
**********************************************************************************************/

#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

class FibonacciNR {
public:
	FibonacciNR(const int &n);
	virtual ~FibonacciNR();
	void PrintFibonacci();
private:
	FibonacciNR();
	int Fibonacci(const int &n);
	const int* n_;
};
#endif