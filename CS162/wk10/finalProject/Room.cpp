/********************************************************
** program: Room.cpp
** Author: Hailey Wilder
** Description: Room class implemnation file.
********************************************************/
#include "Room.hpp"  // Brings in the Room.hpp specification file
#include "Player.hpp" // Brings in the Player.hpp specification file
#include <string>
#include <iostream>

/********************************************************
 ** Function: Room ()
 ** Description: constructor
 ** Parameters: room name
 ********************************************************/
Room::Room(std::string n)
{
	name = n;
	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;
}


/********************************************************
 ** Function: setUp ()
 ** Description: sets the up room
 ** Parameters: r pointer
 ********************************************************/
void Room::setUp(Room *r)
{
    up = r;
}


/********************************************************
 ** Function: setRight()
 ** Description: sets the right room
 ** Parameters: r pointer
 ********************************************************/
void Room::setRight(Room *r)
{
    right = r;
}


/********************************************************
 ** Function: setDown ()
 ** Description: sets the down room
 ** Parameters: r pointer
 ********************************************************/
void Room::setDown(Room *r)
{
    down = r;
}


/********************************************************
 ** Function: setLeft ()
 ** Description: sets the left room
 ** Parameters: r pointer
 ********************************************************/
void Room::setLeft(Room *r)
{
    left = r;
}
