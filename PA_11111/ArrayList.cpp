#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& otherArrayList)
{
	
		//capacity=otherArrayList.size;
		array=new T[otherArrayList.size];
			size=otherArrayList.size;
		for (int i = 0;i< size;i++)
		{
			array[i]=otherArrayList.array[i];
		}
	}


template <class T>
ArrayList<T>::~ArrayList()
{
	delete [] array;
	size=0;
}

template <class T>
void ArrayList<T>::insertAtHead(T item)
{
	if (size==0|| array==NULL)
	{
	array[0]=item;
	size++;
    }
    else if (size==capacity)
	{
		resize();
		for (int i = size-1 ; i >= 0 ; i--)
    		array[i+1] = array[i];

			array[0] = item;
			size++;
    	
	}
	else if (size<capacity)
	{
			for (int i = size-1 ; i >= 0 ; i--)
    		array[i+1] = array[i];

			array[0] = item;
			size++;
	}
	

}

template <class T>
void ArrayList<T>::insertAtTail(T item)
{
	if (size==0 || array==NULL)
	{
		array[0]=item;
		size++;
	}
 if (size==capacity)
	{
		resize();
		array[size]=item;
		size++;
	}
else if (size<capacity)
{
	array[size]=item;
	size++;
}
	
}

template <class T>
void ArrayList<T>::insertAfter(T toInsert, T afterWhat)
{
	if (size==0 ||array == NULL)
	 {
	 array[0]=toInsert;
	 size++;
	}
	else if (size==capacity)
	{
		resize();
		int index;
		for (int i=0;i<size;i++)
		{
			if (array[i]==afterWhat)
			{
				index=i+1;
				break;
			}
		}
		for (int i=size ;i>index;i--)
		array[i]=array[i-1];
		array[index]=toInsert;
		size++;
		
	}
	else
	{
			int index;
		for (int i=0;i<size;i++)
		{
			if (array[i]==afterWhat)
			{
				index=i+1;
				break;
			}
		}
		for (int i=size ;i>index;i--)
		array[i]=array[i-1];
		array[index]=toInsert;
		size++;	
	}
	
}

template <class T>
void ArrayList<T>::insertSorted(T item)
{
	if (size==0)
	insertAtHead(item);
	else if (array[size-1] <item)
	insertAtTail(item);
	else
	{
		int in;
	    for (int i=0;i<size;i++)
	    {
	    	if ((array[i]<item)&& (array[i+1]>item))
	    		in=i;
	    		break;
	    	
		}
		insertAfter(item,array[in]);
		
	}
}

template <class T>
T ArrayList<T>::getAt(int i)
{
	return (array[i]);
}

template <class T>
int ArrayList<T>::searchFor(T item)
{

	int index=0;
	for (int i=0;i<size;i++)
	{
		if (array[i]==item)
		{
		  index=i;
			break;
		}
	
	}
	return index;
	
	
}

template <class T>
void ArrayList<T>::deleteElement(T item)
{
	if (array[0]==item)
	deleteHead();
	else if(array[size-1]==item)
	deleteTail();
	
	else
	{
	int I;
	for (int i=0;i<size;i++)
	{
		if (array[i]==item)
		I=i;
		break;
	}
	for (int i=I+1;i<size;i++)
	array[i-1]=array[i];
	size--;
	}
	
}

template <class T>
void ArrayList<T>::deleteAt(int i)
{
	if (i==0)
	deleteHead();
	else if (i==size-1)
	deleteTail();
	else
	{
	for (int k=i+1;k<size;k++)
	array[k-1]=array[k];
	size--;
	}
}

template <class T>
void ArrayList<T>::deleteHead()
{
	for (int k=1;k<size;k++)
	array[k-1]=array[k];
	size--;
}

template <class T>
void ArrayList<T>::deleteTail()
{
	size--;
}

template <class T>
void ArrayList<T>::resize()
{
	if (size==capacity)
	{
		capacity=2*capacity;
		T *newarray=new T [capacity];
		for (int i =0;i<size; i++)
			newarray[i]=array[i];
			delete [] array;
			array=newarray;
	}
	
}

template <class T>
int ArrayList<T>::length()
{
	return size;
}

template <class T>
void ArrayList<T>::reverse()
{
	int i,j;
	T * newarray=new T [size];
	for ( i=0,j=size-1;i<size,j>=0;i++,j--)
	newarray[i]=array[j];	
	delete [] array;
	array=newarray;
}

#endif

