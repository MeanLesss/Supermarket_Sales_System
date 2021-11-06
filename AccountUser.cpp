#pragma once
#include<iostream>
#include<string>
using namespace std;

class AccountUser
{
private:
	char UserName[20];
	char PassWord[20];
	char role[8];
public:

	AccountUser():UserName("unknown"),PassWord("unknown") { }
	AccountUser(char name[],char password[],char role[]) 
	{
		memcpy(this->UserName, name, 20);
		memcpy(this->PassWord, password, 20);
		memcpy(this->role, role, 8);
	}

	string getName()
	{
		return UserName;
	}
	
	string getPassword()
	{
		return PassWord;
	}
	
	string getRole()
	{
		return role;
	}

	void CreateUser(int role1)/// role 1 = manager ,role 2 = cashier
	{
		cout << "\t\t\t\tEnter username : ";
		cin >> UserName;
		cout << "\t\t\t\tEnter password : ";
		cin >> PassWord;
		//cout << "\t\t\t\tEnter role : ";
		//cin >> role1;
		if (role1 == 1)
		{
			memcpy(this->role, "manager", 20);
		}
		if (role1 == 2)
		{
			memcpy(this->role, "cashier", 20);
		}

	}
	
};