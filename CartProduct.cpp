#pragma once
#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;
class CartProduct
{
private:
	char ProductName[20];
	int ProductNo;
	float Price;
	int quantity;
	float Discount;

	float total;


public:
	CartProduct() {}
	
	CartProduct(char ProductName[20], int ProductNo, float Price, int quantity, float Discount)
	{
		memcpy(this->ProductName, ProductName, 20);
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
	char* getName()
	{
		return ProductName;
	}
	int getQuantity()
	{
		return quantity;
	}
	void setQuantity(int quantity)
	{
		this->quantity = quantity;
	}
	float getTotal()
	{
		return total;
	}
	void DisplayProductInCart()
	{
		float sellingPrice;
		//display -> id -> name -> quantity -> discount -> total for the product
		if (Discount != 0)
		{
			sellingPrice = Price * ((100 - Discount) / 100);
			total = Price - sellingPrice;
			total *= quantity;
		}
		else
		{
			total = Price * quantity;
		}
		
		cout << "===========================================================================================================" << endl;
		cout << "|| " << ProductNo << ".\t||  " << ProductName << "\t\t\t||$" << Price << "\t\t|| " << quantity << "pcs\t\t|| " << Discount << "%\t\t||" << "total : $" << total << endl;
		cout << "===========================================================================================================" << endl;
	}



};
