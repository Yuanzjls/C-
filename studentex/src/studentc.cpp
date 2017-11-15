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
	int lim = scores.size();

	if (lim > 0)
	{
		for (i=0; i<lim; i++)
		{
			os << scores[i] << " ";
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

Student::Student() : name("Null Student"), scores()
{

}

Student::Student(const std::string & s) : name(s), scores()
{

}

Student::Student(int n): name("Nully"), scores(n)
{

}

Student::Student(const std::string &s, int n) : name(s), scores(n)
{

}

Student::Student(const std::string &s, const ArrayDb &a) :	name(s), scores(a)
{

}

Student::Student (const char * str, const double * pd, int n)	:	name(str), scores(pd, n)
{

}

Student::~Student()
{

}

double Student::Average() const
{
	if (scores.size() > 0)
	{
		return scores.sum()/scores.size();
	}
	else
	{
		return 0;
	}
}
const std::string & Student::Name() const
{
	return name;
}
double & Student::operator[](int i)
{
	return scores[i];
}
double Student::operator[](int i) const
{
	return scores[i];
}

std::istream & operator>>(std::istream & is, Student & stu)
{
	is >> stu.name;
	return is;
}

std::istream & getline(std::istream & is, Student & stu)
{
	getline(is, stu.name);
	return is;
}

std::ostream & operator<<(std::ostream &os, const Student & stu)
{
	os << "Scores for " << stu.name << ":\n";
	stu.arr_pit(os);

	return os;
}
