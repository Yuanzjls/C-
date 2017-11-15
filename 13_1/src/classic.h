/*
 * classic.h
 *
 *  Created on: Jul 17, 2017
 *      Author: scott
 */

#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char * s1 = "Null", const char * s2 = "Null", int n = 0, double x = 0);
	Cd(const Cd & d);
	virtual ~Cd();
	virtual void Report() const;
	Cd & operator=(const Cd & d);
};


class Classic : public Cd
{
private:
	char identity[50];
public:
	Classic(const char * s0 = "Null", const char * s1 = "Null", const char * s2 = "Null", int n = 0, double x = 0);
	Classic(const char * s0 , const Cd & d);
	Classic & operator=(const Classic &cla);
	virtual void Report() const;
	virtual ~Classic();
};

#endif /* CLASSIC_H_ */
