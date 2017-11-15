/*
 * queuetp.h
 *
 *  Created on: Jul 24, 2017
 *      Author: scott
 */

#ifndef QUEUETP_H_
#define QUEUETP_H_
template <class Item>
class QueueTP
{
private:
	enum {Q_SIZE = 10};
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(const Item & i): item(i), next(0){}
	};
	Node *front;
	Node *rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP & q) :qsize(0) {}
	QueueTP & operator=(const QueueTP & q){return *this;}
public:
	QueueTP(int qs = Q_SIZE):qsize(qs)
	{
		front = rear = 0;
		items = 0;
	}

	~QueueTP()
	{
		Node * temp;
		while(front != NULL)
		{
			temp = front->next;
			delete front;
			front = temp;
		}
	}

	bool isempty() const
	{
		return items == 0;
	}

	bool isfull() const
	{
		return items == qsize;
	}

	int queuecount() const
	{
		return items;
	}

	bool enqueue(const Item & item)
	{
		if (isfull())
		{
			return false;
		}
		else if (front == NULL)
		{
			front = new Node(item);
			rear = front;
		}
		else
		{
			Node *add = new Node(item);
			rear->next = add;
			rear = add;
		}
		items++;
		return true;
	}

	bool dequeue(Item & item)
	{
		if (isempty())
		{
			return false;
		}
		else
		{
			Node * temp;
			temp = front->next;
			item = front->item;
			delete front;
			front = temp;
			items--;
			return true;
		}
	}
};

#endif /* QUEUETP_H_ */
