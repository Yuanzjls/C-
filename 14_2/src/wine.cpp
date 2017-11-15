/*
 * wine.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: scott
 */

#include "wine.h"
#include <iostream>
using namespace std;

Wine::Wine(const char * l, int y, const int yr[], const int bot[]): string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{

}

Wine::Wine(const char * l, int y) : string(l), PairArray(ArrayInt(y), ArrayInt(y))
{

}

std::string & Wine::Label()
{
	return (string &)*this;
}

int Wine::sum()
{
	return PairArray::second().sum();
}

void Wine::GetBottles()
{
	int number = Pair::first().size();

	std::cout << "Enter " << Label() << " data for " << number <<" year(s):" << std::endl;
	for (int i=0; i< number; i++)
	{
		std::cout << "Enter year:" ;
		std::cin >> PairArray::first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> PairArray::second()[i];
	}
}
void Wine::Show()
{
	std::cout << "Wine: " << Label() << std::endl;
	std::cout << "   " << "Year" << "    " << "Bottles" << std::endl;

	int N = PairArray::first().size();
	for (int i=0; i<N; i++)
	{
		std::cout << "   " << PairArray::first()[i] << "    " << PairArray::second()[i] << std::endl;
	}

}
Wine::~Wine()
{
	// TODO Auto-generated destructor stub
}

