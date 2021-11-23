#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
using namespace std;

class Menu
{
private:

public:
	Menu() {}

	void DisplayProductHeader()
	{
		cout << "_____________________________________________________________________________________" << endl;
		cout << "|+ " << left << "ID" << setw(10) << right << "|"
			<< right << "Product name" << setw(15) << right 
			<< "Price" << setw(22)
			<< right << "Quantity"  << setw(20) << left
			<< right << "Discount"  << setw(15) << left << "|" << endl;
	}

	void DisplayLogInMenu()
	{
		cout << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\t*                     Log in Menu                   *" << endl
			 << "\t\t\t\t*---------------------------------------------------*" << endl
			 << "\t\t\t\t*              1.Log in                             *" << endl
			 << "\t\t\t\t*              2.Sign up manager account            *" << endl
			 << "\t\t\t\t*              3.Show manager account               *" << endl
			 << "\t\t\t\t*              4.Delete manager account             *" << endl
			 << "\t\t\t\t*              5.Exit                               *" << endl
			 << "\t\t\t\t*                                                   *" << endl
			 << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\tEnter your choice : ";
		
	}

	void DisplayManagerMenu()
	{
		cout << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\t*                    Manager Menu                   *" << endl
			 << "\t\t\t\t*---------------------------------------------------*" << endl
			 << "\t\t\t\t*              1.Product management                 *" << endl
			 << "\t\t\t\t*              2.Cashier management                 *" << endl
			 << "\t\t\t\t*              3.Sign out                           *" << endl
			 << "\t\t\t\t*              0.Exit                               *" << endl
			 << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\tEnter your choice : ";
		
	}

	void DisplayManagerProductCRUD()
	{
		cout << "\t\t\t\t*****************************************************" << endl
			<< "\t\t\t\t*                    Product CRUD                   *" << endl
			<< "\t\t\t\t*---------------------------------------------------*" << endl
			<< "\t\t\t\t*              1.Create product                     *" << endl
			<< "\t\t\t\t*              2.View all product                   *" << endl
			<< "\t\t\t\t*              3.Update product                     *" << endl
			<< "\t\t\t\t*              4.Remove Prodcut                     *" << endl
			<< "\t\t\t\t*              5.Back to manager menu               *" << endl
			<< "\t\t\t\t*              0.Exit                               *" << endl
			<< "\t\t\t\t*****************************************************" << endl
			<< "\t\t\t\tEnter your choice : ";
	}
	void DisplayManagerAccountCRUD()
	{
		cout << "\t\t\t\t*****************************************************" << endl
			<< "\t\t\t\t*                    Manager CRUD                   *" << endl
			<< "\t\t\t\t*---------------------------------------------------*" << endl
			<< "\t\t\t\t*              1.Add cashier account                *" << endl
			<< "\t\t\t\t*              2.Update cashier account             *" << endl
			<< "\t\t\t\t*              3.Delete cashier account             *" << endl
			<< "\t\t\t\t*              4.View all cashier account and pass  *" << endl
			<< "\t\t\t\t*              5.Back to manager menu               *" << endl
			<< "\t\t\t\t*              0.Exit                               *" << endl
			<< "\t\t\t\t*****************************************************" << endl
			<< "\t\t\t\tEnter your choice : ";
	}

	void DisplayCashierMenu()
	{
		cout << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\t*                    Cashier Menu                   *" << endl
			 << "\t\t\t\t*---------------------------------------------------*" << endl
			 << "\t\t\t\t*              1.Add product to cart                *" << endl
			 << "\t\t\t\t*              2.View all report                    *" << endl
			 << "\t\t\t\t*              3.Sign out                           *" << endl
			 << "\t\t\t\t*              0.Exit                               *" << endl
			 << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\tEnter your choice : ";

	}
};