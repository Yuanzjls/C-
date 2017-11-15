/*
 * person.h
 *
 *  Created on: Jul 23, 2017
 *      Author: scott
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <cstdlib>
class Person
{
private:
	std::string fname;
	std::string lname;
public:
	Person(const std::string & ln="null", const std::string & fn="null");
	virtual void Show() const;
	virtual void Set();
	virtual ~Person()=0;
};

class Gunslinger: public virtual Person
{
private:
	double draw;
	int numbernotches;
protected:
	const double Draw() const{return draw;}
	double & Draw(){return draw;}
public:
	Gunslinger(const std::string & ln="null", const std::string & fn="null",
			double d=0, int n=0);
	Gunslinger(const Person &p, double d, int n);
	void Set();
	void Show() const;
};

class PokerPlayer: virtual public Person
{
protected:
	const int Draw() const {return std::rand() % 52 + 1;}
public:
	PokerPlayer(const std::string & ln="null", const std::string & fn="null");
	PokerPlayer(const Person &p);
	void Show() const;
	void Set();
};

class BadDude: public Gunslinger, public PokerPlayer
{
protected:
	double Gdraw(){return Gunslinger::Draw();}
	int Cdraw() const {return PokerPlayer::Draw();}
public:
	BadDude(const std::string & ln="null", const std::string & fn="null", double d=0, int n=0);
	BadDude(const Person &p, double d, int n);
	void Show() const;
	void Set();
};

#endif /* PERSON_H_ */
