#pragma once
#include<iostream>
#include<vector>
#include "../Product/CartProduct/CartProduct.cpp"
#include "../SYSTEM/GetTimeAndDate.cpp"

using namespace std;


class Report:CartProduct
{
private:
	CartProduct cartProduct;
	GetTimeAndDate dateAndTime;

	char dateTime[50];
	char ProductName[20];
	int ProductNo;
	float Price;
	int quantity;
	float Discount;

	float total;

public:
	Report():ProductName("unknown"), ProductNo(0), Price(0), quantity(0), Discount(0), total(0) {}
	Report(char ProductName[],int ProductNo,float Price,int quantity,float Discount)
		:CartProduct(ProductName,ProductNo,Price,quantity,Discount)
	{
		
	}
	~Report(){}

	

	void DisplayReport()
	{
		cout << "+ " << ProductNo << ".\t||  " << ProductName << "\t\t$" << Price << "\t\t " << quantity << "pcs\t\t " << Discount << "%\t\t" << "total : $" << total << endl;
	}
};
