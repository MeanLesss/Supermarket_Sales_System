#pragma once
#include<iostream>
using namespace std;

class AddedProduct
{
private:
	int id;
	int quantity;
public:
	AddedProduct() :id(0),quantity(0){}
	AddedProduct(int id, int quantity) :id(id), quantity(quantity) {}

};