#ifndef QUEUE_IMPL_H_
#define QUEUE_IMPL_H_

#include <iostream>
#include "Queue.h"

using namespace std;

class EmptyQueueException{};

template<class T>
Queue<T>::Queue()
{
	front = NULL;
	back = NULL;
	count = 0;
}

template<class T>
Queue<T>::~Queue()
{
	while(!isEmpty())
	{
		dequeue();
	}
}

template<class T>
void Queue<T>::enqueue (const T & item)
{
	QueueItem<T> *newElement = new QueueItem<T>();
	newElement->val = item;
	newElement->next = NULL;
	newElement->prev = NULL;
	
	if (back == NULL)
	{
		back = newElement;
		front = back;
	}
	else
	{
		back -> prev = newElement;
		newElement -> next = back;
		newElement -> prev = NULL;
		back = newElement;
	}
		
	count++;
}

template<class T>
void Queue<T>::dequeue ()
{
	if(!isEmpty())
	{
		QueueItem<T> *temp = front;
		if(front == back)
		{
			delete front;
			front = NULL;
			back = NULL;
		}
		else
		{
			front = temp->prev;
			temp->next = NULL;
			delete temp;

		}
	count--;
	}
	else
		throw EmptyQueueException();	

	
}

template<class T>
const T & Queue<T>::peekFront ()
{
	if(!isEmpty())
	{
		return front->val;
	}
	else
		throw EmptyQueueException();
}

template<class T>
bool Queue<T>::isEmpty ()
{
	
	return back == NULL;
}
template<class T>
int Queue<T>::size()
{
	return count;
}

#endif
