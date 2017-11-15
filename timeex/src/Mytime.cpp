/*
 * Mytime.cpp
 *
 *  Created on: Jul 8, 2017
 *      Author: scott
 */

#include "Mytime.h"
#include <iostream>
time::time() {
	// TODO Auto-generated constructor stub
	hours = minutes = 0;
}

time::time(int h, int m)
{
	hours = h;
	minutes = m;
}

void time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void time::AddHr(int h)
{
	hours += h;
}

void time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

time time::operator+(const time & t) const
{
	time sum;

	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes  %= 60;
	return sum;
}

void time::Show() const
{
	std::cout << hours << " hours, " << minutes << " minutes";
}

time time::operator-(const time & t) const
{
	time diff;

	int tot1, tot2, tmp;

	tot1 = minutes + hours * 60;
	tot2 = t.minutes + t.hours * 60;
	tmp = tot1 - tot2;
	diff.hours = tmp / 60;
	diff.minutes = tmp % 60;
	return diff;
}

time time::operator*(const double mult) const
{
	time result;
	int totalminutes = (minutes + hours * 60)*mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;

}
std::ostream & operator<<(std::ostream &os, const time &t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
time::~time() {
	// TODO Auto-generated destructor stub
}

