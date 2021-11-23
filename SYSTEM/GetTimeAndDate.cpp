#pragma once
#include<iostream>
#include<ctime>
#include<string>
using namespace std;
class GetTimeAndDate
{
private:
	
    char systemTime[30];
	char systemDate[30];
	char localTime[30];
	time_t  now = time(NULL);
	//errno_t e = ctime_s(s, 50, &t);
	int e = ctime_s(systemTime, 30, &now);


public:
//have to change the get date time to small part
	GetTimeAndDate() {}
	~GetTimeAndDate() {}
	char* getDateAndTime()
	{
		return systemTime;
	}
	



};

