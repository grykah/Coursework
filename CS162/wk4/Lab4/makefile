#/****************************************************************************** 
#** Program Filename: makefile
#** Author: Hailey Wilder
#** Date: 2/1/17
#** Description: Builds program
#*******************************************************************************/

CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time


default: polymorphism.cpp item.cpp list.cpp
	${CXX} polymorphism.cpp item.hpp item.cpp list.hpp list.cpp -o Lab4
clean:
	rm -rf *.o Lab4
