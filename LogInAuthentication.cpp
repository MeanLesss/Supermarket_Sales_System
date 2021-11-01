#pragma once
#include<iostream>
#include"ManagerService.cpp"
#include"CashierService.cpp"

class LogInAuthentication 
{
private:
	ManagerService ManService;
	CashierService CashService;
public:
	LogInAuthentication(){}
	//log ins
	void LogIn()
	{
		cout << "\t\t\t\tLogged in as manager" << endl;
		ManService.LogInAsManager();
		//or cashier service
		cout << "\t\t\t\tLogged in as cashier" << endl;
		CashService.LogInAsCashier();
	}


};
