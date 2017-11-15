//============================================================================
// Name        : 13_4.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "port.h"
using namespace std;

int main()
{
	Port p1;
	Port p2("Tsingtao", "Beer", 30);
	std::cout << p1 << std::endl << endl;
	std::cout << p2 << std::endl << endl;
	Port p3 = p2;
	p3.Show();
	cout << endl;
	p3 += 3;
	p3.Show();
	cout << endl;

	VintagePort vp1("Harbin", 50, "hb", 1992);
	vp1.Show();
	cout << endl;
	VintagePort vp2;
	vp2.Show();
	cout << endl;
	vp1 -= 3;
	vp2 = vp1;
	vp2.Show();
	cout << endl;
}
