#pragma once
using namespace std;
#include "../Service/FileUtility.cpp"
//#include "../Authentication/Billing/InvoiceBilling.cpp"const char REPORT_FILE[] = "report.dat";
const char REPORT_FILE[] = "report.dat";

class ReportService
{
private:
	CartProduct cartProduct;
	GetTimeAndDate dateAndTime;
	FileIO fileIO;
	Report report;


public:
	ReportService() {}
	~ReportService() {}


	void SaveSaleReport(vector<CartProduct> storingProduct)
	{
		fileIO.OpenDataToFile(REPORT_FILE);
		fileIO.WriteDataToFileReport(storingProduct,dateAndTime);
		fileIO.CloseDataToFile();

	}

	void LoadSaleReport()
	{
		fileIO.OpenDataFromFile(REPORT_FILE);

		for (int i = 0; i < 10; i++)
		{
			cout << "report" << i << endl;
			for (int j = i ; j <= i ; j++)
			{
				fileIO.ReadDataFromReport();
			}

		}

		fileIO.CloseDataFromFile();
	}

};
