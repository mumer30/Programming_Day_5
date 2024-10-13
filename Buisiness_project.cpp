#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
void gotoxy(int X,int Y);
void print_front();
void disply_front();
void print_front();
void print_header();
void sign_up_menu();
void Login_menu();
int choice_menu();
void add_record();
void update_record();
void show_record();
void delete_record();
void search_record();
void exit_menu();
void print_box();
void exit_menu();
string user_name,password;
main()
{	
	system("cls");
	disply_front();
	system("cls");
	val2:
	sign_up_menu();	
	system("cls");
	Login_menu();
	system("cls");
	int op = choice_menu();
	if (op  ==  1)
	{
		system("cls");
		add_record();
	}
	else if (op  ==  2)
	{
		system("cls");
		show_record();
	}
	else if (op  ==  3)
	{
		system("cls");
		update_record();
	}
	else if (op  ==  4)
	{
		system("cls");
		delete_record();
	}
	else if (op  ==  5)
	{
		system("cls");
		goto val2;
	}
	else if (op  ==  6)
	{
		system("cls");
		sign_up_menu();
	}
	else if (op  ==  7)
	{
		system("cls");
		exit_menu();
	}
	else 
	{
		cout <<"    INVALID  CHOICE !!!!!";
		Sleep(1000);
		system("cls");
		goto val2;
	}

}
void gotoxy(int X,int Y)
{
	COORD coordinates;
	coordinates.X=X;
	coordinates.Y=Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
void disply_front()
{

	system("cls");
	system("color 02");
	print_front();
	Sleep(700);
	system("cls");
	system("color 03");
	print_front();
	Sleep(700);
	system("cls");
	system("color 05");
	print_front();
	Sleep(700);
	system("color 07");
	cout <<endl<<endl<<endl<<endl<<endl;
	system("color 07");
	cout <<"                                                     PRESS   ANY   KEY TO CONTINUE ";
	getch();
	system("cls");	
	
}

void print_header()
{
	cout <<"             |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|"<<endl;
	Sleep(60);
	cout <<"             |***********************************************************************************************************************************|"<<endl;
	Sleep(60);
	cout <<"             |***************************************   EMPLOYEE     MANAGEMENT        SYSTEM     ***********************************************|"<<endl;
	Sleep(60);
	cout <<"             |***********************************************************************************************************************************|"<<endl;
	Sleep(60);
	cout <<"             |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|"<<endl;
}
void sign_up_menu()
{
	print_header();

	cout <<endl<<endl<<endl<<endl;
	cout <<"                                   @@@@@@@@@@@@@@@@@@@@@@@@@     SIGN UP      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	print_box();
	gotoxy(20,20);
	cout <<"Enter User  Name :  ";
	cin >> user_name;
	gotoxy(20,24);
	cout <<"Enter Password :  ";
	cin >> password;
	gotoxy(20,30);
	cout <<"Loading Please Wait .....";
	Sleep(3000);
	gotoxy(28,32);

	cout <<"         PRESS   ANY   KEY TO CONTINUE ";
	getch();
}

void Login_menu()
{
	value:
	string U_name,pass;
	int count=0;
	print_header();
		
	cout <<endl<<endl<<endl<<endl;
	cout <<"                                   @@@@@@@@@@@@@@@@@@@@@@@@@     LOGIN  MENU    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	print_box();
	gotoxy(20,20);
	cout <<"User  Name :  ";
	cin >> U_name;
	gotoxy(20,24);
	cout <<"Password :";
	cin >> pass;
	if (user_name != U_name   &&   password != pass)
	{
		gotoxy(20,28);
		cout <<"INVALID USER NAME AND PASSWORD !!!!!!"<<endl;
		Sleep(1000);
		count++;
		
	}
	else if (user_name != U_name)
	{
		gotoxy(20,28);
		cout <<"INVALID USER NAME !!!!!!!"<<endl;
		Sleep(1000);
		count++;
		
	}
	else if (password != pass)
	{
		gotoxy(20,28);
		cout <<"INVALID  PASSWORD !!!!!!"<<endl;
		Sleep(1000);
		count++;
	}		

	else
	{
		gotoxy(20,28);
		cout <<"Loading Please Wait .....";
		Sleep(3000);
		gotoxy(28,32);

		cout <<"         PRESS   ANY   KEY TO CONTINUE ";
		getch();
	}
	if (count != 0)
	{
		system("cls");
		goto value;
	}
}

void print_box()
{
	gotoxy(15,18);
	cout <<" ------------------------------------------------------------------------------"<<endl;
	gotoxy(15,19);
	cout <<" |                                                                            |"<<endl;
	gotoxy(15,20);
	cout <<" |                                                                            |"<<endl;
	gotoxy(15,21);
	cout <<" |                                                                            |"<<endl;
	gotoxy(15,22);
	cout <<" |                                                                            |"<<endl;
	gotoxy(15,23);
	cout <<" |                                                                            |"<<endl;
	gotoxy(15,24);
	cout <<" |                                                                            |"<<endl;
	gotoxy(15,25);
	cout <<" |                                                                            |"<<endl;
	gotoxy(15,26);
	cout <<" ------------------------------------------------------------------------------"<<endl;

}

int choice_menu()
{
	print_header();
	cout <<endl<<endl<<endl<<endl;
	cout <<"                                   @@@@@@@@@@@@@@@@@@@@@@@@@     CHOICE  MENU    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	int op;
	gotoxy(20,16);
	cout <<"PRESS 1  TO   ENTER  Record :  ";
	gotoxy(20,18);
	cout <<"PRESS 2  TO   SHOW   Record :  ";
	gotoxy(20,20);
	cout <<"PRESS 3  TO   UPDATE  Record :  ";
	gotoxy(20,22);
	cout <<"PRESS 4  TO   DELETE  Record :  ";
	gotoxy(20,24);
	cout <<"PRESS 5  TO   SEARCH  Record :  ";
	gotoxy(20,26);
	cout <<"PRESS 6  TO   LOGOUT  :  ";
	gotoxy(20,28);
	cout <<"PRESS 7  TO   EXIT :  "<<endl;
	gotoxy(20,30);
	cout <<"YOUR CHOICE : ";
	cin >> op;
	return op;

}

void add_record()
{
	// Function call for Enter record 
	cout <<"Enter data";
}

void show_record()
{
	// Function call for  Show record
	cout <<"Show data";
}

void update_record()
{
	// Function call for  update record
	cout <<"Update data";
}

void delete_record()
{
	// Function call for  delete record
	cout <<"Delete data";
}

void search_record()
{
	// Function call for  search record
	cout <<"Search data";
}
void exit_menu()

{

    system("cls");
    cout <<endl<<endl;
    cout <<endl<<endl;
    cout <<endl<<endl;
    cout <<endl<<endl;
    cout <<endl<<endl;
    cout <<"                @@@@@@@ @   @  @@  @@    @ @   @         @   @  @@  @  @    @"<<endl;
    Sleep(70);
    cout <<"                   @    @   @ @  @ @ @   @ @  @          @   @ @  @ @  @    @"<<endl;
    Sleep(70);
    cout <<"                   @    @@@@@ @@@@ @  @  @ @@@            @@@  @  @ @  @    @"<<endl;
    Sleep(70);
    cout <<"                   @    @   @ @  @ @   @ @ @  @            @   @  @ @  @     "<<endl;
    Sleep(70);
    cout <<"                   @    @   @ @  @ @    @@ @   @           @    @@   @@     @"<<endl;
}



void print_front()
{	cout <<endl<<endl<<endl<<endl;
	cout <<"******************************************************************************************************************************************************"<<endl;
	Sleep(80);
	cout <<"******************************************************************************************************************************************************"<<endl;
	Sleep(80);
	cout <<"******************************************************************************************************************************************************"<<endl;
	Sleep(80);
	cout <<"*************|----------------------------------------------------------------------------------------------------------------|***********************"<<endl;
	Sleep(80);
	cout <<"*************|                                                                                                                |***********************"<<endl;
	Sleep(80);
	cout <<"*************| @@@@ @@   @@ @@@  @     @@  @   @ @@@@ @@@@         @@   @@  @@  @@    @  @@   @@  @@   @@ @@@@ @@    @ @@@@@  |***********************"<<endl;
	Sleep(80);
	cout <<"*************| @    @ @ @ @ @  @ @    @  @ @   @ @    @            @ @ @ @ @  @ @ @   @ @  @ @    @ @ @ @ @    @ @   @   @    |***********************"<<endl;
	Sleep(80);
	cout <<"*************| @@@  @  @  @ @@@  @    @  @   @   @@@  @@@          @  @  @ @@@@ @  @  @ @@@@ @ @@ @  @  @ @@@  @  @  @   @    |***********************"<<endl;
	Sleep(80);
	cout <<"*************| @    @     @ @    @    @  @   @   @    @            @     @ @  @ @   @ @ @  @ @  @ @     @ @    @   @ @   @    |***********************"<<endl;
	Sleep(80);
	cout <<"*************| @@@@ @     @ @    @@@@  @@    @   @@@@ @@@@         @     @ @  @ @    @@ @  @  @@  @     @ @@@@ @    @@   @    |***********************"<<endl;
	Sleep(80);
	cout <<"*************|                                                                                                                |***********************"<<endl;
	Sleep(80);
	cout <<"*************|                                          @@@  @   @  @@@ @@@@@ @@@@@ @@   @@                                   |***********************"<<endl;
	Sleep(80);
	cout <<"*************|                                         @     @   @ @      @   @     @ @ @ @                                   |***********************"<<endl;
	Sleep(80);
	cout <<"*************|                                          @@     @    @@    @   @@@@  @  @  @                                   |***********************"<<endl;
	Sleep(80);  
	cout <<"*************|                                            @    @      @   @   @     @     @                                   |***********************"<<endl;
	Sleep(80);
	cout <<"*************|                                         @@@     @   @@@    @   @@@@@ @     @                                   |***********************"<<endl; 
	Sleep(80);
	cout <<"**************----------------------------------------------------------------------------------------------------------------|***********************"<<endl;
	Sleep(80);
	cout <<"******************************************************************************************************************************************************"<<endl;
	Sleep(80);
	cout <<"******************************************************************************************************************************************************"<<endl;
	Sleep(80);
	cout <<"******************************************************************************************************************************************************"<<endl;
	Sleep(80);
	cout <<"******************************************************************************************************************************************************"<<endl;
	Sleep(80);
	cout <<"******************************************************************************************************************************************************"<<endl;
	Sleep(80);
	cout <<"******************************************************************************************************************************************************"<<endl;
}

