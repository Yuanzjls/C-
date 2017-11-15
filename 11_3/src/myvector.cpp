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

unsigned long Max_Steps(unsigned long *pstep, unsigned int N);
unsigned long Min_Steps(unsigned long pstep[], unsigned int N );
double Average_Steps(unsigned long pstep[], unsigned N);

int main() {
	using namespace VECTOR;

	ofstream fout;
	fout.open("Walk_Space.txt");

	srand(time(0));
	double direction, target, dstep;
	Vector step, result(0, 0);
	unsigned int i = 0;
	unsigned long steps = 0, N, *pstep;
	cout << "Enter the loop times:";
	if (cin >> N)
	{
			cout << "Enter target distance: ";
			pstep = new unsigned long [N];
			if (cin >> target)
			{
				cout << "Enter step length: ";

				if ((cin >> dstep))
				{
					for (i=0; i<N; i++)
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
						pstep[i] = steps;
						cout << "After " << steps << " steps, the subject " << "has the following location:\n";
						fout << "After " << steps << " steps, the subject " << "has the following location:\n";
						cout << result << endl;
						fout << result << endl;

						result.polar_mode();
						cout << " or\n" << result << endl;
						fout << " or\n" << result << endl;
						cout << "Average outward distance per step = " << result.magval()/steps << endl;
						fout << "Average outward distance per step = " << result.magval()/steps << endl;
						result.reset(0, 0);
						steps = 0;
					}
					cout << "The highest step is " << Max_Steps(pstep, N) << endl;
					cout << "The lowest step is " << Min_Steps(pstep, N) << endl;
					cout << "The average step is " << Average_Steps(pstep, N) << endl;
				}
			}
	}
	fout.close();
	cout << "Bye!\n";
	cin.clear();
	while(cin.get() != '\n')
	{
		continue;
	}
	delete [] pstep ;
	return 0;
}
unsigned long Max_Steps(unsigned long *pstep, unsigned int N)
{
	unsigned int i;
	unsigned long Max = pstep[0];

	for (i=1; i<N; i++)
	{
		if (pstep[i] > Max)
		{
			Max = pstep[i];
		}
	}
	return Max;

}
unsigned long Min_Steps(unsigned long pstep[], unsigned int N)
{
	unsigned int i;
	unsigned long Min = pstep[0];

	for (i=1; i<N; i++)
	{
		if (Min > pstep[i])
		{
			Min = pstep[i];
		}
	}
	return Min;
}
double Average_Steps(unsigned long pstep[], unsigned N)
{
	unsigned int i;
	unsigned long Sum = 0;

	for (i=0; i<N; i++)
	{
		Sum += pstep[i];
	}
	return double(Sum) / N;
}
