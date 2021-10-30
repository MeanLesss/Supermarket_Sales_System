#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Manager 
{
private:
	//ID maybe later
	string ManagerName;
	string ManagerPass;
	string role;
	//Service service;
	const string MANAGER_FILE = "manager.bin";


public:
	Manager() :ManagerName("unknown"), ManagerPass("unknown"), role("unknown") {}
	Manager(string ManagerName,string ManagerPass) :ManagerName(ManagerName), ManagerPass(ManagerPass){}
	Manager(string ManagerName, string ManagerPass, string role) : ManagerName(ManagerName), ManagerPass(ManagerPass), role(role) {}
	~Manager() {}

	void CreateManager() 
	{
		cout << "\t\t\t\tEnter username : ";
		cin.ignore();
		getline(cin, ManagerName);
		cout << "\t\t\t\tEnter password : ";
		getline(cin, ManagerPass);
		
		//role = "manager";
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
