/***********************************************************
** Program: MasterBedroom.hpp
** Author: Hailey Wilder
** Description: MasterBedroom.hpp is the specification file.
************************************************************/
#ifndef MASTERBEDROOM_HPP
#define MASTERBEDROOM_HPP
#include "Room.hpp" // Brings in the Room.hpp specification file
#include "Player.hpp" // Brings in the Player.hpp specification file

class MasterBedroom : public Room // MasterBedroom Class inherits from Room class
{
    private:
        void printMenu();
		bool videoTapePlayer;
    
    public:
        MasterBedroom() : Room("Master Bedroom") // default constructor and call the Room's default constructor
		{
			videoTapePlayer = false;
		}
        GameStatus enterRoom(Player *player);
};

#endif
