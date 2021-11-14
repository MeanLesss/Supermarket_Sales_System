#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include"AccountUser.cpp"
#include"CartProduct.cpp"


using namespace std;

class FileIO
{
private:
    ofstream fout;
    ifstream fin;
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

    void ReadDataFromFileUser(AccountUser & account)
    {
       fin.read(reinterpret_cast<char*>(&account),sizeof(AccountUser));
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