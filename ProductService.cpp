#pragma once
#include<iostream>
#include<vector>
#include<conio.h>
#include"Menu.cpp"
#include"AddToCart.cpp"
#include"Product.cpp"
#include"InvoiceBilling.cpp"
using namespace std;

class ProductService
{
private:
	Menu menu;
	vector<Product> storingProduct;
	Product product;
	InvoiceBilling invoice;

	unsigned int size;
	int count = 0;
	char option;
	int id;
	int quantity;
public:
	ProductService() {}
	~ProductService() {}

	void Addtocart()//billing in Invoice.cpp
	{
		storingProduct.clear();
		do
		{
			cout << "\t\t\t\t\tAdd To Cart....." << endl;
			cout << "\t\t\t\t========================================" << endl;
			menu.DisplayProductHeader();
			product.LoadFromProduct();
			cout << "Enter product ID to add to cart : ";
			cin >> id;
			cout << "Enter the amount of product : ";
			cin >> quantity;
			//product
			int count = 0;
			ifstream fin;
			fin.open(PRODUCT_FILE, ios::in | ios::binary);
			if (!fin)
			{
				cerr << "File open failed";
				exit(1);
			}
			while (fin.read(reinterpret_cast<char*>(&product), sizeof(Product)))
			{
				if (id == product.getProductNo())
				{
					cout << "Product ADDED!!" << endl;
					storingProduct.push_back(product);
					PrintAddedProduct(storingProduct);
					break;
				}
				else
				{
					cout << "Sorry Product NOT FOUND!!" << endl;
				}
			}
			fin.close();
			cout << "1.Add more item" << endl
				<< "2.Procced payout" << endl
				<< "3.Remove item" << endl
				<< "0.exit" << endl
				<< "Enter option : ";
			option = _getche();
			switch (option)
			{
			case '1':
			case 'Y':
				system("cls");

				break;
			case '2':
			case 'N':
				system("cls");
				invoice.PrintInvoice(storingProduct);
				storingProduct.clear();
				option = '0';
				break;
			case '3':
				system("cls");
				cout << "\t\t\t\t\tRemove item....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				PrintAddedProduct(storingProduct);
				cout << "Enter ID to REMOVE item : "; cin >> id;
				RemoveItem(id);
				cout << "Item REMOVED" << endl;
				system("pause");
				break; 
			}
			//if no print invoice;
		} while (option != '0');
	}
	void PrintAddedProduct(vector<Product>& storingProduct)
	{
		unsigned int size = storingProduct.size();
		for (unsigned int i = 0; i < size; i++)
		{
			storingProduct[i].DisplayInCart(quantity);
		}
	}
	void RemoveItem(int id)
	{
		storingProduct.erase(storingProduct.begin()+id);
	}

	
};