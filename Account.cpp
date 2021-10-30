#pragma once
#include<iostream>
#include<string>
using namespace std;

class Account 
{
private:
	string Name;
	string PassWord;
public:
	Account():Name("unknown"),PassWord("unknown") { }
	Account(string name, string pass) :Name(name), PassWord(pass) { }
	
	virtual void GetName() = 0;
};