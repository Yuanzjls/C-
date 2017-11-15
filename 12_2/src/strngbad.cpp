// strngbad.cpp -- StringBad class methods
#include <cstring> // string.h for some
#include "strngbad.h"
using namespace std;
// initializing static class member
int String::num_strings = 0;
// class methods
// construct StringBad from C string

int String::HowMany()
{
	return num_strings;
}

String::String(const char * s)
{
	len = std::strlen(s); // set size
	str = new char[len + 1]; // allot storage
	std::strcpy(str, s); // initialize pointer
	num_strings++; // set object count
}

String::String() // default constructor
{
	len = 0;
	str = nullptr;
	//str[0] = '\0';
	num_strings++;

}

String::String(const String & s)
{
	num_strings++;
	len = s.len;
	str = new char [len + 1];
	std::strcpy(str, s.str);
}

String::~String() // necessary destructor
{
	--num_strings; // required
	delete [] str; // required
}

String & String::operator=(const String & s)
{
	if (this == &s)
	{
		return *this;
	}
	else
	{
		delete [] str;
		len = s.len;
		str = new char [len + 1];
		std::strcpy(str, s.str);
		return *this;
	}
}

String & String::operator=(const char * s)
{
	delete [] str;

	len = std::strlen(s);
	str = new char [len + 1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return st2 < st2;
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << st.str;
	return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
	char temp[String::CINLIM];

	is.get(temp, String::CINLIM);
	if(is)
	{
		st = temp;
	}
	while(is && is.get() != '\n');

	return is;
}

String String::operator+(const String &s) const
{
	String temp;

	delete temp.str;
	temp.len = this->len + s.len;
	temp.str = new char [temp.len + 1];
	std::strcpy(temp.str, this->str);
	std::strcat(temp.str, s.str);

	return temp;
}

void String::stringup(void)
{
	for (int i=0; i < len; i++)
	{
		str[i] = std::toupper(str[i]);
	}
}
void String::stringlow(void)
{
	for (int i=0; i < len; i++)
	{
		str[i] = std::tolower(str[i]);
	}
}
int String::has(char ch) const
{
	int num = 0;

	for (int i=0; i<len; i++)
	{
		if (str[i] == ch)
		{
			num++;
		}
	}
	return num;
}

String String::operator+(const char * s) const
{
	String temp;

	delete temp.str;

	temp.len = len + std::strlen(s);
	temp.str = new char [temp.len + 1];
	strcpy(temp.str, str);
	strcat(temp.str, s);
	return temp;
}
String operator+(const char *st, const String &s)
{
	String temp;

	delete temp.str;

	temp.len = s.len + strlen(st);
	temp.str = new char [temp.len + 1];
	strcpy(temp.str, st);
	strcat(temp.str, s.str);
	return temp;
}
