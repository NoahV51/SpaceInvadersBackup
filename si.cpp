/*----------------------------------------------
HEADERS
------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
/*------------------------------------------
Structures
-------------------------------------------*/
struct alien
{
int alienXpos;
int alienYpos;
char alienCharacter;
bool alienLife;
int alienXposOld;
int alienVelocity;
};
struct barrier
{
int barrierXpos[18];
int barrierYpos[3];
char barrierCharacter;
bool barrierLife;
};
struct bullet
{
int bulletXpos;
int bulletYpos;
char bulletCharacter;
bool bulletLife;
int bulletVelocity;
int bulletXposOld;
int bulletYposOld;
};
/*----------------------------------------------
PROTOTYPES
------------------------------------------------*/
int tankPositionX;
int tankPositionY;
int tankOldPositionX;
int tankOldPositionY;
void initialize();
void makeEraseString(char buf[], int len);
void printWelcomeScreen(int maxy, int maxx);
void printInstructions(int maxy, int maxx, char name[]);
void shootBullet(int xPos, int yPos, int timer);
void alienBullets();
void printTank();
void printBullet();
void printAliens();
void printBarriers();
void barrierCoordinates();
bool collisionDetection(int yPos, int xPos);
bool barrierCollisionDetection(int yPos, int xPos);
int playGame(char c,int maxx, int &timer, int &actual);
void updateTime( int ctr, int &time);
int uploadData(int scoreArr[], char playerArr[][60]);
void finish(int sig);
void showMenu(char& input, int maxx, int maxy);
void displayScores(char playerArr[][60], int scoreArr[], int &size, int maxx, int maxy);
double tankVelocityX;
double tankVelocityChange;
alien moveAliens[39];
int barrierArray[90][90];
int alienBulletArray[79][24];
void shiftAliens(int timer);
void delay();
void initialize(){
//terminal graphics
(void) initscr(); //initializes the curses library
start_color();
keypad(stdscr, TRUE); //enable keyboard mapping
(void) nonl(); //tesll curses not to do NL-> CR/NL on output
(void) cbreak(); //take input chars one at a time
(void) noecho(); //dont echo input
nodelay(stdscr, TRUE);
init_pair(1, COLOR_BLUE, COLOR_BLACK);
init_pair(2, COLOR_RED, COLOR_RED);
init_pair(3, COLOR_GREEN , COLOR_GREEN);
init_pair(4, COLOR_BLUE, COLOR_BLUE);
init_pair(5, COLOR_BLACK, COLOR_BLACK);
init_pair(6, COLOR_WHITE, COLOR_WHITE);
init_pair(7, COLOR_WHITE, COLOR_BLACK);
//initialize game global variables
//tank
double tankVelocityX = 0.0001;
double tankVelocityY = 0.0;
double tankVelocityChange = 0.0005;
// double tankPositionX = maxx - 70 ;
// double tankPositionY = maxy - 2;
double speed_shotX = 0.0;
double speed_shotY = 0.0005; //speed of the bullet in y dir.
//alien
double alienVelocityX = 0.0001;
double alienVelocityY = 0.0;
//double alienPositionX = ;
//double alienPositionY = ;
//set up aliens
for (int i = 0; i < 15; i++)
{
moveAliens[i].alienXpos = (i*2)+10;
moveAliens[i].alienYpos = 3;
moveAliens[i].alienCharacter = 'k';
moveAliens[i].alienLife = true;
moveAliens[i].alienVelocity = 1;
}
for (int i = 15; i < 27; i++)
{
moveAliens[i].alienXpos = (i*2)+5;
moveAliens[i].alienYpos = 6;
moveAliens[i].alienCharacter = 'k';
moveAliens[i].alienLife = true;
moveAliens[i].alienVelocity = 1;
}
for (int i = 27; i < 36; i++)
{
moveAliens[i].alienXpos = (i*2)+3;
moveAliens[i].alienYpos = 9;
moveAliens[i].alienCharacter = 'k';
moveAliens[i].alienLife = true;
moveAliens[i].alienVelocity = 1;
}
for (int i = 36; i < 39; i++)
{
moveAliens[i].alienXpos = (i*2);
moveAliens[i].alienYpos = 12;
moveAliens[i].alienCharacter = 'k';
moveAliens[i].alienLife = true;
moveAliens[i].alienVelocity = 1;
}

}
void makeEraseString(char buf[], int len){
for(int i = 0; i < len; i++){
buf[i] = ' ';
}
buf[len] = '\0';
return;
}
void printBarriers(){
//set barrier color
attron(COLOR_PAIR(4));
//print the barriers
mvaddch(19,5, '#');
mvaddch(19,6, '#');
mvaddch(19,7, '#');
mvaddch(19,8, '#');
mvaddch(19,9, '#');
mvaddch(19,10, '#');
mvaddch(19,11, '#');
mvaddch(19,12, '#');
mvaddch(19,20, '#');
mvaddch(19,21, '#');
mvaddch(19,22, '#');
mvaddch(19,23, '#');
mvaddch(19,24, '#');
mvaddch(19,25, '#');
mvaddch(19,26, '#');
mvaddch(19,27, '#');
mvaddch(19,36, '#');
mvaddch(19,37, '#');
mvaddch(19,38, '#');
mvaddch(19,39, '#');
mvaddch(19,40, '#');
mvaddch(19,41, '#');
mvaddch(19,42, '#');
mvaddch(19,43, '#');
mvaddch(19,51, '#');
mvaddch(19,52, '#');
mvaddch(19,53, '#');
mvaddch(19,54, '#');
mvaddch(19,55, '#');
mvaddch(19,56, '#');
mvaddch(19,57, '#');
mvaddch(19,58, '#');
mvaddch(19,67, '#');
mvaddch(19,68, '#');
mvaddch(19,69, '#');
mvaddch(19,70, '#');
mvaddch(19,71, '#');
mvaddch(19,72, '#');
mvaddch(19,73, '#');
mvaddch(19,74, '#');
mvaddch(18,6, '#');
mvaddch(18,7, '#');
mvaddch(18,8, '#');
mvaddch(18,9, '#');
mvaddch(18,10, '#');
mvaddch(18,11, '#');
mvaddch(18,21, '#');
mvaddch(18,22, '#');
mvaddch(18,23, '#');
mvaddch(18,24, '#');
mvaddch(18,25, '#');
mvaddch(18,26, '#');
mvaddch(18,37, '#');
mvaddch(18,38, '#');
mvaddch(18,39, '#');
mvaddch(18,40, '#');
mvaddch(18,41, '#');
mvaddch(18,42, '#');
mvaddch(18,52, '#');
mvaddch(18,53, '#');
mvaddch(18,54, '#');
mvaddch(18,55, '#');
mvaddch(18,56, '#');
mvaddch(18,57, '#');
mvaddch(18,68, '#');
mvaddch(18,69, '#');
mvaddch(18,70, '#');
mvaddch(18,71, '#');
mvaddch(18,72, '#');
mvaddch(18,73, '#');
mvaddch(17,7, '#');
mvaddch(17,8, '#');
mvaddch(17,9, '#');
mvaddch(17,10, '#');
mvaddch(17,22, '#');
mvaddch(17,23, '#');
mvaddch(17,24, '#');
mvaddch(17,25, '#');
mvaddch(17,38, '#');
mvaddch(17,39, '#');
mvaddch(17,40, '#');
mvaddch(17,41, '#');
mvaddch(17,53, '#');
mvaddch(17,54, '#');
mvaddch(17,55, '#');
mvaddch(17,56, '#');
mvaddch(17,69, '#');
mvaddch(17,70, '#');
mvaddch(17,71, '#');
mvaddch(17,72, '#');
refresh(); //refresh screen
attroff(COLOR_PAIR(1)); // go back to default colors

barrierCoordinates();
return;
}

void printWelcomeScreen(int maxy, int maxx){
erase(); // clear screen
attron(COLOR_PAIR(1)); //change color
mvprintw(maxy/4, maxx/2 - 15, "Welcome to !(Space Invaders)"); // print welcome, approximately middle of screen
mvprintw(maxy/4+1, maxx/2 - 15, "----------------------------");
mvprintw(maxy/4+15, maxx/2 - 15, "press any key to continue...");
refresh(); //refresh screen
attroff(COLOR_PAIR(1)); // go back to default colors
//sleep(1); // sleep for a second by calling the linux/unix sleep library call
char in;
scanf("%c", &in);
return;
}

void printTank(){
attron(COLOR_PAIR(3));
mvaddch(tankPositionY, tankPositionX, 'x');
mvaddch(tankPositionY,tankPositionX + 1, 'x');
mvaddch(tankPositionY,tankPositionX +2, 'x');

attron(COLOR_PAIR(5));
mvaddch(tankPositionY, tankOldPositionX, 'x');
mvaddch(tankPositionY, tankOldPositionX+1, 'x');
mvaddch(tankPositionY, tankOldPositionX+2, 'x');

refresh(); //refresh screen
}

int playGame(char c, int maxx, int &timer, int &actual){
bool noCollision = true;
//mvprintw(25, 64, "Time: ");
c = getch();
do{
//print barriers
printBarriers();
//print tank
printTank();
//print aliens
printAliens();
//move aliens
shiftAliens(timer);
switch(c)
{
case '6':
if ( tankPositionX < 74){
tankOldPositionX = tankPositionX;
tankPositionX +=3;
erase();
}
c = getch();
break;

case '5':
shootBullet(tankPositionX, tankPositionY, timer);
c = getch();
break;

case '4':
if(tankPositionX > 0){
tankOldPositionX = tankPositionX;
tankPositionX -=3;
erase();
}
c = getch();
break;

case 'q':
break;

default:
c = getch();
break;
}
//update time
timer++;
if(c != 'q' && noCollision){
updateTime(timer, actual);
}
}while(c !='q' && noCollision);

return actual;
}

void updateTime( int ctr, int &time){
if(ctr%3000==0){
time++;
}
attron(COLOR_PAIR(7));
mvprintw(25, 64, "Time: ");
mvprintw(25, 73, "%i",time); 
refresh();
}

void shootBullet(int xPos, int yPos, int timer)
{
yPos -= 1;
xPos += 1;
move(yPos, xPos);
attron(COLOR_PAIR(6));
mvaddch(yPos,xPos,'x');
while(yPos != 0 && !collisionDetection(yPos,xPos) && !barrierCollisionDetection(yPos, xPos)){
	tankOldPositionY = yPos;
	yPos--;
	attron(COLOR_PAIR(5));
	mvaddch(tankOldPositionY,xPos, 'x');
	attron(COLOR_PAIR(6));
	mvaddch(yPos,xPos,'x');
	usleep(20000);
	//refresh();
	shiftAliens(timer);
}
attron(COLOR_PAIR(5));
mvaddch(yPos,xPos, 'x');
refresh(); 
}

void printAliens(){
//set alien color
attron(COLOR_PAIR(2));
for(int i=0; i<39; i++)
{

if (moveAliens[i].alienLife == true)
{
mvaddch(moveAliens[i].alienYpos, moveAliens[i].alienXpos, moveAliens[i].alienCharacter);
}
}
attron(COLOR_PAIR(5));
for(int i=0; i<39; i++)
{
if (moveAliens[i].alienLife == true)
{
mvaddch(moveAliens[i].alienYpos, moveAliens[i].alienXposOld, moveAliens[i].alienCharacter);
}
}
refresh();
return;
}

bool collisionDetection(int yPos, int xPos){
attron(COLOR_PAIR(5));

for(int i=0; i<39; i++)
{

	if(moveAliens[i].alienYpos == yPos && moveAliens[i].alienXpos == xPos)
	{
	mvaddch(moveAliens[i].alienYpos, moveAliens[i].alienXposOld, moveAliens[i].alienCharacter);
	moveAliens[i].alienLife = false;
	return true;
	}
	if(i == 39){
         return true;
        }
	
}

refresh();
return false;


} 

bool barrierCollisionDetection(int yPos, int xPos){
attron(COLOR_PAIR(5));
if(barrierArray[yPos][xPos]==1)
{
	mvaddch(yPos,xPos, '#');
	refresh();
	return true;
}
return false;
}

void alienBullets()
{
int shoot;
srand(time (NULL));

shoot = rand()%12;			
for(int i=0; i<39; i++)
{
shootBullet (moveAliens[i].alienXpos, moveAliens[i].alienYpos, shoot);
}
	
	
	// every tick of clock move existing bullets down
	// collision detection for tank
		// if collision lose a life

}


void shiftAliens(int timer){
if(timer%400 == 0){ 
for(int i = 0; i<39; i++)
{
moveAliens[i].alienXposOld = moveAliens[i].alienXpos;
moveAliens[i].alienXpos += moveAliens[i].alienVelocity;
erase;
refresh();
if(moveAliens[i].alienXpos == 79){
moveAliens[i].alienVelocity = -1;
}
if(moveAliens[i].alienXpos == 0){
moveAliens[i].alienVelocity = 1;
}
}

}
}

void printInstructions(int maxy, int maxx, char name[]){

erase(); // clear screen
attron(COLOR_PAIR(1)); //change color
mvprintw(maxy/4, maxx/2 - 10, "INSTRUCTIONS"); // print instructions, approximately middle of screen
mvprintw(maxy/4+1, maxx/2 - 10, "------------");
mvprintw(maxy/4+3, maxx/2 - 17, "Move: Right Number Pad(4=Left/6=Right)");
mvprintw(maxy/4+4, maxx/2 - 12, "Shoot: 5");
mvprintw(maxy/4+15, maxx/2 - 15, "Enter your Name: ");
getstr(name);
refresh(); //refresh screen
attron(COLOR_PAIR(1));
char in;
scanf("%c", &in);
return;
}

void finish(int sig)
{
endwin();
//do your non-curses wrapup here
// print a nice message
printf ("\nThe Game Has Ended\n");
return;// exit(0);
}

void showMenu(char& input, int maxx, int maxy){
erase(); // clear screen
attron(COLOR_PAIR(1)); //change color
mvprintw(maxy/4, maxx/2 - 10 , "MAIN MENU");
mvprintw(maxy/4+1, maxx/2 - 10, "---------");
mvprintw(maxy/4+3, maxx/2 - 15 , "1. High <S>cores List");
mvprintw(maxy/4+4, maxx/2 - 15 , "2. <P>lay the Game");
mvprintw(maxy/4+5, maxx/2 - 15 , "3. <Q>uit");
mvprintw(maxy/4+6, maxx/2 - 15 , "Enter selection: ");
input = getch();
}

int uploadData(int scoreArr[], char playerArr[][60]){
ifstream fin;
int time, size, index = 0;
char name[60];
char file[20] = "highScores.txt";
fin.clear();
fin.open(file);

if(fin.good())
{
fin.getline(name,60,',');
fin >> time;
fin.get();
while(fin.good())
{
strcpy(playerArr[index],name);
scoreArr[index] = time;
index++;
fin.getline(name,60,',');
fin >> time;
fin.get();
}
}
fin.close();
size = index;
return size;  
}

void displayScores(char playerArr[][60], int scoreArr[], int &size, int maxx, int maxy){
erase();
int index = 0;
int ypos = maxy/4+3; 
char input;
attron(COLOR_PAIR(1)); //change color
mvprintw(maxy/4, maxx/2 - 20 , "HIGH SCORES MENU");
mvprintw(maxy/4+1, maxx/2 - 20, "-----------------");
input = '\0';
while(input != 'q'){
while(index<size){
move(ypos, maxx/2 - 20 );
mvprintw(ypos, maxx/2 - 20 , playerArr[index]);
mvprintw(ypos, maxx/2 - 10 , "%i", scoreArr[index]);
ypos--;
index++;
mvprintw(22, 45, "Press q to return to main menu.");

}
input = getch();
}
}

void barrierCoordinates(){
barrierArray[19][5]= 1;
barrierArray[19][6]= 1;
barrierArray[19][7]= 1;
barrierArray[19][8]= 1;
barrierArray[19][9]= 1;
barrierArray[19][10]= 1;
barrierArray[19][11]= 1;
barrierArray[19][12]= 1;
barrierArray[19][20]= 1;
barrierArray[19][21]= 1;
barrierArray[19][22]= 1;
barrierArray[19][23]= 1;
barrierArray[19][24]= 1;
barrierArray[19][25]= 1;
barrierArray[19][26]= 1;
barrierArray[19][27]= 1;
barrierArray[19][36]= 1;
barrierArray[19][37]= 1;
barrierArray[19][38]= 1;
barrierArray[19][39]= 1;
barrierArray[19][40]= 1;
barrierArray[19][41]= 1;
barrierArray[19][42]= 1;
barrierArray[19][43]= 1;
barrierArray[19][51]= 1;
barrierArray[19][52]= 1;
barrierArray[19][53]= 1;
barrierArray[19][54]= 1;
barrierArray[19][55]= 1;
barrierArray[19][56]= 1;
barrierArray[19][57]= 1;
barrierArray[19][58]= 1;
barrierArray[19][67]= 1;
barrierArray[19][68]= 1;
barrierArray[19][69]= 1;
barrierArray[19][70]= 1;
barrierArray[19][71]= 1;
barrierArray[19][72]= 1;
barrierArray[19][73]= 1;
barrierArray[19][74]= 1;
barrierArray[18][6]= 1;
barrierArray[18][7]= 1;
barrierArray[18][8]= 1;
barrierArray[18][9]= 1;
barrierArray[18][10]= 1;
barrierArray[18][11]= 1;
barrierArray[18][21]= 1;
barrierArray[18][22]= 1;
barrierArray[18][23]= 1;
barrierArray[18][24]= 1;
barrierArray[18][25]= 1;
barrierArray[18][26]= 1;
barrierArray[18][37]= 1;
barrierArray[18][38]= 1;
barrierArray[18][39]= 1;
barrierArray[18][40]= 1;
barrierArray[18][41]= 1;
barrierArray[18][42]= 1;
barrierArray[18][52]= 1;
barrierArray[18][53]= 1;
barrierArray[18][54]= 1;
barrierArray[18][55]= 1;
barrierArray[18][56]= 1;
barrierArray[18][57]= 1;
barrierArray[18][68]= 1;
barrierArray[18][69]= 1;
barrierArray[18][70]= 1;
barrierArray[18][71]= 1;
barrierArray[18][72]= 1;
barrierArray[18][73]= 1;
barrierArray[17][7]= 1;
barrierArray[17][8]= 1;
barrierArray[17][9]= 1;
barrierArray[17][10]= 1;
barrierArray[17][22]= 1;
barrierArray[17][23]= 1;
barrierArray[17][24]= 1;
barrierArray[17][25]= 1;
barrierArray[17][38]= 1;
barrierArray[17][39]= 1;
barrierArray[17][40]= 1;
barrierArray[17][41]= 1;
barrierArray[17][53]= 1;
barrierArray[17][54]= 1;
barrierArray[17][55]= 1;
barrierArray[17][56]= 1;
barrierArray[17][69]= 1;
barrierArray[17][70]= 1;
barrierArray[17][71]= 1;
barrierArray[17][72]= 1;

}
