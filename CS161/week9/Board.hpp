/*******************************************
** Author: Hailey Wilder
** 11/23/16
** Description: hpp for tictactoe board class 
********************************************/
#include <string>
#include <iostream>

using namespace std;

#ifndef BOARD_HPP
#define BOARD_HPP

enum state{X_WON,O_WON,DRAW,UNFINISHED};

class Board
{
    private:
        char **playingBoard;
    public:
        Board();
        bool makeMove(int,int,char);
        state gameState();
        void print();
};

#endif