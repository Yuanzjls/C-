//============================================================================
// Name        : ruler.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
const int len = 65;
const int divs = 6;
void subdivide(char ar[], int low, int high, int level);
int main() {
	char ruler[len];
	int i;
	for (i=0; i<len; i++)
	{
		ruler[i] = ' ';
	}
	ruler[len-1] = 0;
	int max = len - 1;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	cout << ruler << endl;
	for (i=1; i<divs; i++)
	{
		subdivide(ruler, min, max, i);
		cout << ruler << endl;
		for (int j =1; j<len-1; j++)
		{
			ruler[j] = ' ';
		}
	}
	return 0;
}
void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)
	{
		return ;
	}
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level-1);
	subdivide(ar, mid, high, level-1);
}
