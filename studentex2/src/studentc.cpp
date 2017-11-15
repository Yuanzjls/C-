/*
 * studentc.cpp
 *
 *  Created on: Jul 18, 2017
 *      Author: scott
 */

#include "studentc.h"
#include <iostream>
using namespace std;
std::ostream & Student::arr_pit(std::ostream & os) const
{
	int i;
	int lim = ArrayDb::size();

	if (lim > 0)
	{
		for (i=0; i<lim; i++)
		{
			os << ((const ArrayDb &) *this)[i] << " ";
			if (i%5 == 4)
			{
				os << endl;
			}
		}
		if (i % 5 != 0)
		{
			os << endl;
		}
	}
	else
	{
		os << " empty array";
	}
	return os;

}

Student::Student() : string("Null Student"), ArrayDb()
{

}

Student::Student(const std::string & s) : string(s), ArrayDb()
{

}

Student::Student(int n): string("Nully"), ArrayDb(n)
{

}

Student::Student(const std::string &s, int n) : string(s), ArrayDb(n)
{

}

Student::Student(const std::string &s, const ArrayDb &a) :	string(s), ArrayDb(a)
{

}

Student::Student (const char * str, const double * pd, int n)	:	string(str), ArrayDb(pd, n)
{

}

Student::~Student()
{

}

double Student::Average() const
{
	if (ArrayDb::size() > 0)
	{
		return ArrayDb::sum()/ArrayDb::size();
	}
	else
	{
		return 0;
	}
}
const std::string & Student::Name() const
{
	return (const string &) *this;
}
//double & Student::operator[](int i)
//{
//	return ArrayDb::operator[](i);
//}
//double Student::operator[](int i) const
//{
//	return ArrayDb::operator[](i);
//}

std::istream & operator>>(std::istream & is, Student & stu)
{
	is >> (string &) stu;
	return is;
}

std::istream & getline(std::istream & is, Student & stu)
{
	getline(is, (string &)stu);
	return is;
}

std::ostream & operator<<(std::ostream &os, const Student & stu)
{
	os << "Scores for " << (const string &)stu << ":\n";
	stu.arr_pit(os);

	return os;
}
