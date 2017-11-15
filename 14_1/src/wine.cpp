/*
 * wine.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: scott
 */

#include "wine.h"
#include <iostream>

Wine::Wine(const char * l, int y, const int yr[], const int bot[]): label(l), information(ArrayInt(yr, y), ArrayInt(bot, y))
{

}

Wine::Wine(const char * l, int y) : label(l), information(ArrayInt(y), ArrayInt(y))
{

}

std::string & Wine::Label()
{
	return label;
}

int Wine::sum()
{
	return information.second().sum();
}

void Wine::GetBottles()
{
	int number = information.first().size();

	std::cout << "Enter " << label << " data for " << number <<" year(s):" << std::endl;
	for (int i=0; i< number; i++)
	{
		std::cout << "Enter year:" ;
		std::cin >> information.first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> information.second()[i];
	}
}
void Wine::Show()
{
	std::cout << "Wine: " << label << std::endl;
	std::cout << "   " << "Year" << "    " << "Bottles" << std::endl;

	int N = information.first().size();
	for (int i=0; i<N; i++)
	{
		std::cout << "   " << information.first()[i] << "    " << information.second()[i] << std::endl;
	}

}
Wine::~Wine()
{
	// TODO Auto-generated destructor stub
}

