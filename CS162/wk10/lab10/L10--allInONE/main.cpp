/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Hailey Wilder
 ** Date: 3/19/17
 ** Description: The program compares the run times for different
 **              implementations of Fibonacci function.
 ** Input: n/a
 ** Output: std::cout, run times for function
 *********************************************************************/


#include <chrono>
#include <ctime>
#include <iostream>


// alias
typedef unsigned long long int ullint;

// forward declarations

// iterative
ullint fibonacci_i(ullint n);

// double recursion
ullint fibonacci_r(ullint n);


// function pointer alias
typedef ullint (*fcn)(ullint);


long time_function(ullint input, unsigned int num_tests, fcn f);


int main()
{
    //typedef unsigned long long int ullint;

    const int TESTS = 10000;   // tests to run for each function
    const int FIB_N = 20;       // input to Fibonacci


    // test Fibonacci using iteration
    std::cout << "fib(" << FIB_N << ") = " << fibonacci_i(FIB_N) << '\n';
    
    std::cout << "Time to find fib(" << FIB_N
              << ") using iteration "
              << TESTS << " times: "
              << time_function(FIB_N, TESTS, fibonacci_i)
              << " seconds\n\n";

    // test Fibonacci using double recursion
    std::cout << "fib(" << FIB_N << ") = " << fibonacci_r(FIB_N) << '\n';
    
    std::cout << "Time to find fib(" << FIB_N
              << ") using double recursion "
              << TESTS << " times: "
              << time_function(FIB_N, TESTS, fibonacci_r)
              << " seconds\n\n";

    return 0;
}


/*********************************************************************
 ** Function: fibonacci_i()
 ** Description: Returns the nth Fibonacci number.  Uses iteration.
 *********************************************************************/

ullint fibonacci_i(ullint n)
{
    ullint f_1 = 1;     // f(i - 1)
    ullint f_2 = 0;     // f(i - 2)

    for (ullint i = 2ULL; i <= n; ++i)
    {
        // temp variable to store current Fibonacci number
        ullint sum = f_1 + f_2;

        // update the previous two Fibonacci numbers for next iteration
        f_2 = f_1;
        f_1 = sum;
    }

    // stores the Fibonacci number we want now
    return f_1;
}


/*********************************************************************
 ** Function: fibonacci_r()
 ** Description: Returns the nth Fibonacci number.  Uses double
 **              recursion.
 *********************************************************************/

ullint fibonacci_r(ullint n)
{
    // base cases
    if (n == 0ULL || n == 1ULL) return n;

    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}


/*********************************************************************
 ** Function: time_function()
 ** Description: Returns the time needed to get the result of a
 **              function taking and returning an unsigned long long
 **              value num_tests times.
 ** Parameters: input       input to f
 **             num_tests   number of runs
 **             f           function to test
 *********************************************************************/

long time_function(ullint input, unsigned int num_tests, fcn f)
{
    time_t start = time(0U);

    // call the function with the specified input num_tests times
    for (unsigned int i = 0; i < num_tests; ++i)
        f(input);

    time_t end = time(0U);

    return end - start;
}
