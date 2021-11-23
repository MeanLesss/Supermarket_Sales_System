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
		/*this->CashierName = CashierName;
		this->CashierPass = CashierPass;*/
	}
	Cashier(char CashierName[], char CashierPass[], char role[])
	{
		memcpy(this->CashierName, CashierName, 20);
		memcpy(this->CashierPass, CashierPass, 20);
		memcpy(this->role, role, 20);
		/*this->CashierName = CashierName;
		this->CashierPass = CashierPass;
		this->role = role;*/

	}

	string getRole()
	{
		return role;
	}

	void AddProdToCart()
	{
		  
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


	void DisplayCashier()
	{
		cout << "\t\t\t\tUsername : " << CashierName 
			 << "\t\tPassword : " << CashierPass
		   	 << "\t\tRole : " << role << endl;
	}
};