//============================================================================
// Name        : stockxx.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stock.h"
using namespace std;

const int STKS = 4;

int main()
{
	Stock stocks[STKS] = {
			Stock("NanoSmart", 12, 20),
			Stock("Boffo Objects", 200, 2),
			Stock("Monolithic Obelisks", 130, 3.25),
			Stock("Fleep Enterprises", 60, 6.5)
	};


	cout << "Stock holding:\n";

	for (int i=0; i<STKS; i++)
	{
		stocks[i].show();
	}
	const Stock * top = &stocks[0];

	for (int i=0; i<STKS; i++)
	{
		top = &top->topval(stocks[i]);
	}
	cout << "\nMost valuable holding:\n";
	top->show();
	return 0;
}
