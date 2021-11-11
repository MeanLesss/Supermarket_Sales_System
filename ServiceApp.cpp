#pragma once
#include"Service.cpp"
#include"Menu.cpp"
#include"AccountUser.cpp"
#include"LogInAuthentication.cpp"

class ServiceApp
{
private:
	LogInAuthentication Login;
	Manager manager;
	Menu menu;
	Service service;
	AccountUser account;
	
	string name;
	char Username[20];
	char Password[20];
	char loginmenu;

public:
	ServiceApp() {}


	void MenuProcess()
	{
		do
		{
			system("cls");
			menu.DisplayLogInMenu();
			loginmenu = _getche();
			cout << endl;
			switch (loginmenu)
			{
			case '1':
				system("cls");
				cout << "\t\t\t\t\t\tLoggin in....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				cout << "\t\t\t\tEnter username : "; cin >> Username;
				cout << "\t\t\t\tEnter password : "; cin >> Password;
				system("cls");
				Login.authenticateUser(Username, Password);
				break;
			case '2':
				system("cls");
				cout << "\t\t\t\t\tCreate Manager Account....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				account.CreateUser(1);
				service.SignUp(account);
				cout << "Manager Account Created......" << endl;
				system("pause");
				break;
			case '3':
				system("cls");
				cout << "\t\t\t\t\tDisplay Cashier Account....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				service.LoadFromUser("manager");
				system("pause");
				break;

			case '4':
				system("cls");
				cout << "\t\t\t\t\tDelete Manager Account....." << endl;
				cout << "\t\t\t\t========================================" << endl;
				service.LoadFromUser("manager");
				cout << "\t\t\t\tEnter a username to DELETE : "; cin >> name;
				service.DeleteUser(name);
				cout << "Manager Account deleted....." << endl;
				system("pause");
				break;
			case '5':
				exit(1);
				break;
			}
		} while (loginmenu != '5');
	}

	
};