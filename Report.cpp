#pragma once
#include<iostream>
#include<vector>
#include"FileUtility.cpp"
#include"CartProduct.cpp"
using namespace std;
const char REPORT_FILE[] = "report.dat";


class Report
{
private:
	FileIO fileIO;
	CartProduct cartProduct;

public:
	Report() {}
	~Report(){}
	void SaveSaleReport(vector<CartProduct> storingProduct)
	{
		fileIO.OpenDataToFile(REPORT_FILE);
		fileIO.WriteDataToFileReport(storingProduct);
		fileIO.CloseDataToFile();

	}

	void LoadSaleReport()
	{
		fileIO.OpenDataFromFile(REPORT_FILE);
		
		fileIO.ReadDataFromReport(cartProduct);

		fileIO.CloseDataFromFile();
	}
};
/*cout << "===========================================================================================================" << endl;
		cout << "|| " << ProductNo << ".\t||  " << ProductName << "\t\t\t||$" << Price << "\t\t|| " << quantity << "pcs\t\t|| " << Discount << "%\t\t||" << "total : $" << total << endl;
		cout << "===========================================================================================================" << endl;*/
