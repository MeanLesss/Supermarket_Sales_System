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

	float total;


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

	int getID()
	{
		return ProductNo;
	}
	string getName()
	{
		return ProductName;
	}
	float getTotal()
	{
		return total;
	}
	void DisplayInCart()
	{
		//display -> id -> name -> quantity -> discount -> total for the product
		
		total = (Price * quantity) - ((Price * Discount) / 100);
		
		cout << "===========================================================================================================" << endl;
		cout << "|| " << ProductNo << ".\t||  " << ProductName << "\t\t\t||$" << Price << "\t\t|| " << quantity << "pcs\t\t|| " << Discount << "%\t\t||" << "total : $" << total << endl;
		cout << "===========================================================================================================" << endl;
	}



};
