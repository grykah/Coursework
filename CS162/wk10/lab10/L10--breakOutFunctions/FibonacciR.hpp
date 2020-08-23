/*********************************************************************************************
** Program: FibonacciR.hpp
** Author: Hailey Wilder
** Description: FibonacciR.hpp is the specification header file.
** Reference: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
**********************************************************************************************/

#ifndef FIBONACCIR_HPP
#define FIBONACCIR_HPP

class FibonacciR {

public:
	FibonacciR(const int &n);
	virtual ~FibonacciR();
	void PrintFibonacci();
private:
	FibonacciR();
	int Fibonacci(const int &n);
	const int *n_;
};

#endif