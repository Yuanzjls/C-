/*
 * stack.cpp
 *
 *  Created on: Jul 8, 2017
 *      Author: scott
 */

#include "stack.h"

Stack::Stack()
{
	// TODO Auto-generated constructor stub
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == Max;
}

bool Stack::push(const Item &item)
{
	if (top < Max)
	{
		items[top] = item;
		top++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		top--;
		item = items[top];
		return true;
	}
	else
	{
		return false;
	}
}

Stack::~Stack()
{
	// TODO Auto-generated destructor stub

}

