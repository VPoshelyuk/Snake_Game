//Honors project for CS12 by Viachaslau Pashaliuk
#include <iostream>
#include <time.h> 
#include <stdio.h> 
#include <windows.h> 
#include <conio.h>  

using namespace std;

HANDLE hConsole;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void CoordXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);//Setting cursor position
} 

enum ConsoleColor
{
    Black=0,
	Blue=1,
	Green=2,
	Cyan=3,
	Red=4,
	Purple=5,
	DarkYellow=6,
	LightGray=7,
	DarkGray=8,
	LightBlue=9,
	LightGreen=10,
	LightCyan=11,
	LightRed=12,
	Pink=13,
	Yellow=14,
	White=15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));//Text colors & attributes 
}

class Snake  // Snake structure
{
	public:COORD *t; //Points
	public:int PCount; //Apples count
};
enum directions{LEFT,UP,RIGHT,DOWN}; //directions

class Game 
{
	public:Snake snk; //snake
	public:COORD apple; //apple
	public:int dx,dy; //moves
	public:int pause; //pause
	public:int dir; //direction
	
};

void ApplePlusPlus(Game &g) //Apple adding function
{
	int i,x,y;
	int n = g.snk.PCount;
	do
	{
		x = rand() % 26+3; //
		y = rand() % 19+3; //Apples coordinates
		for(i = 0; i < n; i++)
		{
			if(x == g.snk.t[i].X && y == g.snk.t[i].Y) // Not let snake and apple to appear at the same coordinate
				break;
		}
	}
	while(i < n);
	g.apple.X = x; //
	g.apple.Y = y; //Apple position
	SetConsoleCursorPosition(hConsole, g.apple); //Set cursor position
	SetConsoleTextAttribute(hConsole,0x0c); //Apple color  
	printf("%c", 248); //Apple's symbol
	
}

void GameSpeed(Game &g) //Snake starting point and coordinates assignment+speed
{
	system("cls");//Clear the screen
	g.snk.PCount = 3; //Snake length
	g.snk.t = new COORD [3];//Setting points
	for(int i = 0; i < 3; i++)
	{
		g.snk.t[i].X = 3 + i;
		g.snk.t[i].Y = 5;//Snake starting position
		
	}
	g.dx = 1;
	g.dy = 0;
	g.pause = 100;//Snake speed
	ApplePlusPlus(g);//New apple appears
}

void INFO() //Game info
{
	SetColor(LightBlue , Cyan);CoordXY(20,0);cout << "Snake game by Viachaslau Pashaliuk" <<endl;
	SetColor(LightRed , Black);CoordXY(44,2);cout <<  "Summary:" << endl ; 
	CoordXY(44,3);cout <<  "# of Apples:0" << endl ; 
	CoordXY(44,4); cout <<  "Length:3"<< endl;
	CoordXY(44,5); cout <<  "Speed:1" << endl; 
	CoordXY(44,7); cout << "Control:" <<  endl; 
    CoordXY(44,8); cout << "Esc:Exit" <<  endl; 
	CoordXY(44,9); cout << "P:Pause" <<  endl; 
	CoordXY(44,13);printf("%c",24);cout <<":Up"<<endl; 
	CoordXY(44,14);printf("%c",25);cout<<":Down"<<endl;   
	CoordXY(44,15);printf("%c",27);cout<<":Left"<<endl;  
	CoordXY(44,16);printf("%c",26);cout<<":Right"<<endl;
				{SetColor(LightCyan , Black);
				
                CoordXY(2,2); //Upper Horizontal broad
				int upperlowerlines = 0;
				for(upperlowerlines = 0; upperlowerlines < 30; upperlowerlines++)
				{
					printf("*");
				}
				}
				
				{
					CoordXY(2,24); //Lower Horizontal broad
					int upperlowerlines = 0;
					for(upperlowerlines = 0; upperlowerlines < 30;upperlowerlines++)
					{
						printf("*");
					}
				}
				{	//Vertical Left broad
					CoordXY(2,3); cout << "*"<<endl;
					CoordXY(2,4); cout << "*"<<endl;
					CoordXY(2,5); cout << "*"<<endl;
					CoordXY(2,6); cout << "*"<<endl;
					CoordXY(2,7); cout << "*"<<endl;
					CoordXY(2,8); cout << "*"<<endl;
					CoordXY(2,9); cout << "*"<<endl;
					CoordXY(2,10); cout << "*"<<endl;
					CoordXY(2,11); cout << "*"<<endl;
					CoordXY(2,12); cout << "*"<<endl;
					CoordXY(2,13); cout << "*"<<endl;
					CoordXY(2,14); cout << "*"<<endl;
					CoordXY(2,15); cout << "*"<<endl;
					CoordXY(2,16); cout << "*"<<endl;
					CoordXY(2,17); cout << "*"<<endl;
					CoordXY(2,18); cout << "*"<<endl;
					CoordXY(2,19); cout << "*"<<endl;
					CoordXY(2,20); cout << "*"<<endl;
					CoordXY(2,21); cout << "*"<<endl;
					CoordXY(2,22); cout << "*"<<endl;
					CoordXY(2,23); cout << "*"<<endl;
				}
				{   //Vertical Right broad
					CoordXY(31,3); cout << "*"<<endl;
					CoordXY(31,4); cout << "*"<<endl;
					CoordXY(31,5); cout << "*"<<endl;
					CoordXY(31,6); cout << "*"<<endl;
					CoordXY(31,7); cout << "*"<<endl;
					CoordXY(31,8); cout << "*"<<endl;
					CoordXY(31,9); cout << "*"<<endl;
					CoordXY(31,10); cout << "*"<<endl;
					CoordXY(31,11); cout << "*"<<endl;
					CoordXY(31,12); cout << "*"<<endl;
					CoordXY(31,13); cout << "*"<<endl;
					CoordXY(31,14); cout << "*"<<endl;
					CoordXY(31,15); cout << "*"<<endl;
					CoordXY(31,16); cout << "*"<<endl;
					CoordXY(31,17); cout << "*"<<endl;
					CoordXY(31,18); cout << "*"<<endl;
					CoordXY(31,19); cout << "*"<<endl;
					CoordXY(31,20); cout << "*"<<endl;
					CoordXY(31,21); cout << "*"<<endl;
					CoordXY(31,22); cout << "*"<<endl;
					CoordXY(31,23); cout << "*"<<endl;
				}
}


//Moves and draws
enum {HEADEND, WALL,  PLUS, MOVE};

int Move(Game &g)
{
	int & n = g.snk.PCount;
	COORD head = g.snk.t[n - 1]; //Head
	COORD tail = g.snk.t[0]; //Tail
	COORD next;
	next.X = head.X + g.dx;
	next.Y = head.Y + g.dy; //Check next point towards the move direction
	
    if(next.X < 3 || next.Y < 3 || next.X > 30 || next.Y > 23)//Broad check
		return WALL;
		
	if(n > 4)
	{
		for(int i = 0; i < n; i++)
			if(next.X == g.snk.t[i].X && next.Y == g.snk.t[i].Y) //Check if head and tail aren't at the same coordiante
				return HEADEND;
	}
	
	if(next.X == g.apple.X && next.Y == g.apple.Y)
	{
		COORD*temp = new COORD[ ++n ]; //New array,1 time longer
		for(int i = 0; i < n; i++)
			temp[i] = g.snk.t[i]; 
		temp[n - 1] = next;
		delete [] g.snk.t;
		g.snk.t = temp;
		
		SetConsoleCursorPosition(hConsole,head);
		SetConsoleTextAttribute(hConsole, 0x0c); //HIde an Apple
		printf("*");
		SetConsoleCursorPosition(hConsole,next);
		SetConsoleTextAttribute(hConsole,0x0c);
		printf("%c",1);
		ApplePlusPlus(g);
		return PLUS;
	}
	
	for(int i = 0; i < n - 1; i++)
		g.snk.t[i] = g.snk.t[i + 1];
	g.snk.t[n - 1] = next;
	SetConsoleCursorPosition(hConsole,tail);//Hide tail end
	printf(" ");
	
	SetConsoleCursorPosition(hConsole,head);
	SetConsoleTextAttribute(hConsole, 0x0c);//Tail color
	printf("*");
	SetConsoleCursorPosition(hConsole,next);
	SetConsoleTextAttribute(hConsole,0x0f); //Snake head color 
	printf("%c",1);
	
	return MOVE;
}

int intro()
{
        CoordXY(20,10);
	printf("Welcome to my simple Snake game");
    CoordXY(18,11);
    printf("CS12 project by Viachaslau Pashaliuk");
    CoordXY(20,15);
    printf("Press 'Enter' to start the game");
	getch();
}

int main()
{
 	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Console description 
	intro();
    int key = 0, count = 0,cnt=1;
	bool Pause=false;
	Game g;
	GameSpeed(g);
	INFO();
	srand(time(0));
	bool pause = false;
	while(key != 27)
	{
		while(!kbhit()) //First button press
		{
			if(Pause==true)
			{
				Sleep(1); 
				continue;
			}
			
			switch (Move(g))//Move
			{
				
			case PLUS:
				++count;
				++cnt;
				g.pause-=1;
				SetColor(LightRed , Black);
				CoordXY(44,2);cout <<  "Summary:" << endl ;
				CoordXY(44,3); cout << "# of Apples:" <<count << endl;
				CoordXY(44,4); cout << "Length:" <<g.snk.PCount << endl;
				CoordXY(44,5); cout << "Speed:" <<cnt<< endl;
				CoordXY(44,7); cout << "Control:" <<  endl;
				CoordXY(44,8); cout << "Esc:Exit" <<  endl;
				CoordXY(44,9); cout << "P:Pause" <<  endl;
				CoordXY(44,13);printf("%c",24);cout <<":Up"<<endl;
				CoordXY(44,14);printf("%c",25);cout<<":Down"<<endl;
				CoordXY(44,15);printf("%c",27);cout<<":Left"<<endl;
				CoordXY(44,16);printf("%c",26);cout<<":Right"<<endl;
				if (count == 50) 
				{
                    SetColor(White , Pink);
                    CoordXY(24,1); cout << "You won! Congratulations! Are you a human?" << endl; 
					getch();
					return(0);
				}
				break;
				
			case WALL:
				
			case HEADEND:
				CoordXY(23,1); printf("You will never win!!!Muahahaha\n\n\t\t\t");
				getch();
				break;
			}
			
			Sleep(g.pause); //Delay
		}
	key = getch();
		
    	if(key=='P'||key=='p')
			Pause=!Pause;
		else if(key==0||key==224)
		{
			key=getch();
			
			if(key == 72 && g.dir != DOWN)
			{
				g.dir = UP;
				g.dx = 0;
				g.dy = -1;
			}
			else if(key == 80 && g.dir != UP)
			{
				g.dir = DOWN;
				g.dx = 0;
				g.dy = 1;
			}
			else if(key == 75 && g.dir != RIGHT)
			{
				g.dir = LEFT;
				g.dx = -1;
				g.dy = 0;
			}
			else if(key == 77 && g.dir != LEFT)
			{
				g.dir = RIGHT;
				g.dx = 1;
				g.dy = 0;
			}
		}
	}
}
