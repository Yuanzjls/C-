/*
 * worker.h
 *
 *  Created on: Jul 19, 2017
 *      Author: scott
 */

#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker {
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker();
	Worker(const std::string & s, long n);
	virtual ~Worker() = 0;
	virtual void Set()=0;
	virtual void Show() const =0;
};

class Waiter: virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter();
	Waiter(const std::string & s, long n, int p=0);
	Waiter(const Worker & wk, int p = 0);
	void Set();
	void Show() const;
};

class Singer: virtual public Worker
{
protected:
	enum{other, alto, contralto, soprano,
		bass, baritone, tenor};
	enum{Vtypes = 7};
	void Data() const;
	void Get();
private:
	static const char *pv[Vtypes];
	int voice;
public:
	Singer();
	Singer(const std::string &s, long n, int v = other);
	Singer(const Worker & wk, int v = other);
	void Set();
	void Show() const;
};

class SingingWaiter :  public Waiter, public Singer
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter();
	SingingWaiter(const std::string & s, long n, int p=0, int v = other);
	SingingWaiter(const Worker & wk, int p , int v=other);
	SingingWaiter(const Waiter & wt, int v=other);
	SingingWaiter(const Singer & wt, int p=0);
	void Set();
	void Show() const;
};

#endif /* WORKER_H_ */
