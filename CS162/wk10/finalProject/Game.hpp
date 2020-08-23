/********************************************************
** Program: Game.hpp
** Author: Hailey Wilder
** Description: Game class specification file.
********************************************************/
#ifndef GAME_HPP
#define GAME_HPP
//#include "Game.hpp"  // Brings in the Game.hpp specification file
#include "Room.hpp"  // Brings in the Room.hpp specification file
#include "Dungeon.hpp"  // Brings in the Dungeon.hpp specification file
#include "GuestBath.hpp"  // Brings in the GuestBath.hpp specification file
#include "Door.hpp"  // Brings in the Door.hpp specification file
#include "SittingArea.hpp"  // Brings in the SittingArea.hpp specification file
#include "MasterBedroom.hpp"  // Brings in the masterBedroom.hpp specification file
#include "Player.hpp"  // Brings in the Player.hpp specification file
#include <string>

class Game
{
	private:
        Room *dungeon;
        Room *guestBath;
        Room *door;
        Room *sittingArea;
        Room *masterBedroom;    
        Player *player;
    
        int play();
        void win();
        void lose();

	public:
        Game();
        int start();
    
};

#endif