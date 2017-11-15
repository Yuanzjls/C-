//============================================================================
// Name        : myvector.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"
#include <fstream>

using namespace std;

int main() {
	using namespace VECTOR;

	ofstream fout;
	fout.open("Walk_Space.txt");

	srand(time(0));
	double direction, target, dstep;
	Vector step, result(0, 0);
	unsigned long steps = 0;
	cout << "Enter target distance (q to quit): ";
	if (cin >> target)
	{
		cout << "Enter step length: ";

		if ((cin >> dstep))
		{
			fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;

			fout << steps << ": "<< result << endl;
			while(result.magval() < target)
			{

				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
				fout << steps << ": "<< result << endl;
			}
			cout << "After " << steps << " steps, the subject " << "has the following location:\n";
			fout << "After " << steps << " steps, the subject " << "has the following location:\n";
			cout << result << endl;
			fout << result << endl;

			result.polar_mode();
			cout << " or\n" << result << endl;
			fout << " or\n" << result << endl;
			cout << "Average outward distance per step = " << result.magval()/steps << endl;
			fout << "Average outward distance per step = " << result.magval()/steps << endl;
		}
	}
	fout.close();
	cout << "Bye!\n";
	cin.clear();
	while(cin.get() != '\n')
	{
		continue;
	}
	return 0;
}
