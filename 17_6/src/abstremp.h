/*
 * abstremp.h
 *
 *  Created on: Jul 23, 2017
 *      Author: scott
 */

#ifndef ABSTREMP_H_
#define ABSTREMP_H_

#include <iostream>
#include <string>

class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string & fn, const std::string & ln,
			const std::string & j);
	virtual void ShowAll() const;
	virtual void SetAll();
	friend std:: ostream & operator<<(std::ostream &os, const abstr_emp & e);
	virtual ~abstr_emp() = 0;
	virtual void Readall(std::istream & is);
	virtual void Writeall(std::ostream & os);
};

class employee:public abstr_emp
{
public:
	employee();
	employee(const std::string & fn, const std::string & ln,
			const std::string &j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void Readall(std::istream & is);
	virtual void Writeall(std::ostream & os);
};

class manager: virtual public employee
{
private:
	int inchargeof;
protected:
	int InChargeOf() const {return inchargeof;}
	int & InChargeOf() {return inchargeof;}
public:
	manager();
	manager(const std::string & fn, const std::string & ln,
			const std::string & j, int ico = 0);
	manager(const employee & e, int ico);
	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void Readall(std::istream & is);
	virtual void Writeall(std::ostream & os);
};

class fink : virtual public employee
{
private:
	std::string reportsto;
protected:
	const std::string ReportsTo() const {return reportsto;}
	std::string & ReportsTo(){return reportsto;}
public:
	fink();
	fink(const std::string & fn, const std::string & ln,
			const std::string &j, const std::string & rpo);
	fink(const employee &e, const std::string & rpo);
	fink(const fink &e);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void Readall(std::istream & is);
	virtual void Writeall(std::ostream & os);
};

class highfink: public manager, public fink
{
public:
	highfink();
	highfink(const std::string & fn, const std::string & ln,
			const std::string & j, const std::string & rpo,
			int ico);
	highfink(const employee & e, const std::string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const std::string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void Readall(std::istream & is);
	virtual void Writeall(std::ostream & os);
};


#endif /* ABSTREMP_H_ */
