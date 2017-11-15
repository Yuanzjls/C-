//============================================================================
// Name        : 17_7.cpp
// Author      : Yuan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
void ShowStr(const string &s);
class Store
{
private:
	ostream & os;
public:
	Store(ostream & o) : os(o){}
	void operator()(const string &s)
	{
		size_t len = s.size();

		os.write((char *)&len, sizeof(size_t));
		os.write(s.data(), len);
	}
};
void GetStrs(ifstream & fin, vector<string>&vstr);
int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;
	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin,temp) && temp[0] != '\0')
	{
		vostr.push_back(temp);
	}
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	return 0;
}
void ShowStr(const string &s)
{
	cout << s << endl;
}
void GetStrs(ifstream & fin, vector<string>&vstr)
{
	size_t len;
	char *str_temp;
	while(fin.read((char *)&len, sizeof(size_t)))
	{
		str_temp = new char [len+1];
		fin.read(str_temp, len);
		str_temp[len] = 0;
		vstr.push_back(string(str_temp));
		delete [] str_temp;
	}
}
