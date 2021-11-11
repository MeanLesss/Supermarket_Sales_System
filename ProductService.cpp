#pragma once
#include<iostream>
#include<vector>
#include<conio.h>
#include"Menu.cpp"
#include"Product.cpp"
#include"InvoiceBilling.cpp"
using namespace std;

class ProductService
{
private:
	Menu menu;
	vector<Product> addedProduct;
	Product product;
	InvoiceBilling invoice;

	int count = 0;
	char option;
	int id;
	float quantity;
public:
	ProductService() {}
	~ProductService() {}

	void Addtocart()//billing in Invoice.cpp
	{
		do
		{
			menu.DisplayProductHeader();
			FillVector();		
		START:

			cout << "Enter product ID to add to cart : ";
			cin >> id;
			cout << "Enter the amount of product : ";
			cin >> quantity;
			//product
			for (unsigned int i = 0 ; i < addedProduct.size(); i++)
			{

			}
			addedProduct.push_back(product);
			cout << "Do you want to add more items?(y/n) : "; 
			option = _getche();
			switch (option)
			{
			case 'y':
			case 'Y':
				goto START;
				break;
			case 'n':
			case 'N':
				system("cls");
				invoice.PrintInvoice(addedProduct);
				system("pause");
				break;
			}

			//if no print invoice;
		} while (option != '0');
	}
	vector<Product> FillVector()
	{
		int count = 0;
		Product product;
		vector<Product> addProduct;
		ifstream fin;
		fin.open(PRODUCT_FILE, ios::in | ios::binary);
		if (!fin)
		{
			cerr << "File open failed";
			exit(1);
		}
		while (fin.read(reinterpret_cast<char*>(&product), sizeof(Product)))
		{
			product.setProductNo(count);
			if (fin.eof()) { break; }
			addProduct.push_back(product);
			count++;
		}
		fin.close();

		unsigned int size = addProduct.size();
		for (unsigned int i = 0; i < size; i++)
		{
			addProduct[i].DisplayProduct();
		}
		return addProduct;
	}
	void PrintVector(vector<Product>& addedproduct)
	{
		unsigned int size = addedproduct.size();
		for (unsigned int i = 0; i < size; i++)
		{
			cout << addedproduct[i].getProductName();
		}
	}
};