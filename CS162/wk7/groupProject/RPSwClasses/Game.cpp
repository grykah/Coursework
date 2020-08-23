/*********************************************************************
 ** Program Filename: Game.cpp
 ** Author: 
 ** Date:  2/21/17
 ** Description: 
 *********************************************************************/
#include "Game.hpp"

//Tool options/settings
void Tool::setStrength(int st)
{
    strength=st;
}
void Tool::setType(char ch)
{
    type=ch;
}
int Tool::getStrength()
{
   return strength;
}
char Tool::getType()
{
   return type;
}
void Tool::operator=(Tool right)
{
    strength=right.strength;
    type=right.type;
}

// Rock
Rock::Rock()
{
    setStrength(1);
    setType('r');
}
Rock::Rock(int st)
{
    setStrength(st);
    setType('r');
}
bool Rock::fight(Tool opponent)
{
   cout<<opponent.getType()<<" Rocks\n";
    if(opponent.getType()=='s')
        return 2*this->getStrength()>opponent.getStrength();
    if(opponent.getType()=='p')
        return 0.5*this->getStrength()>opponent.getStrength();
}

// Paper
Paper::Paper()
{
    setStrength(1);
    setType('p');
}
Paper::Paper(int st)
{
    setStrength(st);
    setType('p');
}
bool Paper::fight(Tool opponent)
{
   cout<<opponent.getType()<<" Paper\n";

   if(opponent.getType()=='r')
        return 2*this->getStrength()>opponent.getStrength();
    if(opponent.getType()=='s')
        return 0.5*this->getStrength()>opponent.getStrength();
}

// Scissors
Scissors::Scissors()
{
    setStrength(1);
    setType('s');
}
Scissors::Scissors(int st)
{
    setStrength(st);
    setType('s');
}
bool Scissors::fight(Tool opponent)
{
   cout<<opponent.getType()<<" Scissors\n";
    if(opponent.getType()=='p')
        return 2*this->getStrength()>opponent.getStrength();
    if(opponent.getType()=='r')
        return 0.5*this->getStrength()>opponent.getStrength();
}

// RSP Game
RSPGame::RSPGame()
{
    human_wins=0;
    computer_wins=0;
    ties=0;
}
void RSPGame::playOneGame(Tool *human,Tool *computer)
{
    if(human->getType()==computer->getType())
    {
        ties++;
    }
    else
    {
        if(human->fight(computer))
        {
            human_wins++;
            cout<<"You Win!!!\n";
        }
        else
        {
            cout<<"The computer wins.\n";
            computer_wins++;
        }
    }
    printScores();
}
void RSPGame::printScores()
{
    cout<<"Your wins: "<<human_wins<<endl;
    cout<<"Computer wins: "<<computer_wins<<endl;
    cout<<"Ties: "<<ties<<endl;
}