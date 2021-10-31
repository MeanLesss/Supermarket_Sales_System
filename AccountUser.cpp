#pragma once
#include<iostream>
#include<string>
using namespace std;

class AccountUser
{
private:
	char UserName[20];
	char PassWord[20];
public:
	char role[8];

	AccountUser():UserName("unknown"),PassWord("unknown") { }
	AccountUser(char name[],char password[],char role[]) 
	{
		memcpy(this->UserName, name, 20);
		memcpy(this->PassWord, password, 20);
		memcpy(this->role, role, 8);
	}

	void CreateUser(int role1)
	{
		cout << "\t\t\t\tEnter username : ";
		cin >> UserName;
		cout << "\t\t\t\tEnter password : ";
		cin >> PassWord;
		//cout << "\t\t\t\tEnter role : ";
		//cin >> role1;
		if (role1 == 1)
		{
			memcpy(this->role, "manager", 8);
		}
		else if (role1 == 2)
		{
			memcpy(this->role, "cashier", 8);
		}

	}
	
};