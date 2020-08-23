/**********************************************************
** Program: SittingArea.hpp
** Author: Hailey Wilder
** Description: SittingArea.hpp is the specification file.
***********************************************************/
#ifndef SITTINGAREA_HPP
#define SITTINGAREA_HPP
#include "Room.hpp" // Brings in the Room.hpp specification file
#include "Player.hpp" // Brings in the Player.hpp specification file
#include "Inventory.hpp" // Brings in the Inventory.hpp specification file

class SittingArea : public Room // SittingArea inherits from Room class
{
    private:
		bool nameBadge;
        void printMenu();
        void getBone(Player *player);
    
    public:
        SittingArea() : Room("Sitting Area")  // Default constructor and calls the Room default construcotr
		{
            nameBadge = false;
        }
    
        GameStatus enterRoom(Player *player);
};

#endif
