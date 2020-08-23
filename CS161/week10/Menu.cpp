/*********************************************************************
** Author:  Hailey Wilder
** Date:  12/2/16
** Description:  This program simulates a Store's inventory
management.  Specifically, it allows a Store to add new books, add
new Store patrons, check out books, return books, request books,
track and resolve fines, view the current status of books, and view 
the current status of patrons.  This program makes use of three objects
to perform these tasks:  Product, Customer, and Store.  These objects are
defined and implemented in separate files.  This file simply contains
the menu that controls the flow of the program.
*********************************************************************/
#include <iostream>
#include <string>
#include "Product.hpp"
#include "Customer.hpp"
#include "Store.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();				// print a description of the program to the user
void displayMenu();								// display a menu of options to the user
int getChoice();								// get and validate menu choice
string getEntityId(string);						// general function for getting Customer ID or Product ID
double getPaymentAmount();						// get and return payment amount

/*********************************************************************
					"Helper" Function Implementations
** Description:  This function prints a description of the program to
the user when the program is first run.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayProgramDescription() {
	cout << "Welcome to Store Management System!" << endl;
	cout << "Below, you will find a menu of options that you can" << endl;
	cout << "use to add, read, and update information in the" << endl;
	cout << "Store's database. You can quit any time by choosing" << endl;
	cout << "the final option in the menu. I hope you enjoy your time!" << endl;
}

/*********************************************************************
** Description:  This function prints a menu of options to the user.
** Parameters:  This function takes no parameters.
*********************************************************************/
void displayMenu() {
	cout << "----------Store Management System Choices----------" << endl;
	cout << "1.  Add Product" << endl;
	cout << "2.  Add Customer" << endl;
	cout << "3.  Check Out" << endl;
	//cout << "4.  Return Product" << endl;
	//cout << "5.  Request Product" << endl;
	//cout << "6.  Increment Current Date" << endl;
	cout << "4.  View Product Information" << endl;  //Update this function
	cout << "5.  View Customer Information" << endl;
	cout << "7. Quit" << endl;
}

/*********************************************************************
** Description:  This function prompts the user to enter an integer
representing a choice from the menu.  The function validates that the
input falls in an acceptable range and return the valid option once it
has been entered.
** Parameters:  This function takes no parameters. It returns an 
integer representing a choice in the menu.
*********************************************************************/
int getChoice() {
	int choice;
	do {
		cout << "Enter your choice:\n> ";
		cin >> choice;
		cin.ignore();
		if ((choice < 1) || (choice > 7)) {
			cout << "Error:  Invalid choice." << endl;
			cout << "Choice must be between 1 and 10." << endl;
		}
	} while ((choice < 1) || (choice > 10));
	return choice;
}

/*********************************************************************
** Description:  This is a general function for getting and validating
an ID number associated with an object stored in the Store's 
database.  This function accepts a string value representing the type
of object for which the ID is to be collected.  The function then
prompts the user for that type of object, validates the user's input,
and then returns the value once it has been verified.
** Parameters:  This function accepts a string representing the type
of entity for which the function is collecting an ID.  The function
returns a string value representing an ID.
*********************************************************************/
string getEntityId(string entity) {
	string value;
	do {
		cout << "Enter the " << entity << " ID:\n> ";
		getline(cin, value);
		if (value.length() < 1) {
			cout << "Error:  " << entity << " ID must have length greater than 0." << endl;
		}
	} while (value.length() < 1);
	cout << endl;
	return value;
}

/*********************************************************************
** Description:  This function gets a double value representing a
payment amount.  
** Parameters:  This function accepts no parameters.  It returns a
double value representing a payment ammount.
*********************************************************************/
double getPaymentAmount() {
	double value;
	cout << "Enter the payment amount:\n> ";
	cin >> value;
	cin.ignore();
	cout << endl;
	return value;
}

/*********************************************************************
					Main Function
*********************************************************************/
int main() {
	Store Store;
	int choice;

	displayProgramDescription();

	do {
		cout << endl;
		displayMenu();							// display menu to user
		cout << endl;
		choice = getChoice();					// get and validate choice
		/*
			The switch statement below processes the choice entered by the user.  There are
			10 valid options.  The program responds by calling the appropriate Store
			function, or by quitting the program.
		*/
		switch(choice) {
			case 1:						// Add a new Product
				cout << endl;
				Store.addProduct();
				break;
			case 2:						// Add a new Customer
				cout << endl;
				Store.addMember();
				break;
			case 3:						// Check out a particular Product for a particular Customer
				cout << endl;
				Store.addProductToMemberCart(getIdCode("Product"), getName("name"));
				break;
			case 4:						// View the information for a particular Customer
				cout << endl;
				Store.getProductFromID(getEntityId("Product"));
				break;
			case 5:						// View the information for a particular Product
				cout << endl;
				Store.getMemberFromID(getEntityId("Customer"));
				break;
			case 6:					// Quit the program
				cout << endl;
				cout << "Sorry to see you go!" << endl;
				break;
			default:
				cout << "Option Not Yet Available." << endl;
				
	
	
		}
	} while (choice != 6);


	return 0;
}