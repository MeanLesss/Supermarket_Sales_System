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
		ifstream fin;
		fin.open(USER_FILE, ios::in | ios::binary);
		while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
		{
			if (loggedIn == 1)
			{
				ManService.LogInAsManager();
				break;
			}
			if(loggedIn == 2)
			{
				CashService.LogInAsCashier();
				break;
			}
			else
			{
				cout << "\t\t\t\t=======================================" << endl;
				cout << "\t\t\t\t||  Incorrect password or username!  ||" << endl;
				cout << "\t\t\t\t=======================================" << endl;
				system("pause");
				break;
			}
		}

	}

};

