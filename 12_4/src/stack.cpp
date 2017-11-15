/*
 * stack.cpp
 *
 *  Created on: Jul 8, 2017
 *      Author: scott
 */

#include "stack.h"
#include <cstring>

using std::memcpy;
Stack::Stack(int n)
{
	top = 0;
	size = n;
	pitems = new Item[size];
}

Stack::Stack(const Stack & st)
{
	//delete [] pitems;

	size = st.size;
	pitems = new Item[size];
	top = st.top;
//	for (int i=0; i<top; i++)
//	{
//		pitems[i] = st.pitems[i];
//	}
	memcpy(pitems, st.pitems, sizeof(Item)*size);
}

Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == size;
}

bool Stack::push(const Item &item)
{
	if (top < size)
	{
		pitems[top] = item;
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
		item = pitems[top];
		return true;
	}
	else
	{
		return false;
	}
}

Stack & Stack::operator=(const Stack & st)
{
	delete [] pitems;

	size = st.size;
	top = st.top;
	pitems = new Item [size];

//	for (int i=0; i<top; i++)
//	{
//		pitems[i] = st.pitems[i];
//	}
	memcpy(pitems, st.pitems, sizeof(Item)*size);

	return *this;
}


