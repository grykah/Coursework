/********************************************************************************************
** Program: Room.hpp
** Author: Hailey Wilder
** Description: Room.hpp is the specification file header for the Room.cpp.
*********************************************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
#include "Player.hpp" // Brings in the Player.hpp specification file

class Room
{
	protected:
		std::string name; // room space name
		Room *up;
		Room *right;
		Room *down;
		Room *left;
    
        virtual void printMenu() = 0; // pure virtual function template. Each room (space) will have its own menu

	public:
		Room(std::string n); // construcor
		virtual GameStatus enterRoom(Player *player) = 0; // pure virtual function template.
        void setUp(Room *n);
        void setRight(Room *n);
        void setDown(Room *n);
        void setLeft(Room *n);
};

#endif
