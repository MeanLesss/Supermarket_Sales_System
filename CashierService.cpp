#pragma once
#include"Cashier.cpp"
#include"Product.cpp"
#include"Menu.cpp"

class CashierService:public Product
{
private:
	Menu menu;
	Product product;
	char option;

public:
	CashierService() {}
	~CashierService() {}


	void LogInAsCashier()
	{
		START:
		menu.DisplayCashierMenu();
		option = _getche();
		switch (option)
		{
		case '1':
			system("cls");

			AddToCart();

			system("pause");
			goto START;
			break;
		case '2':
			system("cls");



			system("pause");
			goto START;
			break;
		case '3':
			system("cls");
			break;
		case '0':
			exit(1);
			break;

		}
	}


};

