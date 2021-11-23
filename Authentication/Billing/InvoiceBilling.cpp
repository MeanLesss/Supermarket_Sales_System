#pragma once
#include "../../Report/Report.cpp"
#include "../../Product/CartProduct/CartProduct.cpp"
#include "../../SYSTEM/GetTimeAndDate.cpp"
#include "../../Report/ReportService.cpp"
using namespace std;

class InvoiceBilling
{
private:
	CartProduct cartProduct;
	ReportService reportService;
	GetTimeAndDate dateAndTime;


	float subtotal;
	char dateTime[50];

public:
	InvoiceBilling():subtotal(0),dateTime("unknown") {}
	~InvoiceBilling() {}

	void PrintInvoice(vector<CartProduct> storingProduct) 
	{
		unsigned int size = storingProduct.size();

		memcpy(this->dateTime, dateAndTime.getDateAndTime(), 50);

		cout << "Date & Time : " << dateTime << endl;
		cout << "===========================================================================================================" << endl;
		cout << "......................................................INVOICE.............................................." << endl;
		cout << "===========================================================================================================" << endl;
		for (unsigned int i = 0; i < size; i++)
		{
			storingProduct[i].DisplayProductInCart();
			subtotal += storingProduct[i].getTotal();
		}
		cout << "===========================================================================================================" << endl;
		cout << "|| Sub Total ____________________________________________________________________________________$" << subtotal << endl;
		cout << "===========================================================================================================" << endl;
		cout << "                                               --See you again soon--" << endl;

		reportService.SaveSaleReport(storingProduct);
		storingProduct.clear();

	}
	
};

