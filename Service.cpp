#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include"FileUtility.cpp"
#include"Cashier.cpp"
#include"Manager.cpp"
#include"Product.cpp"
#include"AccountUser.cpp"
using namespace std;
const char USER_FILE[] = "user.dat";

class Service 
{
private:

	Manager manager;
	Cashier cashier;
	Product product;

	string UserName;
	string PassWord;
	FileIO fileIO;

public:

	Service() :UserName("unknown"), PassWord("unknown") { }
	Service(string UserName) : UserName(UserName) { }
	Service(string UserName, string PassWord) :UserName(UserName), PassWord(PassWord) { }
	

	
	//Manager file in out
	void SignUp(AccountUser& account)//add admin
	{
		fileIO.OpenDataToFile(USER_FILE);
		fileIO.WriteDataToFileUser(account);
		fileIO.CloseDataToFile();
	}

	//void LoadFromUser(string role)
	void LoadFromUser(string role)
	{
		AccountUser account;
		ifstream fin;

		fileIO.OpenDataFromFile(USER_FILE);

		fileIO.ReadDataFromFileUser(account, role);

		fileIO.CloseDataFromFile();
	}

	void DeleteUser(string username)
	{
		AccountUser account;

		fileIO.OpenDataToFile("temp.dat");

		fileIO.OpenDataFromFile(USER_FILE);

		fileIO.WriteDeleteUser(account, username);
		
		fileIO.CloseDataFromFile();

		fileIO.CloseDataToFile();

		fileIO.RenameRemoveUser();
		
	}

	void UpdateUser(string username)
	{
		AccountUser account;

		fileIO.OpenDataToFile("temp.dat");

		fileIO.OpenDataFromFile(USER_FILE);

		fileIO.WriteUpdateUser(account,username);

		fileIO.CloseDataFromFile();

		fileIO.CloseDataToFile();

		fileIO.RenameRemoveUser();

	}

};