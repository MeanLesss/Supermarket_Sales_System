#pragma once
#include<iostream>
#include "../Report/Report.cpp"
#include "../Product/ProductService.cpp"
#include "../Report/ReportService.cpp"
using namespace std;

class CashierService:public ProductService
{
private:
	Menu menu;
	Report report;
	ReportService reportService;

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
			reportService.LoadSaleReport();
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

