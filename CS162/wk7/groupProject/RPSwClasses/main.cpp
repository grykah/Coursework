/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: 
 ** Date:  2/21/17
 ** Description: 
 *********************************************************************/
#include "Game.hpp"

int main()
{
    cout<<"Welcome to Rock, Paper, Scissors! Do you want to choose different stregngths for the tools? (y-yes, n-no) :";
    char ch;
    cin>>ch;
    int rockStrength=1,paperStrength=1,scissorsStrength=1; //initialized strength
    // user option to change strength 
	if(ch=='y')
    {
        cout<<"Enter strength of Rock :";
        cin>>rockStrength;
        cout<<"Enter strength of Paper :";
        cin>>paperStrength;
        cout<<"Enter strength of Scissors :";
        cin>>scissorsStrength;
    }
    Tool *computer;
    Tool *human;
    Rock temp4,temp1;
    Scissors temp3,temp6;
    Paper temp5,temp2;
    RSPGame game;
    //game loop
	while(1)
    {
        cout<<"Choose your tool(r-rock, p-paper,s-scissors,e-exit):";
        cin>>ch;
        if(ch=='e')
            break;
        int computerChoice=rand()%3;
        if(computerChoice==0)
        {
            cout<<"Computer chose rock\n";
            temp4=Rock(rockStrength);
            computer=&temp4;
        }
        if(computerChoice==1)
        {
            cout<<"Computer chose Paper\n";
            temp5=Paper(paperStrength);
            computer=&temp5;
        }
        if(computerChoice==2)
        {
            cout<<"Computer chose Scissors\n";
            temp6=Scissors(scissorsStrength);
            computer=&temp6;
        }
        if(ch=='r')
        {
            temp1=Rock(rockStrength);
            human=&temp1;
        }
        if(ch=='p')
        {
            temp2=Paper(paperStrength);
            human=&temp2;
        }
        if(ch=='s')
        {
            temp3=Scissors(scissorsStrength);
            human=&temp3;
        }
        game.playOneGame(human,computer); // play the game
    }
    return 0;
}