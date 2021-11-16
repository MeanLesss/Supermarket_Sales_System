#pragma once
#include"CartProduct.cpp"
#include "../../Report/Report.cpp"
using namespace std;

class InvoiceBilling
{
private:
	CartProduct cartProduct;
	Report report;


	float subtotal;
public:
	InvoiceBilling():subtotal(0) {}
	~InvoiceBilling() {}

	void PrintInvoice(vector<CartProduct> storingProduct) 
	{
		unsigned int size = storingProduct.size();

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

		report.SaveSaleReport(storingProduct);


	}
	
};

