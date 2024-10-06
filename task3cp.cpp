#include<iostream>
#include<iomanip>
using namespace std;
float Calculate_tax(char code,float price)
{
	if (code == 'M')
		return 1.06*price;
	else if (code == 'E')
		return 1.08*price;
	else if (code == 'S')
		return 1.10*price;
	else if (code == 'V')
		return 1.12*price;
	else
		return 1.15*price; 
}
main()
{
	char code;
	float price;
	cout <<"Enter the vehicle type code (M,E,S,V,T): ";
	cin >>code;
	cout <<"Enter the price of vehicle: ";
	cin >>price;
	float final_price=Calculate_tax(code,price);
	cout << fixed << setprecision(2);
	cout <<"The final price of a vehicle of type "<<code <<" after adding the tax is $"<<final_price;
}

