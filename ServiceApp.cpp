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

	char loginmenu;

public:
	ServiceApp(){}
	
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
				Login.LogIn();
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
				exit(1);
				break;
			}
		} while (loginmenu != '4');
	}
};