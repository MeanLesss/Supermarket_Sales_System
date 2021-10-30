#pragma once
#include"Service.cpp"
#include"Menu.cpp"
#include"ManagerService.cpp"

class ServiceApp
{
private:
	Manager manager;
	ManagerService ManService;
	Menu menu;
	Service service;

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
				manager.CreateManager();
				service.SignUp(manager);
				break;
			case '3':
				system("cls");

				service.LoadFromManager();
				
				system("pause");
				break;

			case '4':
				exit;
				break;
			}
		} while (loginmenu != '4');
	}
};