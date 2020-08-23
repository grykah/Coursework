/********************************************************
** Program: Dungeon.hpp
** Author: Hailey Wilder
** Description: Dungeon.hpp specificaiton file.
********************************************************/
#ifndef Dungeon_HPP
#define Dungeon_HPP
#include "Room.hpp" // brings in the Room.hpp spcification file
#include "Player.hpp" // brings in the Player.hpp specification file

class Dungeon : public Room // Dungeon class inherits from Room class
{
    private:
        bool videoTape;
        void printMenu();
    
    public:
        Dungeon() : Room("Dungeon") // calls the Room's constructor to set the rooms name, and uses its own constructor to set videoTape
        {
            videoTape = false;
        }
    
        GameStatus enterRoom(Player *player);
};

#endif