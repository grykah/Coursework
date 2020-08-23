/*******************************************
** Author: Hailey Wilder
** 11/23/16
** Description: header file for class for the
** tictactoe game itself.
********************************************/
#include <string>
#include <iostream>
#include "Board.hpp"

using namespace std;

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

class TicTacToe
{
    private:
        Board gameTable;
        char playerTurn;
    public:
        TicTacToe();
        void play();
        void swapXO();
};

#endif