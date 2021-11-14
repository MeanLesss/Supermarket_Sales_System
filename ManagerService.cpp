#pragma once
#include"Service.cpp"
#include"Manager.cpp"
#include"Product.cpp"
#include"Cashier.cpp"
#include"Menu.cpp"
#include"AccountUser.cpp"
class ManagerService
{
private:
	
	AccountUser account;
	Manager manager;
	Service service;
	Menu menu;
	Product product;
	Cashier cashier;

	string name;
	char option;
public:
	void LogInAsManager()
	{
		do
		{
			menu.DisplayManagerMenu();
			option = _getche();
			switch (option)
			{
			case '1':
				system("cls");
				cout << "\t\t\t\t\tCreate Product....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				product.CreateProduct();
				product.SaveToProduct(product);
				cout << "Product Created" << endl;
				system("pause");
				system("cls");
				break;
			case '2':
				system("cls");
				cout << "\t\t\t\t\tDisplay all Product....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				menu.DisplayProductHeader();
				product.LoadFromProduct();
				system("pause");
				system("cls");
				break;
			case '3':
				system("cls");
				cout << "\t\t\t\t\tUpdate Product....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				menu.DisplayProductHeader();
				product.LoadFromProduct();
				cout << "Enter product name : "; cin >> name;
				product.UpdateProduct(name);
				cout << "Product updated...." << endl;
				system("pause");
				system("cls");
				break;
			case '4':
				system("cls");
				cout << "\t\t\t\t\tDelete Product....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				menu.DisplayProductHeader();
				product.LoadFromProduct();
				cout << "Enter product Name : "; cin >> name;
				product.DeleteProduct(name);
				cout << "Product deleted...." << endl;
				system("pause");
				system("cls");
				break;
			case '5':
				system("cls");
				cout << "\t\t\t\t\tCreate Cashier Account....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				account.CreateUser(2);// 2 is for cashier role
				service.SignUp(account);
				cout << "Cashier Account Updated...." << endl;
				system("pause");
				system("cls");
				break;
			case '6':
				system("cls");
				cout << "\t\t\t\t\tUpdate Cashier Account....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				service.LoadFromUser("cashier");
				cout << "Enter cashier name to update : "; cin >> name;
				service.UpdateUser(name);
				cout << "Cashier Account Updated...." << endl;
				system("pause");
				system("cls");
				break;
			case '7':
				system("cls");
				cout << "\t\t\t\t\tDelete Cashier Account....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				service.LoadFromUser("cashier");
				cout << "\t\t\t\tEnter a cashier to DELETE : "; cin >> name;
				service.DeleteUser(name);
				cout << "Cashier Account Updated...." << endl;
				system("pause");
				system("cls");
				break;
			case '8':
				system("cls");
				cout << "\t\t\t\t\tDisplay Cashier Account....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				service.LoadFromUser("cashier");
				system("pause");
				system("cls");
				break;
			case '9':
				system("cls");

				break;
			case '0':
				exit(1);
				break;
			}
		} while (option != '9');
	}
};