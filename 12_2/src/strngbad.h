// strngbad.h -- flawed string class definition
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class String
{
private:
	char * str; // pointer to string
	int len; // length of string
	static int num_strings; // number of objects
	static const int CINLIM = 80;
public:

	String(const char * s); // constructor
	String(); // default constructor
	String(const String & s);
	~String(); // destructor
	int length() const {return len;}

	String & operator=(const String & s);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
	// friend function
	friend std::ostream & operator<<(std::ostream & os, const String & st);
	friend std::istream & operator>>(std::istream & is, String & st);
	friend bool operator<(const String &st1, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st1, const String &st2);
	String operator+(const String &s) const;
	String operator+(const char * s) const;
	friend String operator+(const char *st, const String &s);
	void stringup(void);
	void stringlow(void);
	int has(char ch) const;
	static int HowMany();
};
#endif
