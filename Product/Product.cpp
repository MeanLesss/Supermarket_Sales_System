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
	Product(char ProductName[], int Quantity)
	{
		memcpy(this->ProductName, ProductName, 20);
		this->Quantity = Quantity;
	}
	Product(char ProductName[], int ProductNo, float Price, int Quantity, float Discount) 
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


	//void UpdateProduct(string productname)
	//{
	//	Product product;
	//	ifstream fin;
	//	ofstream fout;
	//	fin.open(PRODUCT_FILE, ios::in | ios::binary);
	//	if (!fin)
	//	{
	//		cerr << "File open failed";
	//		exit(1);
	//	}
	//	fout.open("temp.dat", ios::out | ios::app | ios::binary);
	//	fin.seekg(0, ios::beg);
	//	while (fin.read(reinterpret_cast<char*>(&product), sizeof(Product)))
	//	{
	//		if (fin.eof()) { break; }
	//		if (product.getProductName() != productname)
	//		{
	//			fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
	//		}
	//		else
	//		{
	//			product.CreateProduct();
	//			fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
	//		}
	//	}
	//	fin.close();
	//	fout.close();
	//	//fout.close();
	//	int removeStatus = 0;
	//	//removeStatus = remove(PRODUCT_FILE);
	//	if (remove("product.dat") == 0)
	//	{
	//		//cout << "Failed to remove!" << endl;
	//		cout << "success remove" << endl;
	//	}
	//	else
	//	{
	//		cout << "fail to remove" << endl;
	//	}
	//	//remove(USER_FILE);
	//	int renameStatus;
	//	renameStatus = rename("temp.dat", "product.dat");
	//	if (renameStatus == 0)
	//	{
	//		cout << "Item renamed!" << endl;
	//	}
	//	else
	//	{
	//		cout << "Failed to rename" << endl;
	//	}

	//}

	////File in out for product
	//void SaveToProduct(Product& product)
	//{
	//	//cout << "\t\t\t\tSign up as admin";
	//	ofstream fout;
	//	fout.open(PRODUCT_FILE, ios::out | ios::app | ios::binary);
	//	if (!fout) {
	//		// throw FileNotFoundException("File open failed");
	//		cerr << "File open failed" << endl;
	//		system("pause");
	//	}
	//	fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
	//	fout.close();
	//}
	//void LoadFromProduct()
	//{
	//	Product product;
	//	int count = 0;
	//	ifstream fin;
	//	fin.open(PRODUCT_FILE, ios::in | ios::binary);
	//	if (!fin) {
	//		// throw FileNotFoundException("File open failed");
	//		cerr << "File open failed" << endl;
	//	}
	//	while (1)
	//	{
	//		fin.read(reinterpret_cast<char*>(&product), sizeof(Product));
	//		product.setProductNo(count);
	//		if (fin.eof()) { break; }
	//		product.DisplayProduct();
	//		count++;
	//	}
	//	fin.close();
	//}

	//void DeleteProduct(string productname)
	//{
	//	Product product;
	//	ifstream fin;
	//	ofstream fout;

	//	fin.open(PRODUCT_FILE, ios::in | ios::binary);
	//	if (!fin) 
	//	{
	//		cerr << "File open failed";
	//		exit(1);
	//	}
	//	fout.open("temp.dat", ios::out | ios::app | ios::binary);
	//	fin.seekg(0, ios::beg);
	//	while (fin.read(reinterpret_cast<char*>(&product), sizeof(Product))) // I use this method because it read better than the function read in while(argument)
	//	{
	//		if (fin.eof()) { break; }
	//		if (product.getProductName() != productname) 
	//		{
	//			fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
	//		}
	//	}
	//	fin.close();
	//	fout.close();
	//	int removeStatus = 0 ;
	//	//removeStatus = remove(PRODUCT_FILE);
	//	if (remove("product.dat") == 0)
	//	{
	//		//cout << "Failed to remove!" << endl;
	//		cout << "success remove" << endl;
	//	}
	//	else
	//	{
	//		cout << "fail to remove" << endl;
	//	}
	//	//remove(USER_FILE);
	//	int renameStatus;
	//	renameStatus = rename("temp.dat", "product.dat");
	//	if (renameStatus == 0)
	//	{
	//		cout << "Item renamed!" << endl;
	//	}
	//	else
	//	{
	//		cout << "Failed to rename" << endl;
	//	}
	//}
	
	void DisplayProduct()
	{
		
		cout << "==================================================================================================" << endl;
		cout << "|| " << ProductNo << ".\t||  " << ProductName << "\t\t\t||$" << Price << "\t\t|| " << Quantity << "pcs\t\t|| " << Discount << "%\t\t||" << endl;
		cout << "==================================================================================================" << endl;
	}
	

};