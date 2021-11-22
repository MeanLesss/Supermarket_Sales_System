#pragma once

#include "../Account/AccountUser.cpp"
#include "../Service/Services/Service.cpp"
#include "../Main/Menu.cpp"

class ManagerService:public Menu
{
private:

	AccountUser account;
	Service service;
	//Menu menu;
	Product product;

	string name;
	char optMain,
		optProdCRUD,
		optCashCRUD;
public:

	ManagerService() :name("unknown"), optMain(' '), optProdCRUD(' '), optCashCRUD(' ') {}
	~ManagerService() {}

	void LogInAsManager()
	{
		do
		{
			DisplayManagerMenu();//display main menu
			optMain = _getche();
			switch (optMain)//option for manager menu
			{
			case '1'://option in manager menu
				do
				{
					system("cls");
					DisplayManagerProductCRUD();//display product crud
					optProdCRUD = _getche();
					switch (optProdCRUD)//option for product CRUD
					{

					case '1':

						system("cls");
						cout << "\t\t\t\t\tCreate Product....." << endl;
						cout << "\t\t\t\t========================================" << endl;
						product.CreateProduct();
						service.SaveToProduct(product);
						cout << "Product Created" << endl;
						system("pause");
						system("cls");
						break;

					case '2':

						system("cls");
						cout << "\t\t\t\t\tDisplay all Product....." << endl;
						cout << "\t\t\t\t========================================" << endl;
						DisplayProductHeader();
						service.LoadFromProduct();
						system("pause");
						system("cls");
						break;

					case '3':

						system("cls");
						cout << "\t\t\t\t\tUpdate Product....." << endl;
						cout << "\t\t\t\t========================================" << endl;
						DisplayProductHeader();
						service.LoadFromProduct();
						cout << "Enter product name : "; cin >> name;
						service.UpdateProduct(name);
						cout << "Product updated...." << endl;
						system("pause");
						system("cls");
						break;

					case '4':

						system("cls");
						cout << "\t\t\t\t\tDelete Product....." << endl;
						cout << "\t\t\t\t========================================" << endl;
						DisplayProductHeader();
						service.LoadFromProduct();
						cout << "Enter product Name : "; cin >> name;
						service.DeleteProduct(name);
						cout << "Product deleted...." << endl;
						system("pause");
						system("cls");
						break;

					case '5': //back to menu

						system("cls");

						break;
					}
				
				} while (optProdCRUD != '5');
				break;

			case '2'://option in manager menu
				
				do
				{
					system("cls");
					DisplayManagerAccountCRUD();
					optCashCRUD = _getche();
					switch (optCashCRUD)//option for manager CRUD
					{
					case '1':

						system("cls");
						cout << "\t\t\t\t\tCreate Cashier Account....." << endl;
						cout << "\t\t\t\t========================================" << endl;
						account.CreateUser(2);// 2 is for cashier role
						service.SignUp(account);
						cout << "Cashier Account Updated...." << endl;
						system("pause");
						system("cls");
						break;

					case '2':

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

					case '3':

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

					case '4':

						system("cls");
						cout << "\t\t\t\t\tDisplay Cashier Account....." << endl;
						cout << "\t\t\t\t========================================" << endl;
						service.LoadFromUser("cashier");
						system("pause");
						system("cls");
						break;

					case '5': //back to menu

						system("cls");

						break;

					case '0':

						exit(1);
						break;
					}
				} while (optCashCRUD != '5');
				break;

			case '0': // exit in manager menu
				exit(1);
				break;
				
			}
		} while (optMain != '3');
	}

};