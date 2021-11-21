#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stdio.h>
using namespace std;

class Product
{
private:
	

	char ProductName[20];
	int ProductNo;
	float Price;
	int Quantity;
	float Discount;

public:

	Product() :ProductName("unknown"), ProductNo(0), Price(0), Quantity(0), Discount(0){ }

	Product(char ProductName[], int ProductNo, float Price, int Quantity, float Discount) 
	{
		memcpy(this->ProductName, ProductName, 20);
		this->ProductNo = ProductNo;
		this->Price = Price;
		this->Quantity = Quantity;
		this->Discount = Discount;
	}
	

	int getProductNo()
	{
		return ProductNo;
	}
	string getProductName() 
	{
		return ProductName;
	}
	char* getName() 
	{
		return ProductName;
	}
	void setProductName(char productname[])
	{
		memcpy(this->ProductName, productname, 20);
	}

	void setProductNo(int ProductNo)
	{
		this->ProductNo = ProductNo;
	}

	int getQuantity()
	{
		return Quantity;
	}
	void setQuantity(int quantity)
	{
		this->Quantity = quantity;
	}
	float getPrice()
	{
		return Price;
	}
	float getDis()
	{
		return Discount;
	}
	void CreateProduct() 
	{
		cout << "\t\t\t\tCreate product : Note (do NOT use space for product name use \"_\" instead)" << endl << endl;
		cout << "\t\t\t\tEnter product name : ";
		cin >> ProductName;
		cout << "\t\t\t\tEnter product price : $";
		cin >> Price;
		cout << "\t\t\t\tEnter product quantity : ";
		cin >> Quantity;
		cout << "\t\t\t\tEnter discount : ";
		cin >> Discount;
	}

	void DisplayProduct()
	{
		
		cout << "==================================================================================================" << endl;
		cout << "|| " << ProductNo << ".\t||  " << ProductName << "\t\t\t||$" << Price << "\t\t|| " << Quantity << "pcs\t\t|| " << Discount << "%\t\t||" << endl;
		cout << "==================================================================================================" << endl;
	}
	

};