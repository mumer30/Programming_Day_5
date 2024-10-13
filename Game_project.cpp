#include<iostream>
#include<windows.h>
#include<conio.h>


using namespace std;
char getCharAtxy(short int x, short int y);
void gotoxy(int x,int y);
void move_Right();
void move_Left();
void move_Up();
void move_Down();
void print_maze();
void print_player();
void erase_player();
void print_enemy_hor();
void erase_enemy_hor();
void move_enemy_hor();
void print_enemy_ver();
void clear_enemy_ver();
void move_enemy_ver();
void print_enemy_dia();
void print_front();
void print_bonus();
void player_win();
int pX = 10,pY = 35;
int eX = 2, eY = 2;
int e2X = 110 , e2Y = 9;
int e3X = 110, e3Y = 2;
int p1X = 27,p1Y=33; 
int p2X = 96,p2Y=10; 
int p3X = 50,p3Y=9;
int p4X = 56,p4Y=26;
int p5X = 22,p5Y=19;
int p6X = 20,p6Y=13;
int w1X = 7,w1Y=10;
int w2X = 10,w2Y=10;
int score=0;
int count=0;
main()
{
	system("cls");
	print_front();
	getch();
	system("cls");
	print_maze();
	print_player();
	print_enemy_dia();
	while(true)
	{
		move_enemy_ver();
		move_enemy_hor();
		if (GetAsyncKeyState(VK_LEFT))
		{
			move_Left();
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			move_Right();
			
		}
		if (GetAsyncKeyState(VK_UP))
		{
			move_Up();
			if (count != 0)
			{
				break;
			} 
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			move_Down();
		}
		gotoxy(130, 5);
        cout << "Score: " << score;
		Sleep(100);
		
	}
	
}
void gotoxy(int X,int Y)
{
	COORD coordinates;
	coordinates.X=X;
	coordinates.Y=Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}


void print_player()
{
	gotoxy(pX,pY);
	cout <<"  __  "<<endl;
	gotoxy(pX,pY+1);
	cout <<" /  \\ "<<endl;
	gotoxy(pX,pY+2);
	cout <<"/||||\\"<<endl;
}

void erase_player()
{
	gotoxy(pX,pY);
	cout <<"        "<<endl;
	gotoxy(pX,pY+1);
	cout <<"        "<<endl;
	gotoxy(pX,pY+2);
	cout <<"        "<<endl;
}

void move_Left()
{
	if ((getCharAtxy(pX - 1, pY) != '#'  &&  getCharAtxy(pX - 1, pY+1) != '#'  &&  getCharAtxy(pX - 1, pY+2) != '#') && (getCharAtxy(pX - 1, pY) != '|'  &&  getCharAtxy(pX - 1, pY+1) != '|'  &&  getCharAtxy(pX - 1, pY+2) != '|'))
	{
		erase_player();
		pX--;
		print_player();
		if ((pX == p1X && pY == p1Y) ||(pX   == p1X && pY == p1Y+1) ||(pX   == p1X && pY == p1Y+2) ||(pX   == p1X && pY == p1Y+3) ||(pX   == p1X && pY == p1Y+4))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX== p2X && pY == p2Y) ||(pX  == p2X && pY+1 == p2Y) ||(pX   == p2X && pY+2 == p2Y) ||(pX   == p2X && pY+3 == p2Y) ||(pX   == p2X && pY+4 == p2Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX == p3X && pY == p3Y) ||(pX   == p3X && pY+1 == p3Y) ||(pX   == p3X && pY+2 == p3Y) ||(pX   == p3X && pY+3 == p3Y) ||(pX   == p3X && pY+4 == p3Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX == p4X && pY == p4Y) ||(pX == p4X && pY+1 == p4Y) ||(pX   == p4X && pY+2 == p4Y) ||(pX   == p4X && pY+3 == p4Y) ||(pX   == p4X && pY+4 == p4Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX== p5X && pY == p5Y) ||(pX   == p5X && pY+1 == p5Y) ||(pX   == p5X && pY+2 == p5Y) ||(pX  == p5X && pY+3 == p5Y) ||(pX   == p5X && pY+4 == p5Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX== p6X && pY == p6Y) ||(pX   == p6X && pY+1 == p6Y) ||(pX   == p6X && pY+2 == p6Y) ||(pX   == p6X && pY+3 == p6Y) ||(pX   == p6X && pY+4 == p6Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
	}
	
}
void  move_Right()
{
	if ((getCharAtxy(pX + 8, pY) != '#'  &&  getCharAtxy(pX + 8, pY+1) != '#'  &&  getCharAtxy(pX + 8, pY+2) != '#')  &&  (getCharAtxy(pX + 8, pY) != '|'  &&  getCharAtxy(pX + 8, pY+1) != '|'  &&  getCharAtxy(pX + 8, pY+2) != '|'))
	{
		erase_player();
		pX++;
		print_player();
		if ((pX + 6== p1X && pY == p1Y) ||(pX + 6  == p1X && pY == p1Y+1) ||(pX + 6  == p1X && pY == p1Y+2) ||(pX + 6  == p1X && pY == p1Y+3) ||(pX + 6  == p1X && pY == p1Y+4))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX + 6== p2X && pY == p2Y) ||(pX + 6  == p2X && pY+1 == p2Y) ||(pX + 6  == p2X && pY+2 == p2Y) ||(pX + 6  == p2X && pY+3 == p2Y) ||(pX + 6  == p2X && pY+4 == p2Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX + 6== p3X && pY == p3Y) ||(pX + 6  == p3X && pY+1 == p3Y) ||(pX + 6  == p3X && pY+2 == p3Y) ||(pX + 6  == p3X && pY+3 == p3Y) ||(pX + 6  == p3X && pY+4 == p3Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX + 6== p4X && pY == p4Y) ||(pX + 6  == p4X && pY+1 == p4Y) ||(pX + 6  == p4X && pY+2 == p4Y) ||(pX + 6  == p4X && pY+3 == p4Y) ||(pX + 6  == p4X && pY+4 == p4Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX + 6== p5X && pY == p5Y) ||(pX + 6  == p5X && pY+1 == p5Y) ||(pX + 6  == p5X && pY+2 == p5Y) ||(pX + 6  == p5X && pY+3 == p5Y) ||(pX + 6  == p5X && pY+4 == p5Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX + 6== p6X && pY == p6Y) ||(pX + 6  == p6X && pY+1 == p6Y) ||(pX + 6  == p6X && pY+2 == p6Y) ||(pX + 6  == p6X && pY+3 == p6Y) ||(pX + 6  == p6X && pY+4 == p6Y))
		{
            score++;
            p1X = -1;
            p1Y = -1;
        }
		
	}
}


void move_Up()
{
	if (getCharAtxy(pX , pY  - 1) != '#'  &&  getCharAtxy(pX +1, pY  - 1) != '#'  &&  getCharAtxy(pX +2, pY  - 1) != '#'  &&  getCharAtxy(pX+3 , pY  - 1) != '#'  &&  getCharAtxy(pX +4, pY  - 1) != '#'  &&  getCharAtxy(pX +5, pY  - 1) != '#'  &&  getCharAtxy(pX +6, pY  - 1) != '#'   &&  getCharAtxy(pX +7, pY  - 1) != '#')
	{
		erase_player();
		pY--;
		print_player();
		if ((pX  == p1X && pY == p1Y) ||(pX+1  == p1X && pY == p1Y) ||(pX+2  == p1X && pY == p1Y) ||(pX+3  == p1X && pY == p1Y) ||(pX+4  == p1X && pY == p1Y))
        {
            score++;
            p1X = -1;
            p1Y = -1;
        }
		else if ((pX  == p2X && pY == p2Y) ||(pX+1  == p2X && pY == p2Y) ||(pX+2  == p2X && pY == p2Y) ||(pX+3  == p2X && pY == p2Y) ||(pX+4  == p2X && pY == p2Y))
        {
            score++;
            p2X = -1;
            p2Y = -1;
        }
		else if ((pX  == p3X && pY == p3Y) ||(pX+1  == p3X && pY == p3Y) ||(pX+2  == p3X && pY == p3Y) ||(pX+3  == p3X && pY == p3Y) ||(pX+4  == p3X && pY == p3Y))
        {
            score++;
            p3X = -1;
            p3Y = -1;
        }
		else if ((pX  == p4X && pY == p4Y) ||(pX+1  == p4X && pY == p4Y) ||(pX+2  == p4X && pY == p4Y) ||(pX+3  == p4X && pY == p4Y) ||(pX+4  == p4X && pY == p4Y))
        {
            score++;
            p4X = -1;
            p4Y = -1;
        }
		else if ((pX  == p5X && pY == p5Y) ||(pX+1  == p5X && pY == p5Y) ||(pX+2  == p5X && pY == p5Y) ||(pX+3  == p5X && pY == p5Y) ||(pX+4  == p5X && pY == p5Y))
        {
            score++;
            p5X = -1;
            p5Y = -1;
        }
		else if ((pX  == p6X && pY == p6Y) ||(pX+1  == p6X && pY == p6Y) ||(pX+2  == p6X && pY == p6Y) ||(pX+3  == p6X && pY == p6Y) ||(pX+4  == p6X && pY == p6Y))
        {
            score++;
            p6X = -1;
            p6Y = -1;
        }
		else if ((pX  == w1X && pY == w1Y) ||(pX+1  == w1X && pY == w1Y) ||(pX+2  == w1X && pY == w1Y) ||(pX+3  == w1X && pY == w1Y) ||(pX+4  == w1X && pY == w1Y))
        {
            player_win();
			count++;
        }
		else if ((pX  == w2X && pY == w2Y) ||(pX+1  == w2X && pY == w2Y) ||(pX+2  == w2X && pY == w2Y) ||(pX+3  == w2X && pY == w2Y) ||(pX+4  == w2X && pY == w2Y))
        {
            player_win();
			count++;
        }
	
	}
	
}
void move_Down()
{
	if (getCharAtxy(pX, pY + 3) != '#'  &&  getCharAtxy(pX+1, pY + 3) != '#'  &&  getCharAtxy(pX+2, pY + 3) != '#'  &&  getCharAtxy(pX+3, pY + 3) != '#'  &&  getCharAtxy(pX+4, pY + 3) != '#'  &&  getCharAtxy(pX+5, pY + 3) != '#'  &&  getCharAtxy(pX+6, pY + 3) != '#'   &&  getCharAtxy(pX+7, pY + 3) != '#')
	{
		erase_player();
		pY++;
		print_player();
	}
	
}			
       
char getCharAtxy(short int x, short int y)
{

	CHAR_INFO ci;
	COORD xy = {0, 0};
	SMALL_RECT rect = {x, y, x, y};
	COORD coordBufSize;
	coordBufSize.X = 1;
	coordBufSize.Y = 1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar: ' ';

}

void print_enemy_hor()
{
	gotoxy(eX,eY);
	cout <<"\\\\|||// ";
	gotoxy(eX,eY+1);
	cout <<"  @@@   ";
	gotoxy(eX,eY+2);
	cout <<"   *   ";
}
void erase_enemy_hor()
{
	gotoxy(eX,eY);
	cout <<"        ";
	gotoxy(eX,eY+1);
	cout <<"        ";
	gotoxy(eX,eY+2);
	cout <<"        ";
}
void move_enemy_hor()
{
	erase_enemy_hor();
	eX = eX + 1;
	if (eX == 88)
	{
		erase_enemy_hor();
		eX = 2;
	}
	print_enemy_hor();
}
void print_enemy_dia()
{
	gotoxy(e3X,e3Y);
	cout <<"  <(--)>/)";
	gotoxy(e3X,e3Y+1);
	cout <<"<----)///>";
	gotoxy(e3X,e3Y+2);
	cout <<"* <(-)>";
}


void print_enemy_ver()
{
	gotoxy(e2X,e2Y);
	cout <<"   /---|";
	gotoxy(e2X,e2Y+1);
	cout <<" *(@@@@|";
	gotoxy(e2X,e2Y+2);
	cout <<"   \\---|";
}
void erase_enemy_ver()
{
	gotoxy(e2X,e2Y);
	cout <<"        ";
	gotoxy(e2X,e2Y+1);
	cout <<"        ";
	gotoxy(e2X,e2Y+2);
	cout <<"        ";
}
void move_enemy_ver()
{
	erase_enemy_ver();
	e2Y = e2Y + 1;
	if (e2Y == 36)
	{
		erase_enemy_ver();
		e2Y = 9;
	}
	print_enemy_ver();
}

void print_maze()
{
	cout <<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout <<"|                                                                                                         ||              |"<<endl;
	cout <<"|                                                                                                         ||              |"<<endl; 
	cout <<"|                                                                                                         ||              |"<<endl;
	cout <<"|                                                                                                         ||              |"<<endl;	
	cout <<"|                                                                                                         ||              |"<<endl;					
	cout <<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout <<"###########################################################################################################  --------------"<<endl;
	cout <<"#|$$$$$$$$$$$$$|                              #                                    #                      |# |            |"<<endl;
	cout <<"#|$$$$$$$$$$$$$|       #######                #                                    #                      |# |            |"<<endl;
	cout <<"#|$$$$$$$$$$$$$|       #     #                #                                    #            @         |# |            |"<<endl;
	cout <<"#|$$$$$$$$$$$$$|       #     #            #####                      ###################                  |# |            |"<<endl;
	cout <<"#|                     #######                                                                            |# |            |"<<endl;
	cout <<"#|                                                                                                        |# |            |"<<endl;
	cout <<"#|                    @        ############                     #                                         |# |            |"<<endl;
	cout <<"#|                             #                                #                                         |# |            |"<<endl;
	cout <<"#|                             #                                #                #########################|# |            |"<<endl;
	cout <<"#|                ##############                                #                                         |# |            |"<<endl;
	cout <<"#|                #                                             #                                         |# |            |"<<endl;
	cout <<"#|                #   @                                         #                                         |# |            |"<<endl;
	cout <<"#|                #                                  #####################                                |# |            |"<<endl;
	cout <<"#|                #                   #######               #                                ####         |# |            |"<<endl;
	cout <<"#|                #                   #     #               #                                #            |# |            |"<<endl;
	cout <<"#|                #                   #     #               #                                #            |# |            |"<<endl;
	cout <<"#|                #                   #######         #######                                #            |# |            |"<<endl;
	cout <<"#|                #                                                                ###########            |# |            |"<<endl;
	cout <<"#|         ##################              #             @                        #                       |# |            |"<<endl;
	cout <<"#|                                         #                                      #                       |# |            |"<<endl;
	cout <<"#|                                         #      ################                #                       |# |            |"<<endl;
	cout <<"#|                                         #              #                       #                       |# |            |"<<endl;
	cout <<"#|                                         #              #                       #                       |# |            |"<<endl;
	cout <<"#|                    ###########                         #                ########                       |# |            |"<<endl;
	cout <<"#|                    #         #                         #                #                              |# |            |"<<endl;
	cout <<"#|                    #    @    #                         #                #                              |# |            |"<<endl;
	cout <<"#|#####################         #############################              #####################          |# |            |"<<endl;
	cout <<"#|                                                                                                        |# |            |"<<endl;
	cout <<"#|                                                                                                        |# |            |"<<endl;
	cout <<"#|                                                                                                        |# |            |"<<endl;
	cout <<"#|                                                                                                        |# |            |"<<endl;
	cout <<"############################################################################################################ --------------"<<endl;
}


void print_front()
{
	cout <<endl<<endl<<endl<<endl;
	cout <<"                                           8888888888   888    88888        " <<endl;
	Sleep(75);
	cout <<"                                          88     88    88 88   88  88       " <<endl;
	Sleep(75);
	cout <<"                                           8888  88   88   88  88888        " <<endl;
	Sleep(75);
	cout <<"                                              88 88  888888888 88   88       " <<endl;
	Sleep(75);
	cout <<"                                      888888888  88  88     88 88    8888888" <<endl;
	Sleep(75);
	cout <<"                                                          " <<endl;
	Sleep(75);
	cout <<"                                        88  88  88   888    88888   888888    " <<endl;
	Sleep(75);
	cout <<"                                        88  88  88  88 88   88  88 88         " <<endl;
	Sleep(75);
	cout <<"                                        88 8888 88 88   88  88888   8888       " <<endl;
	Sleep(75);
	cout <<"                                         888  888 888888888 88   88    88     " <<endl;
	Sleep(75);
	cout <<"                                          88  88  88     88 88    888888        " <<endl;
	Sleep(120);
	cout <<endl<<endl<<endl<<endl<<endl;
	cout <<"                                            PRESS    ANY   KEY   TO   CONTINUE  ";

}

void player_win()
{
	system("cls");
	cout <<endl<<endl<<endl;
	cout <<endl<<endl<<endl;
	cout <<endl<<endl<<endl;
	cout <<"             @   @  @@  @   @      @       @  @@@@@  @@    @  "<<endl;
	cout <<"             @   @ @  @ @   @      @       @    @    @ @   @"<<endl;
	cout <<"              @@@  @  @ @   @      @   @   @    @    @  @  @"<<endl;
	cout <<"               @   @  @ @   @      @ @   @ @    @    @   @ @"<<endl;
	cout <<"               @    @@   @@@       @@     @@  @@@@@  @    @@" <<endl;   
}
	





















































