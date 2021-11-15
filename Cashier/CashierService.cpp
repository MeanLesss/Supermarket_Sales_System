#pragma once
#include"Cashier.cpp"
#include"ProductService.cpp"
#include"Menu.cpp"
#include"Report.cpp"

class CashierService:public ProductService
{
private:
	Menu menu;
	Product product;
	Report report;

	char option;

public:
	CashierService():option(' ') {}
	//~CashierService() {}
	

	void LogInAsCashier()
	{
		START:
		menu.DisplayCashierMenu();
		option = _getche();
		switch (option)
		{
		case '1':
			system("cls");
			Addtocart();
			system("pause");
			goto START;
			break;
		case '2':
			system("cls");
			report.LoadSaleReport();
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

