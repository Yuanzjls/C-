/*
 * person.cpp
 *
 *  Created on: 2015年2月10日
 *      Author: Scott
 */

#include "person.h"
#include "cstring"
#include "iostream"
using std::cout;
person::person() {
	// TODO Auto-generated constructor stub
	lname = "";
	fname[0] = 0;
}
person::person(const std::string & name1, const char *name2)
{
	lname = name1;
	strcpy(fname,name2);
}
person::~person() {
	// TODO Auto-generated destructor stub
}
void person::show() const
{
	cout << "last name is " << lname;
	cout << "first name is " << fname;
}
void person::FormalShow() const
{
	cout << "first name is " << fname;
	cout << "last name is " << lname;
}

