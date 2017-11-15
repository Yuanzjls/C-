/*
 * brass.h
 *
 *  Created on: Jul 15, 2017
 *      Author: scott
 */

#ifndef BRASS_H_
#define BRASS_H_

#include <string>
#include <iostream>
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat();
void restore(format f, precis p);

class Brass
{
private:
	std::string fullname;
	long acctNum;
	double balance;
public:
	Brass(const std::string & s = "Nullboday", long an = -1, double bal = 0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	double Balance() const;
	virtual ~Brass(){}
};

#endif /* BRASS_H_ */
