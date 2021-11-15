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
	char role[20];

	//Service service;


public:

	Manager() :ManagerName("unknown"), ManagerPass("unknown"), role("Manager") {}
	Manager(char ManagerName[],char ManagerPass[]):role("manager")
	{
		memcpy(this->ManagerName, ManagerName, 20);
		memcpy(this->ManagerPass, ManagerPass, 20);
	}
	Manager(char ManagerName[], char ManagerPass[], char role[20])
	{
		memcpy(this->ManagerName, ManagerName, 20);
		memcpy(this->ManagerPass, ManagerPass, 20);
		memcpy(this->role, role, 20);
		/*this->ManagerName = ManagerName;
		this->ManagerPass = ManagerPass;
		this->role = role;*/

	}
	~Manager() {}

	//Control cashier
	string getRole()
	{
		return role;
	}

	void DeleteManager()
	{

	}
	void DisplayManager()
	{
		cout << "\t\t\t\tUsername : " << ManagerName << endl;
		cout << "\t\t\t\tPassword : " << ManagerPass << endl;
		cout << "\t\t\t\tRole : " << role << endl;
	}
	

};
