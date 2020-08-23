/*********************************************************************
** Author: Hailey Wilder
** Date: 12/1/16
** Description:  This file contains the class implementation details
** for the Customer class.  Specifically, this file contains the definitions
** of the constructors and public member functions for the Customer class.
** Each of the constructors and functions is described in detail below.
*********************************************************************/
#include <iostream>
#include <string>
#include "Product.hpp"
#include "Customer.hpp"

using namespace std;


/*********************************************************************
					Customer Class Method Implementations
** Description:  This constructor takes information essential to creating
** a customer profile, then the function creates a new Customer object 
** using these values and the cart remains empty.
** Parameters:  This constructor takes a string representing an ID
** number, a string representing a name, and a bool for the premimMember 
** status.
*********************************************************************/
Customer::Customer(std::string n, std::string a, bool pm) {
	name = n;
	accountID = a;
	premiumMember = pm;
}

/*********************************************************************
** Description:  This function returns the ID number associated with
** a Customer.
** Parameters:  Takes none, returns accountID.
*********************************************************************/
string Customer::getAccountID() {
	return accountID;
}


/*********************************************************************
** Description:  This function returns the name number associated with
** a Customer.  It is not required, but seemed like the logical step from 
** the previous function.
** Parameters:  Takes none, returns name.
*********************************************************************/
string Customer::getName() {
	return name;
}

/*********************************************************************
** Description:  This function returns the list of items a customer 
** has in cart.
** Parameters:  Takes none, returns getCart
*********************************************************************/
vector<> Customer::<cart>getCart() {
	return getCart;
}

/*********************************************************************
** Description:  This function adds an item to the list of items that
** the customer has put in the cart.
** Parameters:  This function accepts an object pointer
*********************************************************************/
void Customer::addProductToCart(cart) {
	addProductToCart.push_back();
}

/*********************************************************************
** Description:  This function iterates through the cart and removes 
** the items from the list.
** Parameters:  This function accepts an object pointer.
*********************************************************************/
void Customer::emptyCart() {
	for (int index = 0; index < getCart().size(); index++) {
		if (getCart()[index] >= 0) {
			addProductToCart.erase(addProductToCart.begin() + index);
			break;
		}
	}
}


