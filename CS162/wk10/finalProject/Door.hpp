/********************************************************
** Program: Door.hpp
** Author: Hailey Wilder
** Description: Door class specificaiton file.
********************************************************/
#ifndef DOOR_HPP
#define DOOR_HPP
#include <string>
#include "Room.hpp" // Brings in the Room.hpp specification file
#include "Player.hpp" // Brings in the player.hpp specification file

class Door : public Room // Door class inherits from Room class
{
    private:
        void printMenu();
		std::string pwd;
		bool openDoor;
        
    public:
        Door() : Room("Door") // Door Constructor and calls the Room's class constructor
		{
			std::string pwd = "1234";
			openDoor = false;
		}
        GameStatus enterRoom(Player *player);
};

#endif
