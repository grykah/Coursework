/**********************************************************
** Author: Hailey Wilder
** Date: 10/11/16
** Description: Gets values from file and sums.
**********************************************************/

#include <iostream>  
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
     //declare input file and output file objects
     // and  variables
     ifstream input;
     ofstream output;
     
	 string filename;
     int ints, totSum = 0;

     //get input from user
     cout << "Enter a filename: ";
     cin >> filename;

	 // try to open file
	 // if open-able, then read and sum
     input.open(filename.c_str());

     if(input)
     {
          //loop through file
          while(!input.eof())
          {
              //read ints
              input >> ints;
              //totSum sum

              totSum += ints;
          }
		cout << totSum;
     }
     //if no file, give error and end
     else
     {
         cout << "File not found." << endl;
         /*break;*/
     }
     //close the input file and open output file
     input.close();
     output.open("sum.txt");

     //if the file open, write totSum sum of ints
     if(output.is_open())
	 {	 
		  output << totSum;
	 }
     //if file unaccessable, print error.   
     else
	 {
		  cout << "Could not access the file." << endl;
	 }

     //close the output file object
     output.close();

     return 0;
}