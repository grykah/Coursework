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


default: main.cpp item.cpp list.cpp
	${CXX} main.cpp item.hpp item.cpp list.hpp list.cpp -o Project2
clean:
	rm -rf *.o Project2
