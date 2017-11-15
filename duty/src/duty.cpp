//============================================================================
// Name        : duty.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
	const string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	const string month[12] = {"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December"};
	string name[11] = {"张秋璇","张家智", "思聪", "鲁沛", "郭敏","耿瑞双", "周元", "谢富豪", "晗星", "8号房", "3号房"};
	struct tm* timeinfo;
	time_t rawtime;


	int num[11];
	bool flag = 1;
	srand(time(0));

	for (int k=0; k<10; k++)
	{
		num[0] = rand()%11;
		cout << name[num[0]] << endl;
		for (int i=1; i<11; i++)
		{
			flag = 1;
			while(flag)
			{
				flag = 0;
				num[i] = rand()%11;

				for (int j=0; j<i; j++)
				{
					if (num[i] == num[j])
					{
						flag = 1;
						break;
					}
				}
			}
			cout << name[num[i]] << endl;
		}
	}
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	//mktime(timeinfo);

//	for (int i=0; i<11; i++)
//	{
//		cout << month[timeinfo->tm_mon]<<" " << timeinfo->tm_mday << " " << days[timeinfo->tm_wday]
//				 << " is number " << num[i] <<"'s duty."<< endl;
//		rawtime+=86400;
//		timeinfo = localtime(&rawtime);
//	}


	return 0;
}
