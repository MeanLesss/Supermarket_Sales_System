#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Cashier.cpp"
#include"Manager.cpp"
#include"Product.cpp"
using namespace std;


class Service 
{
private:
	
	string UserName;
	string PassWord;
	const string CASHIER_FILE = "cashier.bin";
	const string MANAGER_FILE = "manager.bin";
	const string PRODUCT_FILE = "product.bin";
	const string REPORT_FILE = "report.bin";

public:

	Service() :UserName("unknown"), PassWord("unknown") { }
	Service(string UserName) : UserName(UserName) { }
	Service(string UserName, string PassWord) :UserName(UserName), PassWord(PassWord) { }
	~Service() { }

	
	
	//File in out for product
	void SaveToProduct(Product & product)
	{
		//cout << "\t\t\t\tSign up as admin";
		ofstream fout;
		fout.open(PRODUCT_FILE, ios::out | ios::app | ios::binary);
		if (!fout) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed";
			exit(1);
		}
		fout.write((char*)&product, sizeof(Product));
		fout << endl;
		fout.close();
	}

	void LoadFromProduct()
	{
		Product product;
		ifstream fin;
		fin.open(PRODUCT_FILE, ios::in | ios::binary);
		while (!fin.read((char*)&product, sizeof(Product)))
		{
			fin.seekg(0);
			product.DisplayProduct();
			cout << endl;
		}

		fin.close();
	}

	//Manager file in out
	void SignUp(Manager& manager)//add admin
	{
		ofstream fout;
		fout.open(MANAGER_FILE, ios::out | ios::app | ios::binary);
		if (!fout) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed";
			exit(1);
		}
		fout.write(reinterpret_cast<char*>(&manager), sizeof(Manager));
		fout.close();
	}

	
	void LoadFromManager()
	{
		int count = 0;
		Manager manager;
		ifstream fin;
		fin.open(MANAGER_FILE, ios::in | ios::binary);
		//fin.read(reinterpret_cast<char*>(&manager), sizeof(Manager))
		while (fin.read((char*)&manager, sizeof(Manager)))
		{
			manager.DisplayManager();
			cout << endl;
		}
		fin.close();
	}

	//Cashier file in out
	void SaveToCashier(Cashier& cashier)
	{
		ofstream fout;
		fout.open(CASHIER_FILE, ios::out | ios::app | ios::binary);
		if (!fout) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed";
			exit(1);
		}
		fout.write((char*)&cashier, sizeof(Cashier));
		fout << endl;
		fout.close();
	}
	void LoadFromCashier(Cashier & cashier)
	{
		ifstream fin;
		fin.open(CASHIER_FILE, ios::in | ios::binary);
		while (!fin.read((char*)&cashier, sizeof(Cashier)))
		{
			cashier.DisplayCashier();
			cout << endl;
		}

		fin.close();
	}


	// Load report of each cashier 
	void SaveReportFile()
	{

	}

	void LoadReportFile()
	{

	}



};