/*----------------------------------------------
                 HEADERS
------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>




/*----------------------------------------------
                PROTOTYPES
------------------------------------------------*/

void initialize();

void makeEraseString(char buf[], int len);

void printWelcomeScreen(int maxy, int maxx);
void printInstructions(int maxy, int maxx);
void printTank();
void printAliens();
void printBarriers();

void finish(int sig);
double tankPositionX;
double tankPositionY;
double tankVelocityX;
double tankVelocityY;
double tankVelocityChange;


/*----------------------------------------------
                MAIN FUNCTION
------------------------------------------------*/
int main(int argc, char *argv[]){






    //Initialize Variables
    int ch;
    int tank = 1;
    int die = 0;
    int maxx, maxy; //maxx and maxy size of terminal
    tankPositionX = maxx - 70 ;
    tankPositionY = maxy - 2;
    //Start Curses
    initialize();
    getmaxyx(stdscr, maxy, maxx);      // get current screen size 
     

       //Display Tittle Screen
       printWelcomeScreen(maxy, maxx);    // Print welcome screen
       //erase();
   
       printInstructions(maxy, maxx);
       //erase();

     //Start Loop  

	  //print tank
	  //printTank();
	
	wclear( stdscr );
	wmove( stdscr, 22, 10);
	waddstr( stdscr, (char*)"/-^-\\");
	
	wmove( stdscr, 15, 45);
	
	//wmove( stdscr, 22, 12);
	//waddch( stdscr, '?');
	wrefresh( stdscr ); 
	

/*ch = wgetch( stdscr );
switch(ch)
{
   case KEY_LEFT:
	tankPositionX --;
   break;

   case KEY_RIGHT:
	tankPositionX ++;
   break;
			
}*/	

     //print aliens 
     printAliens();
     
     //print barriers
     printBarriers();
     erase();
    

 

      //print menu screen 

      //if '1' , show score board 

      //else if '2' , play the game

      
      //End Curses
      //finish(0);
     
      //End Program 
      return 0;

}


/*----------------------------------------------
                 FUNCTIONS
------------------------------------------------*/

void initialize(){
 //terminal graphics
 
 intrflush( stdscr, FALSE );
 (void) initscr(); //initializes the curses library
 start_color();
 (void) keypad(stdscr, TRUE); //enable keyboard mapping
 nonl(); //tells curses not to do NL-> CR/NL on output
 (void) cbreak(); //take input chars one at a time
 (void) noecho(); //dont echo input
 init_pair(1, COLOR_BLUE, COLOR_BLACK);
 init_pair(2, COLOR_RED, COLOR_RED); 
 init_pair(3, COLOR_GREEN , COLOR_GREEN);
 init_pair(4, COLOR_BLUE, COLOR_BLUE);
 //initialize game global variables
 

 //tank
 double tankVelocityX = 0.0001; 
 double tankVelocityY = 0.0;
 double tankVelocityChage = 0.0005;
// double tankPositionX = maxx - 70 ;
// double tankPositionY = maxy - 2;
 double speed_shotX = 0.0; 
 double speed_shotY = 0.0005; //speed of the bullet in y dir.

 //alien
 double alienVelocityX = 0.0001;
 double alienVelocityY = 0.0;
 //double alienPositionX = ;
 //double alienPositionY = ;
}




void makeEraseString(char buf[], int len){
  for(int i = 0; i < len; i++){
    buf[i] = ' ';
  }
  buf[len] = '\0';
  return;
}

void drawBoard()
{
char drawBoard[100][100] = { 

    {"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"},
    {"!                @                  !"},
    {"!               @ @                 !"},
    {"!              @ @ @                !"},
    {"!             @ @ @ @               !"},
    {"!            @ @ @ @ @              !"},
    {"! @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ !"},
    {"!            @ @ @ @ @              !"},
    {"!             @ @ @ @               !"},
    {"!              @ @ @                !"},
    {"!               @ @                 !"},
    {"!                @                  !"},
    {"!                                   !"},
    {"!                                   !"},
    {"!                                   !"},
    {"!                                   !"},
    {"!                                   !"},
    {"!                                   !"},
    {"!                X                  !"},
    {"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"}
};
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
 char in;
 scanf("%c", &in);
 attroff(COLOR_PAIR(1)); // go back to default colors


return;
}



void printWelcomeScreen(int maxy, int maxx){
  erase(); // clear screen
  attron(COLOR_PAIR(1));  //change color
  mvprintw(maxy/4, maxx/2 - 15, "Welcome to !(Space Invaders)"); // print welcome, approximately middle of screen
  mvprintw(maxy/4+1, maxx/2 - 15, "----------------------------");
  //mvprintw(maxy/4+15, maxx/2 - 15, "press any key to continue...");
  refresh(); //refresh screen
  attroff(COLOR_PAIR(1)); // go back to default colors
  sleep(5); // sleep for a second by calling the linux/unix sleep library call
  //char in;
  //scanf("%c", &in);	
  return;
}


void printTank(){
 attron(COLOR_PAIR(3));
 mvaddch(22,2, 'x');
 mvaddch(22,3, 'x');
 mvaddch(22,4, 'x');
 refresh(); //refresh screen

}


void printAliens(){
 
 //set alien color
 attron(COLOR_PAIR(2));
 //column one
 mvaddch(12,22, 'x');
 mvaddch(9,22, 'a');
 mvaddch(6,22, 'v');
 mvaddch(3,22, 'k');
 //Column two
 mvaddch(12,23, 'x');
 mvaddch(9,23, 'a');
 mvaddch(6,23, 'v');
 mvaddch(3,23, 'k');
 //column three
 mvaddch(12,24, 'x');
 mvaddch(9,24, 'a');
 mvaddch(6,24, 'v');
 mvaddch(3,24, 'k');
 //column four
 mvaddch(12,30, 'x');
 mvaddch(9,30, 'a');
 mvaddch(6,30, 'v');
 mvaddch(3,30, 'k');
 //column five
 mvaddch(12,31, 'x');
 mvaddch(9,31, 'a');
 mvaddch(6,31, 'v');
 mvaddch(3,31, 'k');
 //column six
 mvaddch(12,32, 'x');
 mvaddch(9,32, 'a');
 mvaddch(6,32, 'v');
 mvaddch(3,32, 'k');
 //column seven
 mvaddch(12,38, 'x');
 mvaddch(9,38, 'a');
 mvaddch(6,38, 'v');
 mvaddch(3,38, 'k');
 //column eight
 mvaddch(12,39, 'x');
 mvaddch(9,39, 'a');
 mvaddch(6,39, 'v');
 mvaddch(3,39, 'k');
 //column nine
 mvaddch(12,40, 'x');
 mvaddch(9,40, 'a');
 mvaddch(6,40, 'v');
 mvaddch(3,40, 'k');
 //column ten
 mvaddch(12,46, 'x');
 mvaddch(9,46, 'a');
 mvaddch(6,46, 'v');
 mvaddch(3,46, 'k');
 //column eleven
 mvaddch(12,47, 'x');
 mvaddch(9,47, 'a');
 mvaddch(6,47, 'v');
 mvaddch(3,47, 'k');
 //column twelve
 mvaddch(12,48, 'x');
 mvaddch(9,48, 'a');
 mvaddch(6,48, 'v');
 mvaddch(3,48, 'k');
 //column thirteen
 mvaddch(12,54, 'x');
 mvaddch(9,54, 'a');
 mvaddch(6,54, 'v');
 mvaddch(3,54, 'k');
 //column fourteen
 mvaddch(12,55, 'x');
 mvaddch(9,55, 'a');
 mvaddch(6,55, 'v');
 mvaddch(3,55, 'k');
 //column fifteen
 mvaddch(12,56, 'x');
 mvaddch(9,56, 'a');
 mvaddch(6,56, 'v');
 mvaddch(3,56, 'k');

 return;
}




void printInstructions(int maxy, int maxx){
 erase(); // clear screen
 attron(COLOR_PAIR(1));  //change color
 mvprintw(maxy/4, maxx/2 - 10, "INSTRUCTIONS"); // print instructions, approximately middle of screen
 mvprintw(maxy/4+1, maxx/2 - 10, "------------"); 
 mvprintw(maxy/4+3, maxx/2 - 15, "Move: Arrows(Left/Right)");
 mvprintw(maxy/4+4, maxx/2 - 15, "Shoot: Spacebar");
 //mvprintw(maxy/4+15, maxx/2 - 15, "press any key to continue...");
 
 refresh(); //refresh screen
 attroff(COLOR_PAIR(1)); // go back to default colors
 sleep(7); // sleep for a second by calling the linux/unix sleep library call
 //char in;
 //scanf("%c", &in);
 return;
}



void finish(int sig)
{
    endwin();
    //do your non-curses wrapup here 
    // print a nice message
    
    printf ("\nThe Game Has Ended\n");
 
    return;//    exit(0);
}

void gameboard()
{

}



//draw something 
/*
attron(COLOR_PAIR(2));
mvaddch(5,5, 'x');
mvaddch(4,5, 'x');
mvaddch(3,5, 'x');
refresh(); //refresh screen
  attroff(COLOR_PAIR(1)); // go back to default colors
  char in;
  scanf("%c", &in);
	erase();   
     //Display Tittle Screen
	  printWelcomeScreen(maxy, maxx); 
scanf("%c", &in);
*/
