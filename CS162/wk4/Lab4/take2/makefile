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


default: main.cpp Person.cpp University.cpp
	${CXX} main.cpp Person.hpp Person.cpp University.hpp University.cpp -o Lab4
clean:
	rm -rf *.o Lab4
