#pragma once
#include<iostream>
#include<string>

using namespace std;


class Manager 
{
private:
	//ID maybe later
	/*string ManagerName;
	string ManagerPass;
	string role;*/
	char ManagerName[20];
	char ManagerPass[20];
	//Service service;


public:
	char role[20];

	Manager() :ManagerName("unknown"), ManagerPass("unknown"), role("Manager") {}
	Manager(char ManagerName[],char ManagerPass[])
	{
		memcpy(this->ManagerName, ManagerName, 20);
		memcpy(this->ManagerPass, ManagerPass, 20);

	}
	Manager(char ManagerName[], char ManagerPass[], char role[])
	{
		memcpy(this->ManagerName, ManagerName, 20);
		memcpy(this->ManagerPass, ManagerPass, 20);
		memcpy(this->role, role, 20);

	}
	~Manager() {}

	void CreateManager() 
	{
		cout << "\t\t\t\tEnter username : ";
		cin >> ManagerName;
		cout << "\t\t\t\tEnter password : ";
		cin >> ManagerPass;
		cout << "\t\t\t\tEnter role : ";
		cin >> role;

	}

	//Control cashier
	void AddCashierAcc() 
	{
		
	}
	void EditCashierAcc()
	{

	}

	void DeleteCashierAcc()
	{

	}
	void DisplayManager()
	{
		cout << "\t\t\t\tUsername : " << ManagerName << endl;
		cout << "\t\t\t\tPassword : " << ManagerPass << endl;
		cout << "\t\t\t\tRole : " << role << endl;
	}
	

};
