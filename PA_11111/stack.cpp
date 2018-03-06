#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
	ListItem<T> * node=list.getHead();
	node=NULL;
}
    
template <class T>
Stack<T>::Stack(const Stack<T>& otherStack) : list(otherStack.list)
{
	
//this.list(otherStack.list);
	//list=mylist;
	
}

template <class T>
Stack<T>::~Stack() 
{
	list.~LinkedList();
}

template <class T>
void Stack<T>::push(T item)
{
	list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
	return list.getHead()->value;
}

template <class T>
T Stack<T>::pop()
{
	if (list.length()==0)
	return 0;
	else
	{
		ListItem<T> * mynode= new ListItem<T> (NULL);
		mynode=list.getHead();
		T item=mynode->value;
		list.deleteHead();
		return item;
	}
}

template <class T>
int Stack<T>::length()
{
	return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
	if (list.length()==0)
	return true;
	return false;
}

#endif
