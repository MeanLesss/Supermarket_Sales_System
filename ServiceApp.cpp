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

	char Username[20], Password[20];
	char loginmenu;

public:
	
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
				cout << "\t\t\t\tEnter username : "; cin >> Username;
				cout << "\t\t\t\tEnter password : "; cin >> Password;
				Login.authenticateUser(Username,Password);
				break;
			case '2':
				system("cls");
				account.CreateUser(1);
				service.SignUp(account);
				break;
			case '3':
				system("cls");

				service.LoadFromUser("manager");
				//manager.DisplayManager(manager);
				
				system("pause");
				break;

			case '4':
				//delete user == manager

				break;
			}
			case '5':
			    exit(1); 
				break;

		} while (loginmenu != '5');
	}
};