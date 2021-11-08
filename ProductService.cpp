#pragma once
#include<iostream>
#include<vector>
#include<conio.h>
#include"Product.cpp"
#include"InvoiceBilling.cpp"
using namespace std;

class ProductService : public Product
{
private:

	vector<Product> addedProduct;
	Product product;
	InvoiceBilling invoice;

	int count = 0;
	char option;
	char ProductName[20];
	float quantity;
public:
	ProductService() {}
	~ProductService() {}

	void Addtocart()//billing in Invoice.cpp
	{
		do
		{
			FillVector();		
		START:

			cout << "Enter product name to add to cart : ";
			cin >> ProductName;
			cout << "Enter the amount of product : ";
			cin >> quantity;
			//product
			product = Product(ProductName, quantity);
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

};