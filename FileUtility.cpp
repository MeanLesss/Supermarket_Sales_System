#include <iostream>
#include "User.cpp"
#include <fstream>
#include "FileNotFoundException.cpp"
using namespace std;

class FileUtil{
private:
    ofstream fout;
    ifstream fin;
public:
    void openOutputFile(string filename){//OpenDataToFile(string filename)
        try{
            fout.open(filename, ios::out|ios::app|ios::binary);
        }catch(FileNotFoundException e){
            cerr<<e.what()<<endl;
        }
        
    }
    ifstream openInputFile(string filename){//OpenDataFromFile(string filename)
        ifstream fin;
        try{
            fin.open(filename, ios::in|ios::binary);
        }catch(FileNotFoundException e){
            cerr<<e.what()<<endl;
        }
        return fin;
    }
    void writeDataToFile(User user){//save it to void WriteDataTooFile(AccountUser & account)
        fout.write((char*)& user, sizeof(User));
        // fout.write(reinterpret_cast<char*>(&account),sizeof(Account));
    }
    void ReadDataFromFile(/*AccountUser & account*/)
    {
       // fin.read(reinterpret_cast<char*>(&account),sizeof(AccountsUser));
    }

    void closeOutputFile(){//CloseDataToFile()
        fout.close();
    }
    void CloseDataFromFile()
    {
        fin.close();
    }

   
};