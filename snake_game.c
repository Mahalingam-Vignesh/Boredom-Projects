#include<stdio.h>			// For Description of code, scroll down.
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>

#define X 25				// Defines boundary of the game.
#define Y 120

char a[100];				// Name of the player.
char b[X][Y];				// Game area.
char ch ='R';				// Direction (Default is right).
char hit;				// To check for collision.
int score = 0;				// Score of the player.
bool alive=true;			// To check for life.
time_t t;				// To set seed for Random number using time header file.


struct snake				// Snake's body.
{

int v;					// co-ordinates vertical and horizontal as v and h respectively.
int h;
char dir;				// Gives the direction of movement of particular piece of body (Default is right). 
struct snake* next;			// Link between two pieces of body of the snake.

};

typedef struct snake snake;		// type defing so as not to use struct again and again.
snake* temp;				// The Head and the Tail of the snake.
snake* tail;

//Functions used and its purpose

int home();							// Home Page. 				
int second();							// For entering player's name.	
int third();							// Information Regarding Games.
int gamescene();						// Intializing the game field.
snake*  creation(int v1, int h1, char dir1, snake* pre);	// Linked list creation for snake.
int direction();						// To check for Keyboard input, so to change the direction and to pause the game.
int movement();							// Movement of the snake.
int setfood();						
void gotoxy(int x,int y);


void main()
{

t=time(NULL);
home();					// Line No. 85
second();				// Line No. 100
third();				// Line No. 111
gamescene();				// Line No. 139

while(alive)				// Loop in the game, until the player dies.
{

if(kbhit())				// checks for keyboard hit for change of direction.
{
direction();				// Line No. 198
}
movement();				// Line No. 253				

}

system("cls");				// End of the game.
system("color F4");
gotoxy(55,13);				// Line No. 78
printf("gameover!");
gotoxy(40,18);				// Line No. 78
printf("%s, your score is %d.Better Luck next time!",a,score);
getch();

}


void gotoxy(int x,int y)
{

printf("%c[%d;%df",0x1B,y,x);    // vertical horizontal

}

int home()
{

system("cls");
system("color 8f");
gotoxy(55,13);				// Line No. 78
printf("Snakes!");
gotoxy(40,18);				// Line No. 78
printf("Press any button to begin the game!");
getch();
return 0;

}


int second()
{

system("cls");
gotoxy(40,13);				// Line No. 79
printf("Enter your name:\t");
scanf("%[^\n]%*c",a);
return 0;

}

int third()
{

int pos=12;
system("cls");
gotoxy(40,pos);				// Line No. 78
printf("Are you ready %s?",a);
++pos;
gotoxy(40,++pos);
printf("Rules:");
gotoxy(40,++pos);			// Line No. 78
printf("Press arrow key to change the direction.");
gotoxy(40,++pos);			// Line No. 78
printf("Eat the food which is represented with letter F.");
gotoxy(40,++pos);			// Line No. 78
printf("Avoid hitting yourself and the boundary.");
gotoxy(40,++pos);			// Line No. 78
printf("Maximize the screen, if you are unable to view the boundary as whole.");
gotoxy(40,++pos);
printf("Press p to pause the game and to resume press any arrow key.");
++pos;
gotoxy(40,++pos);			// Line No. 78
printf("Press any Key to begin");
getch();
return 0;

}

int gamescene()								// Intialize the game ground
{

system("cls");
system("color 0a");

for(int a1=0;a1<X;a1++)
{
for(int a2=0;a2<Y;a2++)
{
b[a1][a2]=' ';
if(a2==(Y-1))
{
b[a1][a2]='\n';
}
else if((a1==0)||(a1==(X-1))||(a2==0)||(a2==(Y-2)))
{
b[a1][a2]='#';
}
}
}


snake* temp2=malloc(sizeof(snake));
snake* head=creation(12,60,ch,temp2);			// Line No. 185
snake* h1=creation(12,59,ch,head);
snake* h2=creation(12,58,ch,h1);
snake* h3=creation(12,57,ch,h2);
tail = h3;
temp = head;

for(int a3=(head->h);a3>=(h3->h);a3--)
{
b[12][a3]='*';
}

setfood();						// Line No. 353

system("cls");
printf("%s",b);
printf("\rYour current score is %d",score);
return 0;

}


snake*  creation(int v1, int h1, char dir1, snake* pre)		// To create snake length dynamically, with increase in eating of food.
{

snake* temp11 = malloc(sizeof(snake));
temp11->v = v1;
temp11->h = h1;
temp11->dir = dir1;
temp11->next = NULL;
pre->next = temp11;
return temp11;

}

int direction()							// The function changes the direction of head
{

int ch1,ch2;
char v = ch;
ch1=getch();
if(ch1==0xE0)
{
ch2=getch();
switch(ch2)
{
case 72:
ch='U';
break;
case 80:
ch='D';
break;
case 75:
ch='L';
break;
case 77:
ch='R';
break;
default:
break;
}
}
else if(ch1=='p')
{
system("cls");
printf("%s",b);
printf("\rPaused, press any arrow key to resume!");
bool pt = true;
while(pt)
{

Sleep(500);
if(kbhit())
{
pt=false;
}

}
}
if(((v=='R')&&(ch=='L'))||((v=='L')&&(ch=='R'))||((v=='U')&&(ch=='D'))||((v=='D')&&(ch=='U')))
{

ch=v;								// To prohibit the opposite direction movement

}

return 0;

}

int movement()							// The function updates the 'b' from linked list, clears the screen and print 'b' repeatedly so as to look like in motion
{								// Also checks for collision with boundary and itself, as well as the food.

char n,o;
Sleep(100);
snake* temp3=temp;
n=ch;
while(temp3!=NULL)
{

o=temp3->dir;
temp3->dir=n;
switch(temp3->dir)
{

case 'R':
b[temp3->v][temp3->h]=' ';
temp3->h++;
hit=b[temp3->v][temp3->h];
b[temp3->v][temp3->h]='*';
break;
case 'L':
b[temp3->v][temp3->h]=' ';
temp3->h--;
hit=b[temp3->v][temp3->h];
b[temp3->v][temp3->h]='*';
break;
case 'U':
b[temp3->v][temp3->h]=' ';
temp3->v--;
hit=b[temp3->v][temp3->h];
b[temp3->v][temp3->h]='*';
break;
case 'D':
b[temp3->v][temp3->h]=' ';
temp3->v++;
hit=b[temp3->v][temp3->h];
b[temp3->v][temp3->h]='*';
break;
default:
break; 

}
if((hit=='#')||(hit=='*'))
{

alive=false;
return 0;

}
else if(hit=='F')
{

printf("\a");
setfood();							// Line No. 353
score++;
int vv1, hh1;
if(tail->dir == 'R')
{

vv1=tail->v;
hh1=(tail->h)-1;

}
else if(tail->dir == 'L')
{

vv1=tail->v;
hh1=(tail->h)+1;

}
else if(tail->dir == 'U')
{

vv1=(tail->v)+1;
hh1=tail->h;

}
else if(tail->dir == 'D')
{

vv1=(tail->v)-1;
hh1=tail->h;

}
snake* temp13=creation(vv1,hh1,tail->dir,tail);			// Line No. 185
tail = temp13;

}
n=o;
temp3=temp3->next;

}
system("cls");
printf("%s",b);
printf("\rYour current score is %d",score);
return 0;

}

int setfood()							// The function decides the random position of food, when called and stores in 'b'.
{
srand(t);
t++;
int f1 = (rand() % (X-2)) + 0;
int f2 = (rand() % (Y-2)) + 0;
if((b[f1][f2]=='#')||(b[f1][f2]=='*'))
{

setfood();							// Line No. 353

}
else
{

b[f1][f2]='F';
return 0;

}

}


/*	Representation(You find while running):

	Boundary	:	'#'
	Snake		:	'*'
	Food		:	'F'
	Empty place	:	' '	*/


/*	Description of code:

	Intially, Name of the player is fetched and stored in Character array 'a'.
	Character array 'b' is created with the dimension of X and Y defined in Macro.
  	Boundaries, which are a1=0, a1=X-2, b1=0 and b1=Y-2, set as '#' to the Character array 'b'.
	For a1=X-1 and b1=Y-1, the 'b' is set as '\n' (New line command).
	Snake's location is stored in Linked list named 'snake' along with the direction.
	Each node of 'snake' represent a piece of the snake's body, holding position, direction and pointer to the next piece.
	With seeded random number, Food is placed at different spot, written in the string 'b'.
	Variable hit checks for collision.
	hit is nothing but the character, the head strikes.
	It can be ' ', 'F', '#' and '*'.
	Former two, are safe and latter two, means collision
	Score increases with each 'F', it consumes and it notifies/beeps sound.					
	p button is dedicated to pause the game, with help of Sleep() and can be resumed with any arrow keys.		*/

/*	Movement:

	'b' is set as '*' from position of snake in the linked list. 
	Along the direction, Linked list value is updated.
	This is then updated to 'b' regularly.
	'b'is cleared and printed regurlary after 0.1s.
	This seems to be snake in Motion.
	If there is input, which is arrow key, the direction of head is changed.
	The changed direction is then updated to the next piece of snake through iteration of snakesize.	*/

/*	Behind the code:

	Mahalingam Vignesh N P's version of cliche.
	Time Taken : 4 hours.
	If you find any suggestion, feel free to email : npmlvignesh10@gmail.com								*/ 

	   