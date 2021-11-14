#pragma once
#include"CartProduct.cpp"
#include"Product.cpp"
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
			storingProduct[i].DisplayProductInCart();
			subtotal += storingProduct[i].getTotal();
		}
		cout << "===========================================================================================================" << endl;
		cout << "|| Sub Total ____________________________________________________________________________________$" << subtotal << endl;
		cout << "===========================================================================================================" << endl;
		cout << "                                               --See you again soon--" << endl;

		//don't forget to delete vector after print the invoice
		//storingProduct.clear();


	}
	void UpdateStock(vector<CartProduct> storingProduct)
	{
		Product product;
		ifstream fin;
		ofstream fout;

		int i = 0;
		int stock;
		cout << "got in" << endl;

		fin.open(PRODUCT_FILE, ios::in | ios::binary);
		if (!fin)
		{
			cerr << "File open failed";
			exit(1);
		}
		fout.open("temp.dat", ios::out | ios::app | ios::binary);
		fin.seekg(0, ios::beg);
		i = 0;
		while (fin.read(reinterpret_cast<char*>(&product), sizeof(Product))) 
		{
			cout << "got in2" << endl;

			if (fin.eof()) { break; }
			if (product.getProductName() != storingProduct[i].getName())
			{
				fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
			}
			else
			{
				cout << "got in3" << endl;

				stock = product.getQuantity() - storingProduct[i].getQuantity();
				product.setQuantity(stock);
				fout.write(reinterpret_cast<char*>(&product), sizeof(Product));
			}
			i++;
		}
		fin.close();
		fout.close();
		int removeStatus = 0;
		//removeStatus = remove(PRODUCT_FILE);
		if (remove("product.dat") == 0)
		{
			//cout << "Failed to remove!" << endl;
			cout << "success remove" << endl;
		}
		else
		{
			cout << "fail to remove" << endl;
		}
		//remove(USER_FILE);
		int renameStatus;
		renameStatus = rename("temp.dat", "product.dat");
		if (renameStatus == 0)
		{
			cout << "Item renamed!" << endl;
		}
		else
		{
			cout << "Failed to rename" << endl;
		}
	}
};

