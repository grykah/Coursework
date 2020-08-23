/*********************************************************************
** Author:  Hailey Wilder
** Date:  10/26/16
** Description:  Box class specification for calculating box volume
** and surface area.
*********************************************************************/
#ifndef BOX_HPP
#define BOX_HPP

class Box {
	private:
		double length;						// length of rectangular prism
		double width;						// width of rectangular prism
		double height;						// height of rectangular prism
	public:
		Box();								// default constructor sets length, width, and height to 1
		Box(double, double, double);		// constructor that sets length, width, and height to specific values
		void setLength(double);				// mutator method for setting length to specific value
		void setWidth(double);				// mutator method for setting width to specific value
		void setHeight(double);				// mutator method for setting height to specific value
		double getVolume();					// calculates volume of rectangular prism
		double getSurfaceArea();			// calculates surface area of rectangular prism
};

#endif