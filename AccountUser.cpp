#pragma once
#include<iostream>
#include<string>
using namespace std;

class AccountUser
{
private:
	char UserName[20];
	char PassWord[20];
	char role[20];
public:
	AccountUser():UserName("unknown"),PassWord("unknown") { }
	AccountUser(char name[],char password[],char role[]) 
	{
		memcpy(this->UserName, name, 20);
		memcpy(this->PassWord, password, 20);
		memcpy(this->role, role, 20);
	}

	void CreateUser()
	{
		cout << "\t\t\t\tEnter username : ";
		cin >> UserName;
		cout << "\t\t\t\tEnter password : ";
		cin >> PassWord;
		cout << "\t\t\t\tEnter role : ";
		cin >> role;

	}
	
};