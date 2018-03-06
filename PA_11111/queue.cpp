#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"
#include <string>
int count=0;

template <class T>
Queue<T>::Queue()
{
	ListItem<T> * node=list.getHead();
	node=NULL;
	//list;
}
    
template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue) :list(otherQueue.list)
{
//	LinkedList<T> mylist(otherQueue.list);
	//list=mylist;
}

template <class T>
Queue<T>::~Queue()
{
//	list.~LinkedList();
}

template <class T>
void Queue<T>::enqueue(T item)
{
	list.insertAtTail(item);
}

template <class T>
T Queue<T>::front()
{
//	ListItem<T> * node=new ListItem<T>(list.getHead()->value);
//	node =list.getHead();
//	T val;
//	val=node->value;
//	return val;
	return list.getHead()->value;
}

template <class T>
T Queue<T>::dequeue()
{	
		ListItem<T> * mynode= new ListItem<T> (list.getHead()->value);
		mynode=list.getHead();
		T item;
		item=mynode->value;
		list.deleteHead();
		count=0;
		return item;
	
}

template <class T>
int Queue<T>::length()
{
	return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
if (list.length()==0)

	return true;
	else
	return false;
}
template <class T>
void Queue<T>:: AddVip (T item)
{
	if (count>0)                              
	{
		ListItem<T> *node=list.getHead();
		for (int i=1 ;i<count ; i++)
		node=node->next;
		list.insertAfter(item,node->value);
		count++;
		
	}
	else if (count==0)
	{
	
	list.insertAtHead(item);
		count++;

	}
}


#endif
