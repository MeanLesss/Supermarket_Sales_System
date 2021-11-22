#pragma once
#include<iostream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#include "../../SYSTEM/GetTimeAndDate.cpp"

using namespace std;
class CartProduct
{
private:
	GetTimeAndDate dateAndTime;

	char dateTime[30];
	char ProductName[20];
	int ProductNo;
	float Price;
	int quantity;
	float Discount;
	float total;


public:
	//Use to store product when cashier add product to cart.
	CartProduct():ProductName("unknown"),ProductNo(0),Price(0),quantity(0),Discount(0),total(0) {}
	CartProduct(char ProductName[20], int ProductNo, float Price, int quantity, float Discount)
	{
		memcpy(this->ProductName, ProductName, 20);
		this->ProductNo = ProductNo;
		this->Price = Price;
		this->quantity = quantity;
		this->Discount = Discount;
		this->total = 0;
	}
	CartProduct(char ProductName[20], int ProductNo, float Price, int quantity, float Discount,float total)
	{
		memcpy(this->ProductName, ProductName, 20);
		memcpy(this->dateTime, "unknown", 50);
		this->ProductNo = ProductNo;
		this->Price = Price;
		this->quantity = quantity;
		this->Discount = Discount;
		this->total = total;
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
	void setDateTime(char dateTime[])
	{
		memcpy(this->dateTime, dateTime, 30);
	}
	void DisplayProductInCart()
	{
		float sellingPrice;
		//display -> id -> name -> quantity -> discount -> total for the product
		if (Discount != 0)
		{
			sellingPrice = Price * ((100 - Discount) / 100);
			total = sellingPrice;
			total *= quantity;
		}
		else
		{
			total = Price * quantity;
		}
		

		//cout << "+ " << ProductNo << ".\t||  " << ProductName << "\t\t\t$" << Price << "\t\t " << quantity << "pcs\t\t " << Discount << "%\t\t" << "total : $" << total << endl;
		cout << "+ " << left << ProductNo << setw(4) << "||" 
			 << ProductName << setw(15) << "||$" 
			 << Price << setw(20) << "||" 
			 << quantity << "pcs" << setw(15) << "||" 
			 << Discount << "%" << setw(25) << " ||total : $" 
			 << total << endl;

	}

	void DisplayDateFromReport()
	{
		cout << "Report Date and Time : " << dateTime << endl;
	}


};
