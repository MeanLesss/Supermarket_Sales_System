#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include"AccountUser.cpp"
#include"CartProduct.cpp"
#include"Cashier.cpp"
#include"Manager.cpp"
using namespace std;

class FileIO
{
private:
    ofstream fout;
    ifstream fin;

    int count = 0;
public:
    void OpenDataToFile(string filename)//OpenDataToFile(string filename)
    {
        fout.open(filename, ios::out | ios::app | ios::binary);
        if (!fout) 
        {
            cerr << "File open failed! " << endl;
            system("pause");
        }
    }

    void OpenDataFromFile(string filename) //OpenDataFromFile(string filename)
    {
        fin.open(filename, ios::in|ios::binary);
        if (!fin)
        {
            cerr << "File open failed! " << endl;
            system("pause");
        }
        fin.seekg(0, ios::beg);
    }

    void WriteDataToFileUser(AccountUser account)//save it to void WriteDataTooFile(AccountUser & account)
    {
        fout.write(reinterpret_cast<char*>(&account),sizeof(AccountUser));
    }

    void ReadDataFromFileUser(AccountUser & account,string role)
    {
        Manager manager;
        Cashier cashier;
        count = 0;
        if (role == "manager")
        {
            while (1)
            {
                fin.read(reinterpret_cast<char*>(&manager), sizeof(AccountUser));
                if (fin.eof()) { break; }
                if (manager.getRole() == role)
                {
                    manager.DisplayManager();
                    cout << endl;
                }

            }
        }
        else if (role == "cashier")
        {
            while (1)// I use this method because it read better than the function read in while(argument)
            {
                fin.read(reinterpret_cast<char*>(&cashier), sizeof(AccountUser));
                if (fin.eof()) { break; }

                if (cashier.getRole() == role)
                {
                    cashier.DisplayCashier();
                    cout << endl;
                }

            }
        }
    }

    void WriteUpdateUser(AccountUser account, string username)
    {
        count = 0;
        fin.seekg(0, ios::beg);
        while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
        {
            if (fin.eof()) { break; }
            if (account.getUsername() != username)
            {
                WriteDataToFileUser(account);
            }
            else
            {
                account.CreateUser(2);
                WriteDataToFileUser(account);
                count++;
            }
        }
        if (count == 0)
        {
            cout << "Account not found" << endl;
        }
    }

    void WriteDeleteUser(AccountUser account, string username)
    {
        count = 0;
        while (fin.read(reinterpret_cast<char*>(&account), sizeof(AccountUser)))
        {
            if (fin.eof()) { break; }
            if (account.getUsername() != username)
            {
                WriteDataToFileUser(account);
            }
            else
            {
                count++;
            }
        }
        if (count == 0)
        {
            cout << "\t\t\t\tAccount not found" << endl;
        }
        else
        {
            cout << "\t\t\t\tUser deleted" << endl;
        }
    }

















    void RenameRemoveUser()
    {
        int res = 0;
        if (remove("user.dat") != 0)
        {
            cout << "Failed to remove file!" << endl;
        }
        //remove(USER_FILE);
        res = rename("temp.dat", "user.dat");
        if (res == 0)
        {
            cout << "Succeed!" << endl;
        }
        else
        {
            cout << "Failed to rename file" << endl;
        }
    }





    void WriteDataToFileReport(vector<CartProduct> storingProduct)
    {
        unsigned int size = storingProduct.size();
        for (unsigned int i = 0; i < size; i++)
        {
            fout.write(reinterpret_cast<char*>(&storingProduct[i]), sizeof(CartProduct));
        }

    }
    void ReadDataFromReport(CartProduct cartProduct)
    {
        while (fin.read(reinterpret_cast<char*>(&cartProduct), sizeof(CartProduct)))
        {
            if(fin.eof()) { break;}
            cartProduct.DisplayProductInCart();
            
        }
    }


    void CloseDataToFile()
    {
        fout.close();
    }
    void CloseDataFromFile()
    {
        fin.close();
    }

   
};