#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include "../../Manager/Manager.cpp"
#include "../../Cashier/Cashier.cpp"
#include "../../Product/Product.cpp"
#include "../FileUtility.cpp"
using namespace std;
const char USER_FILE[] = "user.dat";
const char PRODUCT_FILE[] = "product.dat";


class Service 
{
private:

	Manager manager;
	Cashier cashier;
	Product product;

	string UserName;
	string PassWord;
	FileIO fileIO;

public:

	Service() :UserName("unknown"), PassWord("unknown") { }
	Service(string UserName) : UserName(UserName) { }
	Service(string UserName, string PassWord) :UserName(UserName), PassWord(PassWord) { }

	//Manager file in out
	void SignUp(AccountUser& account)//add admin
	{
		fileIO.OpenDataToFile(USER_FILE);
		fileIO.WriteDataToFileUser(account);
		fileIO.CloseDataToFile();
	}

	//void LoadFromUser(string role)
	void LoadFromUser(string role)
	{
		AccountUser account;
		ifstream fin;

		fileIO.OpenDataFromFile(USER_FILE);

		fileIO.ReadDataFromFileUser(account, role);

		fileIO.CloseDataFromFile();
	}

	void DeleteUser(string username)
	{
		AccountUser account;

		fileIO.OpenDataToFile("temp.dat");

		fileIO.OpenDataFromFile(USER_FILE);

		fileIO.WriteDeleteUser(account, username);
		
		fileIO.CloseDataFromFile();

		fileIO.CloseDataToFile();

		fileIO.RenameRemoveUser();
		
	}

	void UpdateUser(string username)
	{
		AccountUser account;

		fileIO.OpenDataToFile("temp.dat");

		fileIO.OpenDataFromFile(USER_FILE);

		fileIO.WriteUpdateUser(account,username);

		fileIO.CloseDataFromFile();

		fileIO.CloseDataToFile();

		fileIO.RenameRemoveUser();

	}

	void UpdateProduct(string productname)
	{
		Product product;

		fileIO.OpenDataFromFile(PRODUCT_FILE);

		fileIO.OpenDataToFile("temp.dat");

		fileIO.WriteUpdateProduct(product, productname);
		
		fileIO.CloseDataFromFile();

		fileIO.CloseDataToFile();

		fileIO.RenameRmoveProduct();
	}

	//File in out for product
	void SaveToProduct(Product product)
	{
		fileIO.OpenDataToFile(PRODUCT_FILE);
		fileIO.WriteDataToProduct(product);
		fileIO.CloseDataToFile();
	}
	void LoadFromProduct()
	{
		Product product;

		fileIO.OpenDataFromFile(PRODUCT_FILE);

		fileIO.ReadDataFromProduct(product);

		fileIO.CloseDataFromFile();
	}

	void DeleteProduct(string productname)
	{
		Product product;
		ifstream fin;
		ofstream fout;

		fileIO.OpenDataFromFile(PRODUCT_FILE);

		fileIO.OpenDataToFile("temp.dat");

		fileIO.WriteDeleteProduct(product, productname);

		fileIO.CloseDataFromFile();

		fileIO.CloseDataToFile();

		fileIO.RenameRmoveProduct();

	}

};