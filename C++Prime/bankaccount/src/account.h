/*
 * account.h
 *
 *  Created on: 2015年2月10日
 *      Author: Scott
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
using std::string;
class account {
string name;
string ID;
unsigned long int  num;
public:
	account(string, string ,unsigned long int);
	virtual ~account();
	void show();
	void save(unsigned long int);
	void out(unsigned long int);
};

#endif /* ACCOUNT_H_ */
