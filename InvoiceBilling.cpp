#pragma once
#include"CartProduct.cpp"
#include"Product.cpp"
#include"application.cpp"
using namespace std;

class InvoiceBilling
{
private:
	CartProduct cartProduct;



	float subtotal;
public:
	InvoiceBilling() {}
	~InvoiceBilling() {}

	void PrintInvoice(vector<CartProduct> storingProduct) 
	{
		unsigned int size = storingProduct.size();

		cout << "===========================================================================================================" << endl;
		cout << "......................................................INVOICE.............................................." << endl;
		cout << "===========================================================================================================" << endl;
		for (unsigned int i = 0; i < size; i++)
		{
			storingProduct[i].DisplayInCart();
			subtotal += storingProduct[i].getTotal();
		}
		cout << "===========================================================================================================" << endl;
		cout << "|| Sub Total ____________________________________________________________________________________$" << subtotal << endl;
		cout << "===========================================================================================================" << endl;
		cout << "                                               --See you again soon--" << endl;


		//don't forget to delete vector after print the invoice
		//storingProduct.clear();
	}
};

