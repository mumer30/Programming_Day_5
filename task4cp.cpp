99#include<iostream>
using namespace std;
int project_time_calculation(int,int);
main()
{
	int hours_needed,days,workers;
	cout <<"Enter the needed hours: ";
	cin>>hours_needed;
	cout <<"Enter the days that the film has: ";
	cin>>days;
	cout <<"Enter the number of all workers: ";
	cin>>workers;
	int total_hour=project_time_calculation(days,workers);
	if(hours_needed>total_hour)
		cout <<"Not enough time ! "<<(hours_needed-total_hour)<<" hours needed.";
	else
		cout <<"Yes ! "<<(total_hour-hours_needed)<<" hours left.";
}
int project_time_calculation(int days,int workers)
{
	return (days*0.90)*10*workers; 
	
}
