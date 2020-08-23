/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: 
 ** Date:  2/21/17
 ** Description: 
 *********************************************************************/
#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <stdlib.h>
using namespace std;

// Tool 
class Tool
{
    int strength;
    char type;

    public:
        void setStrength(int st);
        int getStrength();
        char getType();
        void setType(char ch);
        void operator=(Tool right);
        virtual bool fight(Tool*){};
};
// Rock, Paper, Scissors Inheritance classes
class Rock: public Tool
{
public:
    Rock();
    Rock(int st);
    bool fight(Tool opponent);
};
class Paper: public Tool
{
public:
    Paper();
  
    Paper(int st);
    bool fight(Tool opponent);
};
class Scissors: public Tool
{
public:
    Scissors();
    Scissors(int st);
    bool fight(Tool opponent);
};
// RSPGame logic
class RSPGame
{
    int human_wins,computer_wins,ties;
    Tool computer,human;
public:
    RSPGame();
    void playOneGame(Tool*,Tool*);
    void printScores();
};

#endif