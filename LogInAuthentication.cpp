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

    int count;
public:
	LogInAuthentication():count(0) {}
	//log ins


    void authenticateUser(char username[], char password[])
    {
        ifstream fin;
        fin.open(USER_FILE, ios::in | ios::binary);
        count = 0;
        while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
        {
            if (account.getName() == username && account.getPassword() == password) 
            {
                if (account.getRole() == "manager")
                {   
                    char role[20] = "manager";
                    manager = Manager(username, password,role);
                    cout << "\t\t\t\tLogged in as :" << endl;
                    manager.DisplayManager();
                    fin.close();
                    ManService.LogInAsManager();
                    count++;
                    break;
                }
                if (account.getRole() == "cashier")
                {
                    char role[20] = "cashier";
                    Cashier cashier(username, password, role);
                    cout << "\t\t\t\tLogged in as :" << endl;
                    cashier.DisplayCashier();
                    fin.close();
                    CashService.LogInAsCashier();
                    count++;
                    break;
                }
            }

        }
        fin.close();
        if (count == 0) 
        {
            cout << "\t\t\t\t=======================================" << endl;
            cout << "\t\t\t\t||  Incorrect password or username!  ||" << endl;
            cout << "\t\t\t\t=======================================" << endl;
            system("pause");
        }
    }

    


};
