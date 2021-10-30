#include<iostream>
#include"Service.cpp"
#include"ServiceApp.cpp"
#include"Menu.cpp"

using namespace std;
int main()
{
	system("cls");
	cout << "\t\t\t\t\t\tWelcome to Mean supermarket" << endl;
	//Menu menu;
	Product product;
	Service service;
	ServiceApp serviceapp;
	//service.LogIn();
	serviceapp.MenuProcess();
	
	//product.CreateProduct();
	//product.DisplayProduct();
	//service.LoadFromManager();
	//service.SignUp(manager);

	system("pause");

}