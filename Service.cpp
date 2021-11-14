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
const char REPORT_FILE[] = "report.dat";

class Service 
{
private:

	Manager manager;
	Cashier cashier;
	Product product;

	string UserName;
	string PassWord;
	FileUtil fileIO;

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
		int count = 0;
		ifstream fin;
		fin.open(USER_FILE, ios::in | ios::binary);
		
		if (!fin) 
		{
			cerr << "File open failed" << endl;
		}
		else
		{
			if (role == "manager")
			{
				while (1)
				{
					fin.read(reinterpret_cast<char*>(&manager), sizeof(AccountUser));
					if (fin.eof()) { break; }
					if (manager.getRole() == role)
					{
						manager.DisplayManager();
						cout << endl;
					}
					
				}
			}
			else if (role == "cashier")
			{
				while (1)// I use this method because it read better than the function read in while(argument)
				{
					fin.read(reinterpret_cast<char*>(&cashier), sizeof(AccountUser));
					if (fin.eof()) { break; }

					if (cashier.getRole() == role)
					{
						cashier.DisplayCashier();
						cout << endl;
					}
					
				}
			}
			
		}
		fin.close();
	}

	void DeleteUser(string username)
	{
		int count = 0; //account found detector
		AccountUser account;
		ifstream fin;
		ofstream fout;

		fileIO.OpenDataToFile("temp.dat");
		fin.open(USER_FILE, ios::in | ios::binary);

		if (!fin)
		{
			cerr << "File open failed";
			exit(1);
		}
		while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
		{
			if (fin.eof()) { break; }
			if (account.getUsername() != username)
			{
				fileIO.WriteDataToFileUser(account);
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t\tAccount not found" << endl;
		}
		else
		{
			cout << "\t\t\t\tUser deleted" << endl;
		}

		fin.close();
		fileIO.CloseDataToFile();

		int res = 0;
		if (remove("user.dat") != 0)
		{
			cout << "Failed to remove!" << endl;
		}
		//remove(USER_FILE);
		res = rename("temp.dat","user.dat");
		if (res == 0)
		{
			cout << "File deleted" << endl;
		}
		else
		{
			cout << "Failed to rename" << endl;
		}
		
	}

	void UpdateUser(string username)
	{
		int count = 0;
		AccountUser account;
		ifstream fin;

		fileIO.OpenDataToFile("temp.dat");
		fin.open(USER_FILE, ios::in | ios::binary);

		if (!fin)
		{
			cerr << "File open failed";
			exit(1);
		}
		fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
		{
			if (fin.eof()) { break; }
			if (account.getUsername() != username)
			{
				fileIO.WriteDataToFileUser(account);
			}
			else
			{
				account.CreateUser(2);
				fileIO.WriteDataToFileUser(account);
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Account not found" << endl;
		}
		fin.close();
		fileIO.CloseDataToFile();
		int res = 0;
		if (remove("user.dat") != 0)
		{
			cout << "Failed to remove!" << endl;
		}
		//remove(USER_FILE);
		res = rename("temp.dat", "user.dat");
		if (res == 0)
		{
			cout << "\t\t\t\tUser updated!" << endl;
		}
		else
		{
			cout << "Failed to rename" << endl;
		}
	}

	// Load report of each cashier 
	void SaveReportFile()
	{

	}

	void LoadReportFile()
	{

	}



};