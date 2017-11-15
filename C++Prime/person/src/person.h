/*
 * person.h
 *
 *  Created on: 2015年2月10日
 *      Author: Scott
 */

#ifndef PERSON_H_
#define PERSON_H_
#include "string"
class person {
private:
	static const int limit = 25;
	std::string lname;
	char fname[limit];
public:
	person();
	person(const std::string & name1, const char *name2 = "Heyyou");
	void show() const;
	void FormalShow() const;
	virtual ~person();
};

#endif /* PERSON_H_ */
