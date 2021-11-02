#pragma once
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class Menu
{
private:
	char loginmenu ;
public:
	Menu menu() {}
	void DisplayLogInMenu()
	{
		cout << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\t*                     Log in Menu                   *" << endl
			 << "\t\t\t\t*                                                   *" << endl
			 << "\t\t\t\t*              1.Log in                             *" << endl
			 << "\t\t\t\t*              2.Sign up admin                      *" << endl
			 << "\t\t\t\t*              3.Show admin                         *" << endl
			 << "\t\t\t\t*              4.Exit                               *" << endl
			 << "\t\t\t\t*                                                   *" << endl
			 << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\tEnter your choice : ";
		
	}

	void DisplayManagerMenu()
	{
		cout << "\t\t\t\t*****************************************************" << endl
			<< "\t\t\t\t*                    Manager Menu                   *" << endl
			<< "\t\t\t\t*                                                   *" << endl
			<< "\t\t\t\t*              1.Create product                     *" << endl
			<< "\t\t\t\t*              2.View all product                   *" << endl
			<< "\t\t\t\t*              3.Update product                     *" << endl
			<< "\t\t\t\t*              4.Remove Prodcut                     *" << endl
			<< "\t\t\t\t*              5.Add cashier account                *" << endl
			<< "\t\t\t\t*              6.Update cashier account             *" << endl
			<< "\t\t\t\t*              7.Delete cashier account             *" << endl
			<< "\t\t\t\t*              8.View all cashier account and pass  *" << endl
			<< "\t\t\t\t*              9.Sign out                           *" << endl
			<< "\t\t\t\t*              0.Exit                               *" << endl
			<< "\t\t\t\t*****************************************************" << endl
			<< "\t\t\t\tEnter your choice : ";
		
	}

	void DisplayCashierMenu()
	{
		cout << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\t*                    Cashier Menu                   *" << endl
			 << "\t\t\t\t*                                                   *" << endl
			 << "\t\t\t\t*              1.Add product to cart                *" << endl
			 << "\t\t\t\t*              2.View all report                    *" << endl
			 << "\t\t\t\t*              3.Sign out                           *" << endl
			 << "\t\t\t\t*              0.Exit                               *" << endl
			 << "\t\t\t\t*****************************************************" << endl
			 << "\t\t\t\tEnter your choice : ";

	}
};