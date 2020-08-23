/******************************************************************************
** Program Filename: University.hpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: University.hpp is the specification file that University and Buildings.
*******************************************************************************/
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

using namespace std;
#include <iostream>
#include <string>


class University {
	protected:
		string OSU;
		string name;
		string address; 
		
	public:
		University();
		University(string OSU);
		void print();
};

class Buildings: public University {
	
	public:
		Buildings();
		Buildings(string name, string address);
		void print();
};