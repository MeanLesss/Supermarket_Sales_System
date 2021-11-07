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
	START:
		menu.DisplayManagerMenu();
		option = _getche();
		switch (option)
		{
		case '1':
			system("cls");
			product.CreateProduct();
			product.SaveToProduct(product);
			system("pause");
			goto START;
			break;
		case '2':
			system("cls");
			cout << "======================================================================================================" << endl;
			cout << "|| No\t|| product name\t\t\t||price\t\t\t|| quantity\t\t\t|| Discount\t||" << endl;
			product.LoadFromProduct();
			system("pause");
			goto START;

			break;
		case '3':
			system("cls");
			product.SearchProduct();
			product.UpdateProduct(product);
			system("pause");
			goto START;

			break;
		case '4':
			system("cls");
			/*product.SearchProduct();
			product.RemoveProduct(product);*/
			product.LoadFromProduct();
			cout << "Enter the product Name : "; cin >> name;
			product.DeleteProduct(name);
			system("pause");
			goto START;

			break;
		case '5':
			system("cls");
			account.CreateUser(2);// 2 is for cashier
			service.SignUp(account);
			system("pause");
			goto START;

			break;
		case '6':
			system("cls");
			cashier.SearchCashier();
			cashier.UpdateCashier(cashier);
			system("pause");
			goto START;

			break;
		case '7':
			system("cls");
			service.LoadFromUser("cashier");
			cout << "\t\t\t\tEnter a username to DELETE : "; cin >> name;
			service.DeleteUser(name);
			system("pause");
			goto START;

			break;
		case '8':
			system("cls");
			service.LoadFromUser("cashier");
			system("pause");
			goto START;

			break;
		case '9':
			system("cls");

			break;
		case '0':
			exit(1);
			break;
		}
	}
};