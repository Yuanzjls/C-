/*
 * main.cpp
 *
 *  Created on: Jul 29, 2017
 *      Author: scott
 */
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	srand(time(0));
	const int size = 10000000;
	vector<int> vi0(size), vi(size);
	list<int> li(size);
	clock_t start, end;
	for (int i=0; i<size; i++)
	{
		vi0[i] = rand();
	}
	vi = vi0;
	cout << "The time that using vector sort is ";
	start = clock();
	sort(vi.begin(), vi.end());
	end = clock();
	cout << (double)(end - start)/CLOCKS_PER_SEC;

	copy(vi0.begin(), vi0.end(), li.begin());
	start = clock();
	li.sort();
	end = clock();
	//copy(li.begin(), li.end(), vi0.begin());
	cout << "\nThe time that using list sort is " << (double)(end - start)/CLOCKS_PER_SEC;

	copy(vi0.begin(),vi0.end(), li.begin());
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << "\nThe time that using copy vector sort and copy is " << (double)(end - start)/CLOCKS_PER_SEC;

	return 0;
}

