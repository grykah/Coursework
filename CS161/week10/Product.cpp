/*********************************************************************
** description:  Hailey Wilder
** Date:  12/1/16
** Description:  This file contains the class implementation details
for the Product class.  Specifically, this file contains the definitions
of the constructors and public member functions for the Product class.
Each of these constructors and functions is described in detail below.
*********************************************************************/
#include <iostream>
#include <string>
#include "Product.hpp"

using namespace std;

/*********************************************************************
					Product Class Method Implementations
** Description:  This constructor creates a Product object using an ID
** code, title, and description, price, and quantity provided when the 
** constructor is called.  
** Parameters:  This constructor takes three string parameters 
** representing the ID code, title, and description and a double and an int
** representing the price and quantity.
*********************************************************************/
Product::Product(string id, string t, string d, double p, int qa) {
	idCode = id;
	title = t;
	description = d;
	price = p;
	quanitityAvailable = qa;
}

/*********************************************************************
** Description:  This function returns the ID code of a Product.
** Parameters:  Takes none, returns idCode.
*********************************************************************/
string Product::getIdCode() {
	return idCode;
}

/*********************************************************************
** Description:  This function returns the title for a Product.
** Parameters:  Takes none, returns title.
*********************************************************************/
string Product::getTitle() {
	return title;
}

/*********************************************************************
** Description:  This function returns the description for a Product.
** Parameters:  Takes none, returns description.
*********************************************************************/
string Product::getDescription() {
	return description;
}

/*********************************************************************
** Description:  This function returns the price of a Product.
** Parameters:  Takes none, returns price of product.
*********************************************************************/
double Product::getPrice() {
	return price;
}

/*********************************************************************
** Description:  This function returns the quanitity available for a Product.
** Parameters:  Takes none, returns quantity of product.
*********************************************************************/
int Product::getQuantityAvailable() {
	return quantityAvailable;
}

/*********************************************************************
** Description:  This function decreases the stocked quantity of a Product.
** Parameters:  Takes none, returns none.
*********************************************************************/
void Product::decreaseQuantity() {
	quantityAvailable = quantityAvailible - 1;
	<cart>getCart().size
}


