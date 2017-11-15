//============================================================================
// Name        : 6_3.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;



int main()
{
	char ch;
	cout << "Please enter one of the following choices" << endl;
	cout << "c) carnivore         p) pianist" << endl;
	cout << "t) tree              g) game"<<endl;

	cin >> ch;
	while(cin.get()!='\n');

	while(!((ch == 'c') || (ch == 'p') || (ch == 't') || (ch == 'g')))
	{
		cout << "Please enter c, p, t, or g:" << endl;
		cin >> ch;
		while(cin.get()!='\n');
	}
	switch (ch)
	{
		case 'c':
			cout << "A tiger is a carnivore." << endl;
			break;
		case 'p':
			cout << "A pianist is a musician." << endl;
			break;
		case 't':
			cout << "A maple is a tree." << endl;
			break;
		case 'g':
			cout << "A sudoku is a game." << endl;
			break;
	}
	return 0;
}
