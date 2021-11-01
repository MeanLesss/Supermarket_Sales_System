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

	// Need log in control statement to devide the program 
	// and to go back and forth from menu to menu
	void LogIn()
	{

		cout << "\t\t\t\tLogged in as manager" << endl;
		ManService.LogInAsManager();

		//or cashier service
		cout << "\t\t\t\tLogged in as cashier" << endl;
		CashService.LogInAsCashier();


	}


};
