#pragma once
#include<iostream>
#include<string>
using namespace std;

class Cashier
{
private:
	/*string CashierName;
	string CashierPass;
	string role;*/
	char CashierName[20];
	char CashierPass[20];
	char role[20];

	
public:
	Cashier() :CashierName("unknown"), CashierPass("unknown"), role("cashier") {}
	Cashier(char CashierName[], char CashierPass[]):role("cashier")
	{
		memcpy(this->CashierName, CashierName, 20);
		memcpy(this->CashierPass, CashierPass, 20);
	}
	Cashier(char CashierName[],char CashierPass[],char role[])
	{
		memcpy(this->CashierName, CashierName, 20);
		memcpy(this->CashierPass, CashierPass, 20);
		memcpy(this->role, role, 20);
	}

	/*void CreateCashier()
	{
		cout << "\t\t\t\tEnter username : ";
		cin >> CashierName;
		cout << "\t\t\t\tEnter password : ";
		cin >> CashierPass;
		cout << "\t\t\t\tEnter role : ";
		cin >> role;
	}*/
	string getRole()
	{
		return role;
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