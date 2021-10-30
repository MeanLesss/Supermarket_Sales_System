#pragma once
#include<iostream>
#include<string>
#include<fstream>
//#include"Product.cpp"
//#include"Account.cpp"
using namespace std;

class Cashier
{
private:
	string CashierName;
	string CashierPass;
	string role;
	
public:
	Cashier() :CashierName("unknown"), CashierPass("unknown"), role("unknown") {}
	Cashier(string CashierName, string CashierPass) :CashierName(CashierName), CashierPass(CashierPass) {}
	Cashier(string CashierName,string CashierPass,string role) :CashierName(CashierName), CashierPass(CashierPass), role(role) {}
	void CreateCashier()
	{
		cout << "\t\t\t\tEnter username : ";
		cin.ignore();
		getline(cin, CashierName);
		cout << "\t\t\t\tEnter password : ";
		getline(cin, CashierPass);
		role = "cashier";
	}
	void SearchCashier()
	{

	}

	void UpdateCashier(Cashier & cashier)
	{

	}

	void DeleteCashier(Cashier& cashier)
	{


	}

	void AddProdToCart()
	{


		//service.SaveReportFile(/*need a parameter*/);
	}

	void DisplayCashier()
	{
		cout << "\t\t\t\tUsername : " << CashierName << endl;
		cout << "\t\t\t\tPassword : " << CashierPass << endl;
		cout << "\t\t\t\tRole : " << role << endl;
	}
};