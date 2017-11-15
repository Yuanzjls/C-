/*
 * queuetp.h
 *
 *  Created on: Jul 22, 2017
 *      Author: scott
 */

#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class T>
class QueueTP
{
private:
	enum{Q_SIZE = 10};
	struct Node
	{
		T item;
		Node * next;
	};
	Node * front;
	Node * rear;
	int items;
	const int qs_size;
public:
	QueueTP(int qs = Q_SIZE):qs_size(qs){items = 0; rear = 0; front = 0; items = 0;}
	~QueueTP()
	{
		Node *temp;
		while(front!= NULL)
		{
			temp = front;
			delete front;
			front = temp->next;
		}
	}
	bool isempty()
	{
		return items == 0;
	}
	bool isfull()
	{
		return items == qs_size;
	}
	int queuecount()
	{
		return items;
	}
	bool enqueue(const T & item)
	{
		if (isfull())
		{
			return false;
		}
		else if (front == NULL)
		{
			front = new Node;
			front->item = item;
			front->next = NULL;
			rear = front;
		}
		else
		{
			Node * temp;
			temp = new Node;
			temp->item = item;
			temp->next = NULL;
			rear->next = temp;
			rear = temp;
		}
		items++;
		return true;
	}

	bool dequeue(T & item)
	{
		if (isempty())
		{
			return false;
		}
		else
		{
			Node * temp;

			item = front->item;
			temp = front->next;
			delete front;
			front = temp;
		}
		items--;
		return true;

	}

};



#endif /* QUEUETP_H_ */
