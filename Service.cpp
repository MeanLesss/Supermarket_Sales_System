#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<vector>
#include"Cashier.cpp"
#include"Manager.cpp"
#include"Product.cpp"
#include"AccountUser.cpp"
using namespace std;
const char USER_FILE[] = "user.dat";
const char PRODUCT_FILE[] = "product.dat";
const char REPORT_FILE[] = "report.dat";

class Service 
{
private:

	Manager manager;
	Cashier cashier;
	Product product;

	string UserName;
	string PassWord;
	

public:

	Service() :UserName("unknown"), PassWord("unknown") { }
	Service(string UserName) : UserName(UserName) { }
	Service(string UserName, string PassWord) :UserName(UserName), PassWord(PassWord) { }
	

	
	
	//File in out for product
	void SaveToProduct(Product & product)
	{
		//cout << "\t\t\t\tSign up as admin";
		ofstream fout;
		fout.open(PRODUCT_FILE, ios::out | ios::app | ios::binary);
		if (!fout) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed" << endl;
			system("pause");
		}
		fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
		fout.close();
	}

	void LoadFromProduct()
	{
		int count = 0;
		ifstream fin;
		fin.open(PRODUCT_FILE, ios::in | ios::binary);
		if (!fin) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed" << endl;
		}
		while (1)
		{
			fin.read(reinterpret_cast<char*>(&product), sizeof(Product));
			product.setProductNo(count);
			if (fin.eof()) { break; }
			product.DisplayProduct();
			count++;

		}

		fin.close();
	}
	void DeleteProduct(int id)
	{
		Product product;
		ifstream fin;
		ofstream fout;

		fin.open(PRODUCT_FILE, ios::in | ios::binary);
		if (!fin) {
			cerr << "File open failed";
			exit(1);
		}
		fout.open("temp.dat", ios::out | ios::app | ios::binary);
		fin.seekg(0, ios::beg);
		while (1) // I use this method because it read better than the function read in while(argument)
		{
			fin.read(reinterpret_cast<char*>(&product), sizeof(Product));
			if (fin.eof()) { break; }
			if (product.getProductNo() != id) {
				fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
			}
		}
		fin.close();
		fout.close();
		remove("product.dat");
		rename("temp.dat", "product.dat");
		cout << "Item deleted" << endl;
	}
	//Manager file in out
	void SignUp(AccountUser& account)//add admin
	{
		ofstream fout;
		fout.open(USER_FILE, ios::out | ios::app | ios::binary);
		if (!fout) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed" << endl;
			system("pause");
		}
		fout.write(reinterpret_cast<char*>(&account), sizeof(AccountUser));
		fout.close();
	}

	//void LoadFromUser(string role)
	void LoadFromUser(string role)
	{
		int count = 0;
		ifstream fin;
		fin.open(USER_FILE, ios::in | ios::binary);
		//fin.read(reinterpret_cast<char*>(&manager), sizeof(Manager))
		if (!fin) {
			// throw FileNotFoundException("File open failed");
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
					}
					
				}
			}
			
			fin.close();
		}
	}

	void DeleteUser(string username)
	{
		AccountUser account;
		ifstream fin;
		ofstream fout;

		fin.open(USER_FILE, ios::in | ios::binary);
		if (!fin) 
		{
			cerr << "File open failed";
			exit(1);
		}
		fout.open("temp.dat", ios::out | ios::app | ios::binary);
		fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser))) 
		{
			/*fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser))*/;
			if (fin.eof()) { break; }
			if (account.getUsername() != username) 
			{
				fout.write(reinterpret_cast<char*>(&account), sizeof(AccountUser));
			}
			else
			{
				continue;
			}
		}
		fin.close();
		fout.close();
		int res = 0;
		if (remove(USER_FILE) != 0)
		{
			cout << "Failed to remove!" << endl;
		}
		//remove(USER_FILE);
		res = rename("temp.dat", USER_FILE);
		if (res == 0)
		{
			cout << "User deleted" << endl;
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