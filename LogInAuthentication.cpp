#pragma once
#include<iostream>
#include"ManagerService.cpp"
#include"CashierService.cpp"
#include"AccountUser.cpp"

class LogInAuthentication 
{
private:
	ManagerService ManService;
	CashierService CashService;
    AccountUser account;
    Cashier cashier;
    Manager manager;
public:
	LogInAuthentication(){}
	//log ins

	// Need log in control statement to devide the program 
	// and to go back and forth from menu to menu

    AccountUser* authenticateUser(char username[], char password[])
    {
        ifstream fin;
        fin.open(USER_FILE, ios::in | ios::binary);
        while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser))) {
            if (account.getName() == username && account.getPassword() == password) {

                if (account.getRole() == "manager")
                {   
                    char role[20] = "manager";
                    manager = Manager(username, password,role);
                    cout << "\t\t\t\tLogged in as :" << endl;
                    manager.DisplayManager();
                    ManService.LogInAsManager();
                    break;
                }
                if (account.getRole() == "cashier")
                {
                    char role[20] = "cashier";
                    Cashier cashier(username, password, role);
                    cout << "\t\t\t\tLogged in as :" << endl;
                    cashier.DisplayCashier();
                    CashService.LogInAsCashier();
                    break;
                }
            }

        }
        fin.close();
        return nullptr;

    }


};
