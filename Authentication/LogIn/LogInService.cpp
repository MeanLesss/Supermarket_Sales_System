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


	void UserType(bool loggedIn)
	{
		ifstream fin;
		fin.open(USER_FILE, ios::in | ios::binary);
		while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
		{
			if (loggedIn == true)
			{
				memcpy(this->role, "manager", 8);
				
				manager = Manager(account.getUserName() , account.getPassWord(), role);
				cout << "\t\t\t\tLogged in as :" << endl;
				manager.DisplayManager();
				fin.close();
				ManService.LogInAsManager();
			}
			else
			{
				memcpy(this->role, "cashier", 8);
				Cashier cashier(account.getUserName(), account.getPassWord(), role);
				cout << "\t\t\t\tLogged in as :" << endl;
				cashier.DisplayCashier();
				fin.close();
				CashService.LogInAsCashier();
			}
		}

	}

};

