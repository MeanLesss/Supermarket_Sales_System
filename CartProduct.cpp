#pragma once
#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;
class CartProduct
{
private:
	string ProductName;
	int ProductNo;
	float Price;
	int quantity;
	float Discount;

public:
	CartProduct() {}
	
	CartProduct(string ProductName, int ProductNo, float Price, int quantity, float Discount)
	{
		this->ProductName = ProductName;
		//this->ProductName = ProductName;
		this->ProductNo = ProductNo;
		this->Price = Price;
		this->quantity = quantity;
		this->Discount = Discount;
	}
	~CartProduct() {}
	void DisplayInCart()
	{
		//display -> id -> name -> quantity -> discount -> total for the product
		float total;
		
		cout << "==================================================================================================" << endl;
		cout << "|| " << ProductNo << ".\t||  " << ProductName << "\t\t\t||$" << Price << "\t\t|| " << quantity << "pcs\t\t|| " << Discount << "%\t\t||" << endl;
		cout << "==================================================================================================" << endl;
	}



};
