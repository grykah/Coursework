/*******************************************
** Author: Hailey Wilder
** 11/23/16
** Description: hpp for tictactoe board class 
********************************************/
#include <string>
#include <iostream>
#include "Board.hpp"

using namespace std;

/*************************
** Description: allocates space for board 
** Parameters: takes none and gives a game board
**************************/
Board::Board()
{
    //initializing array
    playingBoard = new char*[3];
    for(int i =0;i < 3;i++){
        playingBoard[i] = new char[3];
    }

    //filling array with empty space
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            playingBoard[i][j] = '.';
        }
    }
}

/*************************
** name: makeMove
** Description: allocates an x or o for a position on the board
** Parameters: takes xcoord, ycoord, player (x or o) and 
** returns true or false
**************************/
bool Board::makeMove(int xCoor,int yCoor,char player)
{
    if(playingBoard[yCoor][xCoor] == '.'){
        playingBoard[yCoor][xCoor] = player;
        return true;
    }
    else{
        return false;
    }
    
}

/*************************
** Description: Checks the game state to determine if
** someone has won from vertical, horizontal, or diagonal
** front.  Also checks for draws and unfinished games.
** Parameters: none
**************************/
state Board::gameState()
{
    state playerX = UNFINISHED;
    state playerO = UNFINISHED;

    //vertical
    for(int i = 0; i < 3;i++){
        if(playingBoard[0][i] == 'x' && playingBoard[1][i] == 'x' && playingBoard[2][i] == 'x'){
            playerX = X_WON;
        }
        else  if(playingBoard[0][i] == 'o' && playingBoard[1][i] == 'o' && playingBoard[2][i] == 'o'){
            playerO = O_WON;
        }
    }
    //horizontal
    for(int i = 0; i < 3;i++){
        if(playingBoard[i][0] == 'x' && playingBoard[i][1] == 'x' && playingBoard[i][2] == 'x'){
            playerX = X_WON;
        }
        else  if(playingBoard[i][0] == 'o' && playingBoard[i][1] == 'o' && playingBoard[i][2] == 'o'){
            playerO = O_WON;
        }
    }
    //diagonals
    if(playingBoard[0][0] == 'x' && playingBoard[1][1] == 'x' &&playingBoard[2][2] =='x'){
        playerX = X_WON;
    }
    else if(playingBoard[0][0] == 'o' && playingBoard[1][1] == 'o' &&playingBoard[2][2] =='o'){
        playerO = O_WON;
    }

    if(playingBoard[2][0] == 'x' && playingBoard[1][1] == 'x' &&playingBoard[0][2] =='x'){
        playerX = X_WON;
    }
    else if(playingBoard[2][0] == 'o' && playingBoard[1][1] == 'o' &&playingBoard[0][2] =='o'){
        playerO = O_WON;
    }

    //looking for draw
    int freespaces = 0;
    for(int i = 0;i < 3;i++){
        for(int j =0;j < 3;j++){
            if(playingBoard[i][j] != '.'){
                freespaces++;
            }
        }
    }

    //returning the winner...
    if(playerX == X_WON && playerO == UNFINISHED){
        //cout << "X WON" << endl;
        return X_WON;
    }
    else if(playerX == UNFINISHED && playerO == O_WON){
        //cout << "O WON" << endl;
        return O_WON;
    }
    else if(freespaces == 9){
        //cout << "Draw" << endl;
        return DRAW;
    }
    else if(playerX == UNFINISHED && playerO == UNFINISHED){
        //cout << "Unfinished" << endl;
        return UNFINISHED;
    }

}

/*************************
** Description: prints the 3x3 array 
** Parameters: none
**************************/
void Board::print()
{
    cout << "  0 1 2" << endl; 
    for(int i = 0; i < 3; i++){
        cout << i;
        for(int j = 0;j < 3; j++){
            cout << " " <<playingBoard[i][j];
        }
        cout<< endl;
    }
}

/*
// //unit tests
int main(){
//     Board draw,horizontal,diagonals,vertical;

     draw.makeMove(0,0,'o');
     draw.makeMove(0,1,'x');
     draw.makeMove(0,2,'o');
     draw.makeMove(1,0,'x');
     draw.makeMove(1,1,'x');
     draw.makeMove(1,2,'o');
     draw.makeMove(2,0,'o');
     draw.makeMove(2,1,'o');
     draw.makeMove(2,2,'x');
     draw.print();
     draw.gameState();

     vertical.makeMove(0,1,'o');
     vertical.makeMove(1,1,'o');
     vertical.makeMove(2,1,'o');
     vertical.print();
     vertical.gameState();

     horizontal.makeMove(0,0,'x');
     horizontal.makeMove(0,1,'x');
     horizontal.makeMove(0,2,'x');
     horizontal.print();
     horizontal.gameState();

     diagonals.makeMove(0,0,'o');
     diagonals.makeMove(1,1,'o');
     diagonals.makeMove(2,2,'o');
     diagonals.print();
     diagonals.gameState();

}
*/