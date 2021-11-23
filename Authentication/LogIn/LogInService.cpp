#pragma once
#include<fstream>
#include "../../Manager/ManagerService.cpp"
#include "../../Cashier/CashierService.cpp"
#include"../LogIn/LogInAuthentication.cpp"

class LogInService
{
private:
	LogInAuthentication logIn;
	ManagerService ManService;
	CashierService CashService;

	AccountUser account;
	Cashier cashier;
	Manager manager;

	char role[20];
public:

	LogInService():role("unknown") {}
	~LogInService() {}


	void UserType(int loggedIn)
	{

		if (loggedIn == 1)
		{
			ManService.LogInAsManager();
		}
		if (loggedIn == 2)
		{
			CashService.LogInAsCashier();
		}
		if(loggedIn == 3)
		{
			cout << "\t\t\t\t=======================================" << endl;
			cout << "\t\t\t\t||  Incorrect password or username!  ||" << endl;
			cout << "\t\t\t\t=======================================" << endl;
			system("pause");
		}
	}

};

