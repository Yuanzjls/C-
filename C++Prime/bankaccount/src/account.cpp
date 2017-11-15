/*
 * account.cpp
 *
 *  Created on: 2015年2月10日
 *      Author: Scott
 */

#include "account.h"
#include "iostream"
using std::cout;
using std::endl;
account::account(string name, string ID, unsigned long int num) {
	// TODO Auto-generated constructor stub
	account::name = name;
	account::ID = ID;
	account::num = num;
}

account::~account() {
	// TODO Auto-generated destructor stub
}
void account::show()
{
	cout << "This account name is " << name << endl;
	cout << "The ID is " << ID << endl;
	cout << "The account has " << num << endl;
}
void account::save(unsigned long int num)
{
	account::num += num;
}
void account::out(unsigned long int num)
{
	if (account::num < num)
	{
		cout << "you don't have enough money" << endl;
	}
	else
	{
		account::num -= num;
	}
}
