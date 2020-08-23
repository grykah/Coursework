/********************************************************
** Program: Player.hpp
** Author: Hailey Wilder
** Description: Player.hpp specification file.
********************************************************/
#ifndef PLAYER
#define PLAYER
class Room;
class Inventory;
#include <ctime>

enum GameStatus { KEEP_PLAYING, OUT_OF_TIME, ESCAPED };
const int TIME_LIMIT  = 2;

class Player
{
    private:
        Room *location;
        Inventory *inventory;
        time_t startTime;
    
    public:
        Player();
        Room* getLocation();
        void setLocation(Room *room);
        Inventory* getInventory();
        bool outOfTime();
};

#endif
