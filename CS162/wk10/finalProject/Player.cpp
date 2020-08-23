/********************************************************
** Program: Player.cpp
** Author: Hailey Wilder
** Description: Player.cpp is the implmenation file.
********************************************************/
#include "Room.hpp"  // Brings in the Room.hpp specification file
#include "Player.hpp" // Brings in the Player.hpp specification file
#include "Inventory.hpp" // Brings in the Inventory.hpp specification file
#include <ctime> // used for the timer
#include <iostream>

/********************************************************
 ** Function: Player ()
 ** Description: constructor
 ** Parameters: None
 ********************************************************/
Player::Player()
{
    inventory = new Inventory();
    time(&startTime);
}

/********************************************************
 ** Function: getLocation ()
 ** Description: returns the location of the pointer player
 ** Parameters: None
 ********************************************************/
Room* Player::getLocation()
{
    return location;
}

/********************************************************
 ** Function: getInventory ()
 ** Description: returns inventory
 ** Parameters: None
 ********************************************************/
Inventory* Player::getInventory()
{
    return inventory;
}

/********************************************************
 ** Function: setLocation ()
 ** Description: sets the location
 ** Parameters: Room address
 ********************************************************/
void Player::setLocation(Room *room)
{
    location = room;
}

/*************************************************************
 ** Function: outOfTime ()
 ** Description: Timer count down if it reach 0 is game over.
 ** Parameters: None
 *************************************************************/
bool Player::outOfTime()
{
    time_t currTime;
    time(&currTime);
    
    if(difftime(currTime, startTime) / 60.0 > TIME_LIMIT)
        return true;
    else
        return false;
}
