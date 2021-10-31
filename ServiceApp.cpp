#pragma once
#include"Service.cpp"
#include"Menu.cpp"
#include"ManagerService.cpp"
#include"AccountUser.cpp"

class ServiceApp
{
private:
	Manager manager;
	ManagerService ManService;
	Menu menu;
	Service service;
	AccountUser account;

	char loginmenu;

public:
	//ServiceApp():loginmenu('0') {}
	void LogIn()
	{

		cout << "\t\t\t\tLogged in as manager" << endl;
		ManService.LogInAsManager();
		//or cashier service
		cout << "\t\t\t\tLogged in as cashier" << endl;

	}
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
				LogIn();
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