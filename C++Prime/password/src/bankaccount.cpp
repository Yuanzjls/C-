//============================================================================
// Name        : bankaccount.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//using namespace std;

int main() {

	srand(time(0));


	for (int i=0; i<10;i++)
	{
	    switch(rand()%3)
		{
			case 0: //属于数字
				printf("%d", rand()%10);
			break;
			case 1: //属于小写字母
				printf("%c", (rand()%26)+'a');
			break;
			case 2://属于大写字母
				printf("%c", (rand()%26)+'A');
			break;


		}
	}
}
