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
public:
	Worker();
	Worker(const std::string & s, long n);
	virtual ~Worker() = 0;
	virtual void Set();
	virtual void Show() const;
};

class Waiter: public Worker
{
private:
	int panache;
public:
	Waiter();
	Waiter(const std::string & s, long n, int p=0);
	Waiter(const Worker & wk, int p = 0);
	void Set();
	void Show() const;
};

class Singer: public Worker
{
protected:
	enum{other, alto, contralto, soprano,
		bass, baritone, tenor};
	enum{Vtypes = 7};
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

#endif /* WORKER_H_ */
