//============================================================================
// Name        : 7_6.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int Fill_array(double [], int );
void Show_array(double [], int);
void Reverse_array(double [], int);
const int Max = 10;

int main() {
	double array[Max];
	int size;

	size = Fill_array(array, Max);
	Show_array(array, size);
	Reverse_array(array, size);
	Show_array(array, size);

	return 0;
}
int Fill_array(double arr[], int N)
{
	int i;

	for (i=0; i<N; i++)
	{
		cout << "Please enter a number:";
		if (cin >> arr[i])
	   {

	   }
	   else
	   {
		   break;
	   }
	}
	return i;
}
void Show_array(double array[], int N)
{
	cout << "The number you enter is:" << endl;
	for (int i=0; i<N; i++)
	{
		cout << "#" << i << " : " << array[i] << endl;
	}

}
void Reverse_array(double array[], int N)
{
	double temp;
	for (int i=0, j= N-1; i<j; i++, j--)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
