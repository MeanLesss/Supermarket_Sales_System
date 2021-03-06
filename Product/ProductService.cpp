#pragma once
#include<iostream>
#include<vector>
#include<conio.h>
#include"string.h"
#include"Product.cpp"
#include "../Service/Services/Service.cpp"
#include "../Main/Menu.cpp"
#include "../Authentication/Billing/InvoiceBilling.cpp"
using namespace std;

class ProductService
{
private:
	Service service;
	Menu menu;
	CartProduct cartProduct;
	Report cartReport;
	Product product;
	InvoiceBilling invoice;
	GetTimeAndDate dateAndTime;
	
	vector<CartProduct> storingProduct;
	vector<Report> storingForReport;
	vector<int> tempQuantity;
	

	char productName[20];
	unsigned int sizeTemp = tempQuantity.size();
	unsigned int size;
	int count = 0;//use as a error detector in after search
	int countDelete = 0;
	char option;
	int id;
	int quantity;
	int No;// to set product No to the product in vector
	float Price;
	float Discount;
	char dateTime[30];

	

public:
	ProductService():size(0),count(0),countDelete(0),option(0),id(0),quantity(0),tempQuantity(0),No(0),Price(0),Discount(0) {}
	~ProductService() {}

//Not enough time to refactor this part

	void Addtocart()//billing in Invoice.cpp
	{

		storingProduct.clear();
		do
		{
			count = 0;
			No = 0;
			cout << "\t\t\t\t\tAdd To Cart....." << endl;
			cout << "\t\t\t\t========================================" << endl;
			menu.DisplayProductHeader();
			service.LoadFromProduct();
			cout << "Enter product ID to add to cart : ";
			cin >> id;
			cout << "Enter the amount of product : ";
			cin >> quantity;
			//product
			ifstream fin;
			fin.open(PRODUCT_FILE, ios::in | ios::binary);
			if (!fin)
			{
				cerr << "File open failed";
				exit(1);
			}
			while (fin.read(reinterpret_cast<char*>(&product), sizeof(Product)))
			{
				product.setProductNo(No);//i don't set it manually becasue when it have more product it easier to let it load
				
				if (id == product.getProductNo())
				{
					system("cls");
					cout << "Product ADDED!!" << endl;
					memcpy(this->dateTime,dateAndTime.getDateAndTime(),30);
					cout << dateTime << endl;

					Price = product.getPrice();
					Discount = product.getDis();
					memcpy(this->productName, product.getName(), 20);
					cartProduct = CartProduct(productName, id, Price, quantity, Discount);
					storingProduct.push_back(cartProduct);//push carted product to vector

					PrintAddedProduct(storingProduct);
					count++;
					fin.close();

					tempQuantity.push_back(product.getQuantity());
					quantity = product.getQuantity() - quantity;
					UpdateStock(product.getName(), id, Price, quantity, Discount);//Update the quantity of the product
					break;
				}
				No++;
			}
			if(count == 0)
			{
				cout << "Sorry Product NOT FOUND!!" << endl;
			}
			fin.close();   
			cout << "1.Add more item" << endl
				<< "2.Procced payout" << endl
				<< "3.Remove item" << endl
				<< "4.Back to menu" << endl
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
			{
				system("cls");
				invoice.PrintInvoice(storingProduct);
				storingProduct.clear();
				option = '4';
				system("pause");
				system("cls");
				
				break;
			}
			case '3':
				system("cls");
				cout << "\t\t\t\t\tRemove item....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				PrintAddedProduct(storingProduct);
				countDelete = 0;
				//cout << "Enter ID to REMOVE item : "; cin >> id;
				
				cout << "Sorry this feature will available in the next update!"<<endl;

				//cout << "Item REMOVED" << endl;

				//PrintAddedProduct(storingProduct);

				//option = '4';
				system("pause");
				system("cls");
				break;

			case '4':
				for (unsigned int i = 0; i < size; i++)
				{
					quantity = tempQuantity[i];
					Price = storingProduct[i].getPrice();
					Discount = storingProduct[i].getDiscount();
					memcpy(this->productName, storingProduct[i].getName(), 20);
					id = storingProduct[i].getID();

					UpdateStock(productName, id, Price, quantity, Discount);//Update the quantity of the product
				}
				tempQuantity.clear();
				storingProduct.clear();
				break;
			case '0':
				exit(1);
			}
			//if no print invoice;	
		} while (option != '4');
	}
	void PrintAddedProduct(vector<CartProduct> storingProduct)
	{
		unsigned int size = storingProduct.size();
		for (unsigned int i = 0; i < size; i++)
		{
			storingProduct[i].DisplayProductInCart();
		}
	}
	/*void RemoveItem(int id)
	{
		storingProduct.erase(storingProduct.begin()+id);
	}*/

	void UpdateStock(char productname[],int id,float Price,int quantity,float Discount)
	{
		Product product;
		ifstream fin;
		ofstream fout;

		fin.open(PRODUCT_FILE, ios::in | ios::binary);
		if (!fin)
		{
			cerr << "File open failed";
			exit(1);
		}
		fout.open("temp.dat", ios::out | ios::app | ios::binary);
		fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&product), sizeof(Product)))
		{
			if (fin.eof()) { break; }
			if (product.getProductName() != productname)
			{
				fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
			}
			else
			{
				product = Product(productname, id, Price, quantity, Discount);
				fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
			}
		}
		fin.close();
		fout.close();
		int removeStatus = 0;
		//removeStatus = remove(PRODUCT_FILE);
		if (remove("product.dat") == 0)
		{
			//cout << "Failed to remove!" << endl;
			cout << "success remove" << endl;
		}
		else
		{
			cout << "fail to remove" << endl;
		}
		//remove(USER_FILE);
		int renameStatus;
		renameStatus = rename("temp.dat", "product.dat");
		if (renameStatus == 0)
		{
			cout << "Item renamed!" << endl;
		}
		else
		{
			cout << "Failed to rename" << endl;
		}

	}
};