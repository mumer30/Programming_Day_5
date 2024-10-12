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
int pX = 20,pY = 35;
int eX = 2, eY = 2;
int e2X = 110 , e2Y = 9;
int e3X = 110, e3Y = 2;
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
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			move_Down();
		}
		move_enemy_ver();
		move_enemy_hor();

		Sleep(200);
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
	if (getCharAtxy(pX - 1, pY) == ' '  &&  getCharAtxy(pX - 1, pY+1) == ' '  &&  getCharAtxy(pX - 1, pY+2) == ' ')
	{
		erase_player();
		pX--;
		print_player();
	}
}
void move_Right()
{
	if (getCharAtxy(pX + 8, pY) == ' '  &&  getCharAtxy(pX + 8, pY+1) == ' '  &&  getCharAtxy(pX + 8, pY+2) == ' ')
	{
		erase_player();
		pX++;
		print_player();
	}
}
void move_Up()
{
	if (getCharAtxy(pX , pY  - 1) == ' '  &&  getCharAtxy(pX +1, pY  - 1) == ' '  &&  getCharAtxy(pX +2, pY  - 1) == ' '  &&  getCharAtxy(pX+3 , pY  - 1) == ' '  &&  getCharAtxy(pX +4, pY  - 1) == ' '  &&  getCharAtxy(pX +5, pY  - 1) == ' '  &&  getCharAtxy(pX +6, pY  - 1) == ' '   &&  getCharAtxy(pX +7, pY  - 1) == ' ')
	{
		erase_player();
		pY--;
		print_player();
	}
}
void move_Down()
{
	if (getCharAtxy(pX, pY + 3) == ' '  &&  getCharAtxy(pX+1, pY + 3) == ' '  &&  getCharAtxy(pX+2, pY + 3) == ' '  &&  getCharAtxy(pX+3, pY + 3) == ' '  &&  getCharAtxy(pX+4, pY + 3) == ' '  &&  getCharAtxy(pX+5, pY + 3) == ' '  &&  getCharAtxy(pX+6, pY + 4) == ' '   &&  getCharAtxy(pX+7, pY + 4) == ' ')
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
	cout <<"#|$$$$$$$$$$$$$|       #     #                #                                    #                      |# |            |"<<endl;
	cout <<"#|$$$$$$$$$$$$$|       #     #            #####                      ###################                  |# |            |"<<endl;
	cout <<"#|                     #######                                                                            |# |            |"<<endl;
	cout <<"#|                                                                                                        |# |            |"<<endl;
	cout <<"#|                             ############                     #                                         |# |            |"<<endl;
	cout <<"#|                             #                                #                                         |# |            |"<<endl;
	cout <<"#|                             #                                #                #########################|# |            |"<<endl;
	cout <<"#|                ##############                                #                                         |# |            |"<<endl;
	cout <<"#|                #                                             #                                         |# |            |"<<endl;
	cout <<"#|                #                                             #                                         |# |            |"<<endl;
	cout <<"#|                #                                  #####################                                |# |            |"<<endl;
	cout <<"#|                #                   #######               #                                ####         |# |            |"<<endl;
	cout <<"#|                #                   #     #               #                                #            |# |            |"<<endl;
	cout <<"#|                #                   #     #               #                                #            |# |            |"<<endl;
	cout <<"#|                #                   #######         #######                                #            |# |            |"<<endl;
	cout <<"#|                #                                                                ###########            |# |            |"<<endl;
	cout <<"#|         ##################              #                                      #                       |# |            |"<<endl;
	cout <<"#|                                         #                                      #                       |# |            |"<<endl;
	cout <<"#|                                         #      ################                #                       |# |            |"<<endl;
	cout <<"#|                                         #              #                       #                       |# |            |"<<endl;
	cout <<"#|                                         #              #                       #                       |# |            |"<<endl;
	cout <<"#|                    ###########                         #                ########                       |# |            |"<<endl;
	cout <<"#|                    #         #                         #                #                              |# |            |"<<endl;
	cout <<"#|                    #         #                         #                #                              |# |            |"<<endl;
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
	cout <<"                                         88 8888 88 88   88  88888   8888       " <<endl;
	Sleep(75);
	cout <<"                                          888  888 888888888 88   88    88     " <<endl;
	Sleep(75);
	cout <<"                                           88  88  88     88 88    888888        " <<endl;
	Sleep(120);
	cout <<endl<<endl<<endl<<endl<<endl;
	cout <<"                                            PRESS    ANY   KEY   TO   CONTINUE  ";

}
	





















































