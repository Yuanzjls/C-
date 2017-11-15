//============================================================================
// Name        : 8_2.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

struct CandyBar
{
	char * Brand;
	double weight;
	int Calories;
};

void CandyBarSet(CandyBar & cb, char * Branch = "Millennium Munch", double Weight = 2.85, int Calories = 350);
void CandyBarShow(const CandyBar);

int main()
{
	CandyBar cb;

	cout << "The original one is ";
	CandyBarSet(cb);
	CandyBarShow(cb);
	cout << "The new one is ";
	CandyBarSet(cb, "Munch", 4.35, 650);
	CandyBarShow(cb);

	return 0;
}
void CandyBarSet(CandyBar & cb, char * Branch, double Weight, int Calories)
{
	cb.Brand = Branch;
	cb.weight = Weight;
	cb.Calories = Calories;
}
void CandyBarShow(const CandyBar cb)
{
	cout << "The brand is " << cb.Brand << endl;
	cout << "The weight is " << cb.weight << endl;
	cout << "The calories is " << cb.Calories << endl;
}
