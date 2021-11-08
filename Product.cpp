#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
using namespace std;
const char PRODUCT_FILE[] = "product.dat";

class Product
{
private:
	char ProductName[20];
	int ProductNo;
	float Price;
	float Quantity;
	float Discount;

public:

	Product() :ProductName("unknown"), ProductNo(0), Price(0), Quantity(0), Discount(0){ }
	Product(char ProductName[],int ProductNo,float Price,float Quantity) 
	{
		memcpy(this->ProductName, ProductName,20);
		//this->ProductName = ProductName;
		this->ProductNo = ProductNo;
		this->Price = Price;
		this->Quantity = Quantity;
	}
	Product(char ProductName[], int ProductNo, float Price, float Quantity, float Discount) 
	{
		memcpy(this->ProductName, ProductName, 20);
		//this->ProductName = ProductName;
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

	void setProductNo(int ProductNo)
	{
		this->ProductNo = ProductNo;
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
		cout << "Enter product number : ";
		cin >> ProductNo;

	}


	void UpdateProduct(Product & product)
	{
		cout << "update product";

	}

	//File in out for product
	void SaveToProduct(Product& product)
	{
		//cout << "\t\t\t\tSign up as admin";
		ofstream fout;
		fout.open(PRODUCT_FILE, ios::out | ios::app | ios::binary);
		if (!fout) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed" << endl;
			system("pause");
		}
		fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
		fout.close();
	}
	void LoadFromProduct()
	{
		Product product;
		int count = 0;
		ifstream fin;
		fin.open(PRODUCT_FILE, ios::in | ios::binary);
		if (!fin) {
			// throw FileNotFoundException("File open failed");
			cerr << "File open failed" << endl;
		}
		while (1)
		{
			fin.read(reinterpret_cast<char*>(&product), sizeof(Product));
			product.setProductNo(count);
			if (fin.eof()) { break; }
			product.DisplayProduct();
			count++;
		}

		fin.close();
	}

	void DeleteProduct(string productname)
	{
		Product product;
		ifstream fin;
		ofstream fout;

		fin.open(PRODUCT_FILE, ios::in | ios::binary);
		if (!fin) {
			cerr << "File open failed";
			exit(1);
		}
		fout.open("temp.dat", ios::out | ios::app | ios::binary);
		fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&product), sizeof(Product))) // I use this method because it read better than the function read in while(argument)
		{
			if (fin.eof()) { break; }
			if (product.getProductName() != productname) {
				fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
			}
			else
			{
				continue;
			}
		}
		fin.close();
		fout.close();
		int res = 0;
		if (remove(PRODUCT_FILE) != 0)
		{
			cout << "Failed to remove!" << endl;
		}
		//remove(USER_FILE);
		res = rename("temp.dat", PRODUCT_FILE);
		if (res == 0)
		{
			cout << "Item removed!" << endl;
		}
		else
		{
			cout << "Failed to rename" << endl;
		}
	}
	
	void DisplayProduct()
	{
		
		cout << "==================================================================================================" << endl;
		cout << "|| " << ProductNo << "\t||  " << ProductName << "\t\t\t||$" << Price << "\t\t\t|| " << Quantity << "pcs\t\t\t|| " << Discount << "%\t\t||" << endl;
		cout << "==================================================================================================" << endl;
	}


};