/******************************************************************************
** Program Filename: 
** Author: Hailey Wilder
** Date: 2/2/17
** Description: item.hpp is the specification file that creates an item.
*******************************************************************************/
using namespace std;
#include <iostream>
#include <string>
#include "item.hpp" //item class specification file 
#include "list.hpp" //list class specificaiton file

class University {
	protected:
		std::string OregonStateUniversity;
		std::string name;
		std::string address; 
		
	public:
		University();
		University(string OregonStateUniversity);
		void print();
};

class Buildings: public University {
	
	public:
		Buildings();
		Buildings(string name, string address);
		void print();
};

class Person {
	protected:
		std::string name, age, hours, instructorRating, GPA;
	
	public:
		Person();
		Person(string name);
		void do_work (string hrs);
		void print();
      //{ width=a; height=b; }
    //virtual int area ()
      //{ return 0; }
};

class Instructor: public Person {
	
	public:
		Instructor();
		Instructor(string name, string age, string instructorRating);
		void print();	
};

class Student: public Person {
	// EmployeeList person;
		 
	public:
		Student();
		Student(string name, string age, string GPA);
		void print();
};






int main() {
	int choice; // var for menu selection
	//List itemList; // creates a List variable
	List BuildingList;  //creates building list
	List EmployeeList;  //creates employee list
	
	std::cout << std::endl << "Welcome to Lab 4:\nOregon State University Directory!" << std::endl;

	do 
	{   // menu options -- enter choice 1-4
		std::cout << "Please make a selection: " << std::endl;
		std::cout << "1) Print employee list " << std::endl;
		std::cout << "2) Print building list " << std::endl;
		std::cout << "3) Do_work" << std::endl;
		std::cout << "4) Exit" << std::endl;
		std::cout << "Choice: ";

		std::cin >> choice;

		// check for valid input
		while (choice < 1 || choice > 4 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n'); // Adding cin.ignore() to the next line clears / ignores the newline from the stream.
			std::cout << "Invalid  Selection! Choose an option from the menu above." << std::endl;
			std::cout << "Choice: ";
			std::cin >> choice;
		}

		switch (choice)
		{

		case 1: //print personnel list
		{
			std::string name;
			std::string age;
			std::string instructorRating;
			std::string GPA;
			int option;
			
			std::cout << std::endl;
			std::cout << "***Option 1: Print employee list***" << std::endl;
			std::cout << std::endl;
			
			std::cout << "Enter name: " << std::endl;
			std::cin.clear(); // clears error flag if any
			std::cin.ignore(256, '\n'); // ignores next line from the stream
			std::getline(std::cin, name); // this method allows spaces
			
			std::cout << "Enter age: " << std::endl;
			std::cin.clear(); // clears error flag if any
			std::cin.ignore(256, '\n'); // ignores next line from the stream
			std::getline(std::cin, age); // this method allows spaces
			
			std::cout << "Do you need to enter a GPA or Instructor Rating (Enter 1 or 2): " << std::endl;
			//std::cin.clear(); // clears error flag if any
			//std::cin.ignore(256, '\n'); // ignores next line from the stream
			//std::getline(std::cin, option); // this method allows spaces
			std::cin >> option;
			
			if (option == 1)
			{
			
				std::cout << "Enter GPA: " << std::endl;
				std::cin.clear(); // clears error flag if any
				std::cin.ignore(256, '\n'); // ignores next line from the stream
				std::getline(std::cin, GPA); // this method allows spaces
				
				Item student(name, age, GPA);
				// this uses the overloaded "==" operator to compare to see if the item name already exist in the list
				if (EmployeeList == name) // will not add if item name is in the list
				{
					std::cout << "\nThis item name already exsists and was not added to the list!\n" << std::endl; 					
				}
				else // will add item to the list 
				{
					EmployeeList.addItem(student);
				}
				EmployeeList.printListP(); // calls the pintList member function
			}
			else //(option == 2)
			{
				std::cout << "Enter Instructor Rating: " << std::endl;
				std::cin.clear(); // clears error flag if any
				std::cin.ignore(256, '\n'); // ignores next line from the stream
				std::getline(std::cin, instructorRating); // this method allows spaces
				
				Item instructor(name, age, instructorRating);
				// this uses the overloaded "==" operator to compare to see if the item name already exist in the list
				if (EmployeeList == name) // will not add if item name is in the list
				{
					std::cout << "\nThis item name already exsists and was not added to the list!\n" << std::endl; 					
				}
				else // will add item to the list 
				{
					EmployeeList.addItem(instructor);
				}
				Item e1("Lynn Grim", "45", "5");
				Item e2("Bob Nye", "22", "3.0");
				Item e3("Leslie Smith", "18", "4.0");
				Item e4("Tom Huck", "25", "2.5");
				EmployeeList.addItem(e1);
				EmployeeList.addItem(e2);
				EmployeeList.addItem(e3);
				EmployeeList.addItem(e4);
				
				EmployeeList.printListP(); // calls the pintList member function
			}
			

			break;
		}
		
		case 2: // print building list
		{
			std::string name;
			std::string address;
			
			std::cout << std::endl;
			std::cout << "***Option : Print building list***" << std::endl;
			std::cout << std::endl;
			
			std::cout << "Enter building name: " << std::endl;
			std::cin.clear(); // clears error flag if any
			std::cin.ignore(256, '\n'); // ignores next line from the stream
			std::getline(std::cin, name); // this method allows spaces
			
			std::cout << "Enter building address: " << std::endl;
			std::cin.clear(); // clears error flag if any
			std::cin.ignore(256, '\n'); // ignores next line from the stream
			std::getline(std::cin, address); // this method allows spaces
			
			Item build(name, address, "placeholder");
			// this uses the overloaded "==" operator to compare to see if the item name already exist in the list
			if (BuildingList == name) // will not add if item name is in the list
			{
				std::cout << "\nThis item name already exsist and was not added to the list!\n" << std::endl; 					
			}
			else // will add item to the list 
			BuildingList.addItem(build);
			
			Item b1("Building 1", "11 S St, OR 55555", " ");
			BuildingList.addItem(b1);
			
			BuildingList.printListB(); // calls the pintList member function
			break;
		}
		
		case 3: //do_work -- instructor/student
		{
			int option2;
			std::string name;
			std::string hrs;
			
			//EmployeeList.printListP();
			std::cout << std::endl;
			std::cout << "***Option 3: Choose a person to do work.***" << std::endl << std::endl;
			std::cout << "Do work for a student or an instructor (Enter 1 or 2): " << std::endl;
			//std::cin.clear(); // clears error flag if any
			//std::cin.ignore(256, '\n'); // ignores next line from the stream
			std::cin >> option2;
			
			if (option2 == 1)
			{
				EmployeeList.printListP();
				
				std::cout << "Enter Instructor: " << std::endl;
				std::cin.clear(); // clears error flag if any
				std::cin.ignore(256, '\n'); // ignores next line from the stream
				std::getline(std::cin, name); // this method allows spaces
				
				std::cout << "Enter Hours: " << std::endl;
				std::cin.clear(); // clears error flag if any
				std::cin.ignore(256, '\n'); // ignores next line from the stream
				std::getline(std::cin, hrs); // this method allows spaces
				
				std::cout << "Instructor " << name << " graded papers for " << hrs << "." << std::endl;
				
			}
			else //(option2 == 2)
			{
				std::cout << "Enter Student: " << std::endl;
				std::cin.clear(); // clears error flag if any
				std::cin.ignore(256, '\n'); // ignores next line from the stream
				std::getline(std::cin, name); // this method allows spaces
				
				std::cout << "Enter Hours: " << std::endl;
				std::cin.clear(); // clears error flag if any
				std::cin.ignore(256, '\n'); // ignores next line from the stream
				std::getline(std::cin, hrs); // this method allows spaces
				
				std::cout << name << " did " << hrs << "hours of homework." << std::endl;
			}
			
			
			//std::getline(std::cin, name); // this method allows spaces

			
		}

		case 4: //exit out of the program
		{
			std::cout << "***Goodbye!***" << std::endl;
			return 0;
		}

		default:
		{
			break;
		}
		}
		
	} while (true);

	return 0;
}