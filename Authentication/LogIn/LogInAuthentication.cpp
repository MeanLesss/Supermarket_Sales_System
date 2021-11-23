#pragma once
#include<iostream>
#include<fstream>
#include "../../Account/AccountUser.cpp"
#include "../../Cashier/Cashier.cpp"
#include "../../Manager/Manager.cpp"

class LogInAuthentication 
{
private:
    AccountUser account;

    int count,loggedIn;
    char role[20];

public:
	LogInAuthentication():count(0),loggedIn(0) {}
    ~LogInAuthentication() {}
	//log in

    int authenticateUser(char username[], char password[])
    {
        ifstream fin;
        fin.open("user.dat", ios::in | ios::binary);
        count = 0;
        while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
        {
            if (account.getName() == username && account.getPassword() == password)
            {
                if (account.getRole() == "manager")
                {
                    loggedIn = 1;
                    count ++;
                    memcpy(this->role, "manager", 8);
                    Manager manager(account.getUserName(), account.getPassWord(), role);
                    cout << "\t\t\t\tLogged in as :" << endl;
                    manager.DisplayManager();
                    fin.close();
                    break;
                }
                if (account.getRole() == "cashier")
                {
                    loggedIn = 2;

                    count ++;
                    memcpy(this->role, "cashier", 8);
                    Cashier cashier(account.getUserName(), account.getPassWord(), role);
                    cout << "\t\t\t\tLogged in as :" << endl;
                    cashier.DisplayCashier();

                    fin.close();
                    break;
                }
            }

        }
        fin.close();
        if (count == 0)
        {
            loggedIn = 3;
        }
        return loggedIn;
        
    }

};
