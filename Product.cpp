#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//const string ProductFile = "product.dat";


class Product
{
private:
	//char ProductName[20];
	string ProductName;
	float Price;
	float Quantity;
	float Discount;

public:
	int ProductNo;

	Product() :ProductName("unknown"), ProductNo(0), Price(0), Quantity(0), Discount(0){ }
	Product(string ProductName,int ProductNo,float Price,float Quantity) 
	{
		//memcpy(this->ProductName, ProductName,20);
		this->ProductName = ProductName;
		this->ProductNo = ProductNo;
		this->Price = Price;
		this->Quantity = Quantity;
	}
	Product(string ProductName, int ProductNo, float Price, float Quantity, float Discount) 
	{
		//memcpy(this->ProductName, ProductName, 20);
		this->ProductName = ProductName;
		this->ProductNo = ProductNo;
		this->Price = Price;
		this->Quantity = Quantity;
		this->Discount = Discount;
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
	void SearchProduct()
	{

	}
	void AddToCart()
	{


	}


	void UpdateProduct(Product & product)
	{
		cout << "update product";

	}
	void ShowProduct()
	{
		cout << "show product";
	}
	void RemoveProduct(Product & product)
	{
		cout << "remove product";
	}
	void DisplayProduct()
	{
		
		cout << "==================================================================================================" << endl;
		cout << "|| " << ProductNo << "\t||  " << ProductName << "\t\t\t||$" << Price << "\t\t\t|| " << Quantity << "pcs\t\t\t|| " << Discount << "%\t\t||" << endl;
		cout << "==================================================================================================" << endl;
	}


};