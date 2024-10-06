#include<iostream>
#include<iomanip>
using namespace std;
float volume(float,float,float,string);
main()
{
	float length,width,height;
	string user_desire;
	cout <<"Enter the length of the pyramid (in meters): ";
	cin >>length;
	cout <<"Enter the width of the pyramid (in meters): ";
	cin >>width;
	cout <<"Enter the height of the pyramid (in meters): ";
	cin >>height;
	cout <<"Enter the desired output unit (millimeters,centimeters,meters,kilometers): ";
	cin >>user_desire;
	float ans=volume(length,width,height,user_desire);
	cout << fixed << setprecision(3);
	cout <<"The volume of the Pyramid is: "<<ans <<" cubic "<<user_desire;
}
float volume(float length,float width,float height,string user_desire)
{
	float Vol=(length*width*height)/3;
	if (user_desire=="millimeters")
		return Vol*1000*1000*1000;
	else if (user_desire=="centimeters")
		return Vol*100*100*100;
	else if (user_desire=="kilometers")
		return Vol/(1000*1000*1000);
	else 
		return Vol;

}
