/*
 * namesp.h
 *
 *  Created on: Jul 7, 2017
 *      Author: scott
 */

#ifndef NAMESP_H_
#define NAMESP_H_

#include <string>

namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void getPerson(Person &);
	void showPerson(const Person &);

}

namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount;
	};
	void getDebt(Debt &);
	void showDebt(const Debt &);
	double sumDebts(const Debt ar[], int n);
}

#endif /* NAMESP_H_ */
