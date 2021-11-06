#pragma once
#include<iostream>
#include<string>
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
			system("pause");
		}
		while (1)
		{
			product.setProductNo(count);
			fin.read(reinterpret_cast<char*>(&product), sizeof(Product));
			if (fin.eof()) { break; }
			product.DisplayProduct();
			count++;

		}

		fin.close();
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
		ifstream fin;
		fin.open(USER_FILE, ios::in | ios::binary);
		//fin.read(reinterpret_cast<char*>(&manager), sizeof(Manager))
		if (!fin) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed" << endl;
			system("pause");
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
				while (1)
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

	// Load report of each cashier 
	void SaveReportFile()
	{

	}

	void LoadReportFile()
	{

	}



};