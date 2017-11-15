/*
 * showyou.cpp
 *
 *  Created on: 2015年2月10日
 *      Author: Scott
 */

#include "showyou.h"
#include "string.h"
#include "iostream"
using namespace std;
showyou::showyou(int num_init, char* name_init) {
	// TODO Auto-generated constructor stub
	num = num_init;
	strcpy(name, name_init);
}

showyou::~showyou() {
	// TODO Auto-generated destructor stub
}
char* showyou::showname()
{
	return name;
}
void showyou::setnum(int num)
{
	showyou::num = num;
}
int showyou::getnum()
{
	cout << num;
}
void showyou::setname(char *name)
{
	strcpy(showyou::name,name);
}
