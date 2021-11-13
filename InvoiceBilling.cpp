#pragma once
#include"CartProduct.cpp"
#include"Product.cpp"
#include"application.cpp"
using namespace std;

class InvoiceBilling
{
private:


public:
	InvoiceBilling() {}
	~InvoiceBilling() {}

	void PrintInvoice(vector<Product> storingProduct)
	{
		cout << "\t\t\t\t\t.....INVOICE....." << endl;
		cout << "\t\t\t\t========================================" << endl;

		//don't forget to delete vector after print the invoice
		storingProduct.clear();
	}
};

