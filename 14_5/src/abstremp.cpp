/*
 * abstremp.cpp
 *
 *  Created on: Jul 23, 2017
 *      Author: scott
 */

#include "abstremp.h"
using namespace std;

abstr_emp::abstr_emp()
{
	fname = "none";
	lname = "none";
	job = "none";
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,
			const std::string & j)
{
	fname = fn;
	lname = ln;
	job = j;
}

void abstr_emp::ShowAll() const
{
	cout << "The employee's first name is " << fname <<endl;
	cout << "The employee's last  name is " << lname <<endl;
	cout << "The employee's job is " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter employee's first name: ";
	cin >> fname;
	cout << "Enter employee's last name: ";
	cin >> lname;
	cout << "Enter employee's job: ";
	cin >> job;
}

std::ostream & operator<<(std::ostream &os, const abstr_emp & e)
{
	os << "The employee's first name is " << e.fname <<endl;
	os << "The employee's last  name is " << e.lname <<endl;
	os << "The employee's job is " << e.job << endl;
	return os;
}

abstr_emp::~abstr_emp()
{

}

employee::employee():abstr_emp()
{

}

employee::employee(const std::string & fn, const std::string & ln,
		const std::string &j): abstr_emp(fn, ln, j)
{

}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager():abstr_emp()
{
	inchargeof = 0;
}

manager::manager(const std::string & fn, const std::string & ln,
		const std::string & j, int ico): abstr_emp(fn, ln, j)
{
	inchargeof = ico;
}

manager::manager(const abstr_emp & e, int ico): abstr_emp(e)
{
	inchargeof = ico;
}

manager::manager(const manager & m): abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "The manager has " << inchargeof << " employees" << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter how many employees manage: ";
	cin >> inchargeof;
}

fink::fink(): abstr_emp()
{
	reportsto = "none";
}

fink::fink(const std::string & fn, const std::string & ln,
		const std::string &j, const std::string & rpo):abstr_emp(fn, ln, j)
{
	reportsto = rpo;
}

fink::fink(const abstr_emp &e, const std::string & rpo):abstr_emp(e)
{
	reportsto = rpo;
}

fink::fink(const fink &e):abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Have to report to " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the person whom fink have to report: ";
	cin >> reportsto;
}

highfink::highfink():abstr_emp(), manager(), fink()
{

}

highfink::highfink(const std::string & fn, const std::string & ln,
			const std::string & j, const std::string & rpo,
			int ico):abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{

}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico):abstr_emp(e), manager(e, ico), fink(e, rpo)
{

}

highfink::highfink(const fink & f, int ico):abstr_emp(f), manager((const abstr_emp &)f, ico), fink(f)
{

}

highfink::highfink(const manager & m, const std::string & rpo):abstr_emp(m), manager(m), fink((const abstr_emp &)m, rpo)
{

}

highfink::highfink(const highfink & h):abstr_emp(h), manager((const manager &)h), fink((const fink &)h)
{

}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "The manager has " << manager::InChargeOf() << " employees" << endl;
	cout << "Have to report to " << fink::ReportsTo() << endl;
	cout << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter how many employees manage: ";
	cin >> manager::InChargeOf();
	cout << "Enter the person whom fink have to report: ";
	cin >> fink::ReportsTo();
}
