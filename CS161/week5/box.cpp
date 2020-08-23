/*********************************************************************
** Author:  Hailey Wilder
** Date:  10/26/16
** Description:  Calculates volume and surface area of box.
*********************************************************************/
#include <iostream>
#include <string>
#include "Box.hpp"

using namespace std;

/*********************************************************************
					"Helper" Function Prototypes
*********************************************************************/
void displayProgramDescription();						// shows description of program to user at beginning of program
double getUserInput(string inputDescription);			// general function for getting and validating input

/*********************************************************************
					Box Class Method Implementations
** Description:  Default constructor, which is used when
a Box object is created without initial values -- all values are 1.
** Parameters:  Takes none.
*********************************************************************/
Box::Box() {
	setLength(1);										
	setWidth(1);
	setHeight(1);
}

/*********************************************************************
** Description:  This constructor creates a Box object with values
** for length, height, and width provided by user. 
** Parameters:  This constructor takes doubles for the length, width, 
** and height.
*********************************************************************/
Box::Box(double l, double w, double h) {
	setLength(l);										
	setWidth(w);
	setHeight(h);
}

/*********************************************************************
** Description:  This class method sets the length of a Box object,
** so long as the value provided is greater than zero, else it provides 
** error and sets value to zero.
** Parameters:  This method takes a double for length.
*********************************************************************/
void Box::setLength(double l) {							
	if (l < 0) {										
		length = 0;
		cout << "Invalid input for length." << endl;
	} else {
		length = l;
	}
}

/*********************************************************************
** Description:  This class method sets the width of a Box object,
so long as the value provided is as the value provided is greater than zero, else it provides 
** error and sets value to zero.
** Parameters:  This method takes a double for width.
*********************************************************************/
void Box::setWidth(double w) {				
	if (w < 0) {
		width = 0;
		cout << "Invalid input for width." << endl;
	} else {
		width = w;
	}
}

/*********************************************************************
** Description:  This class method sets the height of a Box object,
so long as the value provided is as the value provided is greater than zero, else it provides 
** error and sets value to zero.
** Parameters:  This method takes a double for height.
*********************************************************************/
void Box::setHeight(double h) {
	if (h < 0) {
		height = 0;
		cout << "Invalid input for height." << endl;
	} else {
		height = h;
	}
}

/*********************************************************************
** Description:  Calculates and returns volume.
** Parameters:  Takes none.
*********************************************************************/
double Box::getVolume() {
	return length * width * height;
}

/*********************************************************************
** Description:  Calculates and returns surfance area.
** Parameters:  Takes none.
*********************************************************************/
double Box::getSurfaceArea() {
	return 2 * ((width * length) + (height * length) + (height * width));
}

/*********************************************************************
					"Helper" Function Implementations
** Description:  Prints a description of program.
** Parameters:  Takes none.
*********************************************************************/
void displayProgramDescription() {
	cout << "This program calculates the volume and surface area of a box." << endl;
	cout << "The user is prompted to enter the length, width, and height" << endl;
	cout << "of the box.  Then this program calculates and displays the" << endl;
	cout << "volume and surface area." << endl;
}

/*********************************************************************
** Description:  Generalizes input and input validation. 
** Parameters:  This function takes a string description of the 
** required input and returns a validated integer value.
*********************************************************************/
double getUserInput(string inputDescription) {
	double value;
	do {
		cout << endl;
		cout << "Enter " << inputDescription << " as a double:\n> ";
		cin >> value;
		if (value < 0) {
			cout << "Error:  value must be greater than 0." << endl << endl;;
		}
	} while (value < 0);
	return value;
}

int main() {
	double length, width, height;
	Box rectangularPrism;

	length = getUserInput("length");			// get and validate input for length, width, and height
	width = getUserInput("width");				// of rectangularPrism
	height = getUserInput("height");

	rectangularPrism.setLength(length);			// set values of length, width, and height of rectangularPrism
	rectangularPrism.setWidth(width);			// using values provided by user
	rectangularPrism.setHeight(height);

	cout << endl;
	cout << "Volume      : " << rectangularPrism.getVolume() << endl;		// output results of volume and
	cout << "Surface Area: " << rectangularPrism.getSurfaceArea() << endl; 	// surface area calculations

	return 0;
}