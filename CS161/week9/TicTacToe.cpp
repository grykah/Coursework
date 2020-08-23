/*******************************************
** Author: Hailey Wilder
** 11/23/16
** Description: Tictactoe game file
********************************************/
#include <string>
#include <iostream>
#include "Board.hpp"
#include "TicTacToe.hpp"

using namespace std;

/*************************
** Description: default tictactoe constructor
** Parameters: takes none, reterns the game
**************************/
TicTacToe::TicTacToe()
{
    gameTable = Board();

    do{
        cout << "Who will go first x or o? (lower case only): ";
        cin >> playerTurn;
        cout << endl;

        if((playerTurn == 'x') || (playerTurn == 'o')){
            break;            
        }
        else{
            cout << "Invalid input." << endl; 
        }
    }
    while(true);
}

/*************************
** Description: swapXO players. 
** Parameters: none
**************************/
void TicTacToe::swapXO()
{
    if(playerTurn == 'x'){
        playerTurn = 'o';
    }
    else{
        playerTurn = 'x';
    }
}

/*************************
** Description: allows users to play the game. 
** Parameters: none
**************************/
void TicTacToe::play()
{

    while(true){
        int moveCol;
        int moveRow;

        do{
            cout << "Player " << playerTurn << ": It is your turn! (ex: 0 1)." << endl;
            cin >> moveCol;
            cin >> moveRow;
            cout << endl;

            if(moveCol < 0 || moveCol > 2 || moveRow < 0 || moveRow > 2){
                cout << "Input invalid." << endl << endl;
            }
            else if(gameTable.makeMove(moveCol,moveRow,playerTurn) == false){
                cout << "That space is taken already." << endl;
            }
            else{
                break;
            }
        }
        while(true);

        gameTable.makeMove(moveCol,moveRow,playerTurn);

        gameTable.print();
        cout << endl;

        swapXO();


        if(gameTable.gameState() == X_WON){
            cout << "X Won!" << endl;
            break; 
        }
        else if(gameTable.gameState() == O_WON){
            cout << "O Won!" << endl;
            break;
        }
        else if(gameTable.gameState() == DRAW){
            cout << "Draw!" << endl;
            break;
        }

        
    }
}

int main()
{
    TicTacToe game1;
    game1.play();

    return 0;
}