#pragma once
#include<iostream>
#include<fstream>
#include "../../Account/AccountUser.cpp"

class LogInAuthentication 
{
private:
    AccountUser account;

    bool count,loggedIn;

public:
	LogInAuthentication():count(0),loggedIn(0) {}
    ~LogInAuthentication() {}
	//log in

    bool authenticateUser(char username[], char password[])
    {
        ifstream fin;
        fin.open("user.dat", ios::in | ios::binary);
        count = false;
        while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
        {
            if (account.getName() == username && account.getPassword() == password)
            {
                if (account.getRole() == "manager")
                {
                    loggedIn = true;
                    count = true;
                    break;
                }
                if (account.getRole() == "cashier")
                {
                    loggedIn = false;
                    count = true;
                    break;
                }
            }

        }
        fin.close();
        if (count == false)
        {
            cout << "\t\t\t\t=======================================" << endl;
            cout << "\t\t\t\t||  Incorrect password or username!  ||" << endl;
            cout << "\t\t\t\t=======================================" << endl;
            system("pause");
        }
        return loggedIn;
    }

};
