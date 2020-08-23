/*********************************************************************
** description:  Hailey Wilder
** Date:  12/1/16
** Description:  This file contains the class implementation details for
the Store class.  Specifically, this file contains the definitions
of the constructors and public member functions for the Libraryy class.
Each of these constructors and functions is described in detail below.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Product.hpp"
#include "Customer.hpp"
#include "Store.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototype
*********************************************************************/
string getStringInput(string, string);

/*********************************************************************
					"Helper" Function Implementation
** Description:  This is a general function for getting and validating
string input that will be used to create Product and Customer objects. The
function expects string values representing the value being collected
and the name of the type for which the data is being collected. This
function verifies that the length of the string input by the user is
at least 1 character long.  Once such a string has been input, the
function returns the validated value.
** Parameters:  This function takes two string parameters, representing
the value and the type of the value.  The function returns a validated
string value entered by the user.
*********************************************************************/
string getStringInput(string value, string type) {
	string input;

	do {
		cout << "Enter the " << value << " for the " << type << ":\n> ";
		getline(cin, input);
		if (input.length() < 1) {
			cout << "Invalid input." << endl;
			cout << value << " must be at least 1 character long." << endl;
		}
	} while (input.length() < 1);

	return input;
}

/*********************************************************************
				Store Class Method Implementations
** Description:  This is the default constructor for the Store class.
It creates an empty Store, reserving 100 spaces for products and 100
spaces for members. 
** Parameters:  This constructor takes no parameters.
*********************************************************************/
Store::Store() {
	holdings.reserve(100);
	members.reserve(100);
}

/*********************************************************************
** Description:  This function prompts the user for Product information
and creates a new Product using the information provided by the user.
Specifically, the program gets the ID, title, and description for the Product
(these values are validated by the getStringInput function), and creates
a new Product object so long as the ID is unique.
** Parameters:  Takes none.
*********************************************************************/
void Store::addProduct(Product* p) {
	cout << "----------Add New Product----------" << endl;
	Product Product(getStringInput("ID", "Product"), getStringInput("title", "Product"), getStringInput("description", "Product"));
	/*
		In the loop below, we search through holdings to make sure that no Product with the
		provided ID exists.  If one does, we do not create a new Product with the duplicate
		ID.  Instead, we print an appropriate error message and go back to the menu.
	*/
	
	for (int index = 0; index < holdings.size(); index++) {										
		if (holdings[index].getIdCode() == Product.getIdCode()) {									
			cout << "Error: Product with ID " << Product.getIdCode() << " already exists." << endl;	
			return;
		}
	}

	holdings.push_back(Product* p);			// no duplicate found; add new Product to holdings
	
}

/*********************************************************************
** Description:  This function prompts the user for Customer information
and creates a new Customer using the information provided by the user.
Specifically, the program gets the ID, and name of the Customer (these
values are validated by the getStringInput function), and creates a new
Customer object so long as the ID is unique.
** Parameters:  Takes none.
*********************************************************************/
void Store::addMember(Customer* c) {
	cout << "----------Add New Customer----------" << endl;
	Customer Customer(getStringInput("ID", "Customer"), getStringInput("name", "Customer"));
	/*
		In the loop below, we search through members to make sure that no Customer with the provided
		id already exists.  If one does, we do not create a new Product with the duplicate ID.  Instead,
		we print an appropriate error message and go back to the menu.
	*/
	
	for (int index = 0; index < members.size(); index++) {											
		if (members[index].getIdNum() == Customer.getIdNum()) {										
			cout << "Error:  Member with ID " << Customer.getIdNum() << " already exists." << endl;	
			return;																					
		}
	}

	members.push_back(Customer* c);		// no duplicate found; add new Customer to members
	
}

/*********************************************************************
** Description:  This function checks out a particular Product for a 
particular Customer, provided that the Product is not already checked out
or requested by another Customer.  If the Product is already on checked out
or requested by another Customer, then the function prints out the
appropriate message and returns to the menu.  Otherwise, the function
checks out the Product for the Customer.  The particular details of this
will be addressed in comments below.
** Parameters:  This function accepts two string values, one for the 
ID associated with a Customer and another for the ID of the Product.
*********************************************************************/
void Store::addProductToMemberCart(string pID, string mID) {
	int patronIndex = -1, 
		productIndex = -1;

	for (int index = 0; index < members.size(); index++) {		// look to see if member is in the member list 
		if (members[index].getIdNum() == mID) {
			patronIndex = index;								// member found; keep track of member index
			break;
		}
	}

	if (patronIndex == -1) {									// member not found; return to menu
		cout << "Error:  Customer not found." << endl;
		return;
	}
	
	for (int index = 0; index < holdings.size(); index++) {		// look to see if Product is in holdings
		if (holdings[index].getIdCode() == pID) {
			productIndex = index;									// Product found; keep track of Product index
			break;
		}
	}

	if (productIndex == -1) {										// Product not found; return to menu
		cout << "Error:  Product not found." << endl;
		return;
	}
}





/*********************************************************************
** Description:  This function looks up and prints all of the relevant
information for a particular Customer.  Specifically, this function prints
the Customer ID, Customer name, a list of the products that are currently
checked out, and the current fines associated with the user.
** Parameters:  This function accepts a string value representing a
Customer ID.  
*********************************************************************/
Customer* Store::getMemberFromID(string mID) {
	int patronIndex = -1;

	for (int index = 0; index < members.size(); index++) {			// look up Customer to see if they are in
		if (members[index].getIdNum() == mID) {				// the database
			patronIndex = index;
			break;
		}
	}

	if (patronIndex == -1) {										// if user is not found, print error message
		cout << "Error:  Customer not found." << endl;				// and return to menu
		return;
	}

	/*
		Below, we print out the information that is associated with the specified user.  Specifically,
		we print out the Customer's ID, their name, the products they have checked out, and the total that
		is due for their cart.
	*/
	
	cout << "Customer ID:         " << members[patronIndex].getAccountID() << endl;
	cout << "Customer Name:       " << members[patronIndex].getName() << endl;
	
	cout << "Products In Cart: ";
	for (int index = 0; index < members[patronIndex].getCart().size(); index++) {
		cout << members[patronIndex].getCart()[index]->getTitle();
		if (index != (members[patronIndex].getCart().size() - 1)) {
			cout << ", ";
		}
	}
	cout << endl;
	cout << fixed << showpoint << setprecision(2);		//formatting sigfigs
	cout << "Current Cost:     $" << members[patronIndex].getCart() << endl; 
	
}

/*********************************************************************
** Description:  This function prints out all of the information for a
particular Product if the Product is found in the database.  Specifically,
fhis function prints out the Product ID, the Product title, the Product description,
the Product location, by whom the Product is requested, and by whom the Product
is checked out, and how many days the Product has left until it is overdue
or whether it is already overdue.
** Parameters:  This function accepts a string value representing a
Product ID.
*********************************************************************/
Product* Store::getProductFromID(string pID) {
	int productIndex = -1;

	for (int index = 0; index < holdings.size(); index++) {				// look up Product to make sure it is in
		if (holdings[index].getIdCode() == pID) {					// the holdings
			productIndex = index;
			break;
		}
	}

	if (productIndex == -1) {												// if Product is not found, return to menu
		cout << "Error:  Product not found." << endl;
		return;
	}

	
		Print out the following information:
			Product ID (Always)
			Product Title (Always)
			Product Description (Always)
			
	cout << "Product ID:            " << holdings[productIndex].getIdCode() << endl;
	cout << "Product Title:         " << holdings[productIndex].getTitle() << endl;
	cout << "Product Description:        " << holdings[productIndex].getDescription() << endl;
	
}



/*********************************************************************
** Description:  This function checks out a particular product for a 
particular patron, provided that the product is not already checked out
or requested by another patron.  If the product is already on checked out
or requested by another patron, then the function prints out the
appropriate message and returns to the menu.  Otherwise, the function
checks out the product for the patron.  The particular details of this
will be addressed in comments below.
** Parameters:  This function accepts a string, associated with a patron. 
*********************************************************************/
void Store::checkOutMember(string mID) {
	int patronIndex = -1, 
		productIndex = -1;
		
	pID = getCart(mID);
	
	for (int index = 0; index < members.size(); index++) {		// look to see if member is in the member list 
		if (members[index].getIdNum() == mID) {
			patronIndex = index;								// member found; keep track of member index
			break;
		}
	}

	if (patronIndex == -1) {									// member not found; return to menu
		cout << "Error:  Patron not found." << endl;
		return;
	}
		
	for (int index = 0; index < holdings.size(); index++) {		// look to see if product is in holdings
		if (holdings[index].getIdCode() == pID) {
			productIndex = index;								// product found; keep track of product index
			break;
		}
	}

	if (productIndex == -1) {									// product not found; return to menu
		cout << "Error:  Product unavailable." << endl;
		return;
	}

}
