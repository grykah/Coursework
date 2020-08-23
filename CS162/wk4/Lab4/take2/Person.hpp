/******************************************************************************
** Program Filename: Person.hpp
** Author: Hailey Wilder
** Date: 2/1/17
** Description: Person.hpp is the specification file for Person which includes 
** Instructor and Student
*******************************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP

using namespace std;
#include <iostream>
#include <string>

class Person {
	protected:
		string name;
		int age, hrs;
		int instructorRating;
		int GPA;
	
	public:
		Person();
		Person(string name);
		void do_work (int hrs);
		void print();
      //{ width=a; height=b; }
    //virtual int area ()
      //{ return 0; }
};

class Instructor: public Person {
	
	public:
		Instructor();
		Instructor(string name, int age, int instructorRating);
		void print();	
};

class Student: public Person {
	// EmployeeList person;
		 
	public:
		Student();
		Student(string name, int age, int GPA);
		void print();
};