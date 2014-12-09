/*----------------------------------------------
HEADERS
------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <math.h>
#include "si.h"

/*----------------------------------------------
MAIN FUNCTION
------------------------------------------------*/
int main(int argc, char *argv[]){
//Initialize Variables
tankPositionX = 3 ;
tankPositionY = 22;
int maxx, maxy; //maxx and maxy size of terminal
int c, timerCtr = 0, actualTime = 0, size, score;
int scoreArray[10];
char playerList[10][60], playerName[50];
char in;
bool continueProgram = true;
//Start Curses
initialize();
getmaxyx(stdscr, maxy, maxx); // get current screen size
//Display Tittle Screen
printWelcomeScreen(maxy, maxx); // Print welcome screen
erase();

//Start Loop
//get new input
do
{
showMenu(in, maxx, maxy);
size = uploadData(scoreArray, playerList);
erase();
switch(in){
case '1':
case 's':
case 'S':
displayScores(playerList, scoreArray,size,maxx,maxy);
erase();
break;

case '2':
case 'p':
case 'P':
//print instructions
printInstructions(maxy, maxx, playerName);
erase();
//play game
score = playGame(in, maxx, timerCtr, actualTime);
erase();
break;

case '3':
case 'q':
case 'Q':
continueProgram = false;
break;

default:
break;
}
}while(continueProgram);
//print menu screen
//if '1' , show score board
//else if '2' , play the game
//End Curses
finish(0);
//End Program
return 0;
}
