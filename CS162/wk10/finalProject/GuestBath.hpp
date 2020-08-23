/**************************************************************
** Program: GuestBath.hpp
** Author: Hailey Wilder
** Description: GuestBath.hpp class is the specificaiton file.
***************************************************************/
#ifndef GUESTBATH_HPP
#define GUESTBATH_HPP
#include "Room.hpp" // Brings in the Room.hpp specification file
#include "Player.hpp" // Brings in the Player.hpp specification file

class GuestBath : public Room // GuestBath inerits from Room class
{
    private:
        bool taskComplete;
		bool rfIDCard;
        void printMenu();
    
    public:
        GuestBath() : Room("Guest Bath") // call the GuestBath constructor and the Room constructor
        {
            taskComplete = false;
			rfIDCard = false;
        }
    
        GameStatus enterRoom(Player *player);
};

#endif