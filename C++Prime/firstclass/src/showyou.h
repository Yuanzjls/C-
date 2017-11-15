/*
 * showyou.h
 *
 *  Created on: 2015年2月10日
 *      Author: Scott
 */

#ifndef SHOWYOU_H_
#define SHOWYOU_H_

class showyou {
	int num;
	char name[20];
	public:
		showyou(int num_init, char* name_init);
		virtual ~showyou();
		char* showname();
		void setnum(int num);
		int getnum();
		void setname(char *name);
};

#endif /* SHOWYOU_H_ */
