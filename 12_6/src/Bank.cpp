//============================================================================
// Name        : Bank.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

using namespace std;

int main() {
	srand(time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line1(qs/2), line2(qs/2);


	cout << "Enter the number of simulation hours:";
	int hours;
	cin >> hours;

	long cyclelimit = MIN_PER_HR * hours;

	cout << "Enter the average number of customer per hour: ";
	double perhour;

	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time1 = 0, wait_time2 = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line1.isfull() && line2.isfull())
			{
				turnaways++;
			}
			else
			{
				customers++;
				temp.set(cycle);
				if (line1.queuecount() <= line2.queuecount())
				{
					line1.enqueue(temp);
				}
				else
				{
					line2.enqueue(temp);
				}
			}
		}
		if (wait_time1 <= 0 && (!line1.isempty()))
		{
			line1.dequeue(temp);
			wait_time1 = temp.ptime();
			line_wait += (cycle - temp.when());
			served++;
		}
		if (wait_time1 > 0)
		{
			wait_time1--;
		}
		if (wait_time2 <=0 && (!line2.isempty()))
		{
			line2.dequeue(temp);
			wait_time2=temp.ptime();
			line_wait += (cycle-temp.when());
			served++;
		}
		if (wait_time2 > 0)
		{
			wait_time2--;
		}
		sum_line += line1.queuecount()+line2.queuecount();
	}

	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size:";
		cout.precision(2);
		cout.setf(ios::fixed, ios::floatfield);
		cout << (double) sum_line / cyclelimit << endl;
		cout << " average wait time: " << (double) line_wait / served << " minutes\n";
	}
	else
	{
		cout << "No customers!\n";
	}
	cout << "Done!\n";

	return 0;
}

bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}
