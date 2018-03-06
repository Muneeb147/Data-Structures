#ifndef __LIST_CPP
#define __LIST_CPP
# include <iostream>
#include <cstdlib>
#include "LinkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
	head=NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{ 
	ListItem <T>*temp = otherLinkedList.head ;

            if (otherLinkedList.head!=NULL)
            {
                head = new ListItem <T> (temp->value);
                ListItem <T> *cop = head ;

                while (temp->next !=NULL)
                {
                    temp = temp->next ;
                    cop->next = new ListItem <T> (temp->value) ;
                    cop = cop->next ;
                }
            }
            else 
            head=NULL;



}

template <class T>
LinkedList<T>::~LinkedList()
{
	ListItem<T> * temp =head;
	if (head==NULL)
	return;
	while (temp->next!=NULL)
	{
		head=head->next;
		delete temp;
		temp=head;
	}
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    ListItem <T> *temp = new ListItem <T> (item);
	if (head==NULL)
	{
		head= temp ;
		//head->value=item;
		//head->next= NULL;
		//head->prev=NULL;
	}
	else
	{
		ListItem<T>* temp=new ListItem<T>(item);
		//temp->value=item;
		temp->next=head;
		head->prev=temp;

		//temp->prev=NULL;
		head=temp;
	}
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
	if (head==NULL)
	{
		ListItem <T> *temp = new ListItem <T> (item);

		 head=temp;
 ////head->value=item;
	//	head->prev=NULL;
	//	head->next=NULL;
	}
	else
	{
		ListItem<T> * temp=head;
		ListItem<T>* temp1=new ListItem<T>(item);
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
			temp->next=temp1;
			temp1->prev=temp;
			//temp2->value=item;
			temp1->next=NULL;

		
	}
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
	if (head==NULL)
		insertAtHead(toInsert);
	else
	{
	ListItem<T> * newNode = new ListItem<T>(toInsert);
	
    	ListItem<T>* checkptr=head;
		while (checkptr->value!=afterWhat && checkptr->next!=NULL)
			checkptr=checkptr->next;
    	
          
    	
		if (checkptr->next!=NULL)
		{
    	// now checkpointer is pointing to the node after which we wanna add the new node;
		newNode->next=checkptr->next;
		checkptr->next=newNode;
		newNode->prev=checkptr;
		newNode->next->prev=newNode;
		}
		else
		{
			newNode->next=NULL;
			newNode->prev=checkptr;
			checkptr->next=newNode;
		}
    
	}


}

template <class T>
void LinkedList<T>::insertSorted(T item)
{
	if(head == NULL)
	insertAtHead(item);
	
	else
	{
		ListItem<T> *Tail = head;
		while(Tail->next != NULL)
		Tail = Tail->next;
	
		if(Tail->value < item)
		insertAtTail(item);
 	
		else if (head!=NULL)
		{
			ListItem<T> *temp = head;
			int done=1;
			while(temp != NULL|| done==1)
			{
				if((temp->value >= item)&&(temp->prev == NULL))
					{
					insertAtHead(item);
					done=0;
					break;
					}
				else if ((temp->value>=item) && (temp->prev!=NULL))
				
				{
					ListItem<T> *newnode = new ListItem<T>(item);
						temp->prev->next = newnode;
						newnode->prev = temp->prev;
						newnode->next = temp;
						temp->prev = newnode;
						done=0;
					    break;
				}
	          		 else if ((temp->value<item) && (temp->prev==NULL))
				temp =  temp->next;
					else if ((temp->value<item) && (temp->prev!=NULL))
					temp=temp->next	;		
           }
		}
				
	}
	
	}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
	if (head==NULL)
		return NULL;
	else
		return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
	if (head==NULL)
	{
		return NULL;
	}
	else
	{
		ListItem<T> * C= head;
		int done=1;
		while (done==1)
		{
			if (C->next==NULL)
			{
				return C;
				done =0;
				break;
			}
			C=C->next;
		}
	}

}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
	if (head==NULL)
		{
			cout << "list is not created"<< endl;
			return NULL;
		}
	else
		{
			// checking for presence of item
		/*	int check=0;
	 		ListItem<T> * temp1= head;
	 		while (temp1->next!=NULL)
	 		{
	 			if (temp1->next->value==item)
	 				check=1;
	 			temp1=temp1->next;
	 		}
	 		if (check==0)
	 		{
	 			cout << "item not found" << endl;
	 			return NULL;
	 		}
	 		*/
			
			ListItem <T> *temp=head;
			int check=0;
		while (temp !=NULL)
		
		   {
		   		if (temp->value==item)
		   		{
		   			check=1;
		   			return temp;
		   			break;
				}
		   	
//			if (temp->next !=NULL)
//			temp = temp->next ;
//
//			else
//			{
//				return NULL;
//				break;
//			}
//			}
//			return temp;
		temp=temp->next;
		}
		
		if (check==0)
		return NULL;
		

	}
			
		

}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
  ListItem <T> *temp = head ;
		if (head ==NULL)
			return;
		else
		{
			while (temp->value != item && temp->next!=NULL)
				temp=temp->next;
				
				if(temp==head)
				deleteHead();
				
				else if(temp->next==NULL)
					deleteTail();

				else
				{
				
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				}
			
			


		}
}

template <class T>
void LinkedList<T>::deleteHead()
{
   if (head!=NULL){
   
   	ListItem<T> * Temp=head;
	head=head->next;
	delete Temp;
}
}

template <class T>
void LinkedList<T>::deleteTail()
{
	ListItem<T> *Node = head;
	//Node = head->next;
	if (Node==NULL)
	{
		cout << "no list is created";
		return;
//		return;

	}

		
	 //if (Node->next==NULL)
	 //{
	 //	ListItem<T> * temp=head;
	 //	delete temp;
	 //	head=NULL;
	 //}
	 else if (Node->next==NULL) 
	 	delete head;
		 else
		 {
		   
	 while (Node->next!=NULL)
	 	Node=Node->next;
		 Node->prev->next = NULL ;
		Node->prev =NULL ;
                delete Node;
        }
}

template <class T>
int LinkedList<T>::length()
{
	if (head==NULL)
		return 0;
	else
	{
		int i=1;
		ListItem <T> * temp=head;
		while (temp->next!=NULL)
		{
			i++;
			temp=temp->next;

		}
		return i;
	}
}

template <class T>
void LinkedList<T>::reverse()
{
	// by swapping the prev and next node
	if (head==NULL)
	{
		cout << " no lnked list created"<< endl;
	}
	else
	{
		ListItem<T> * Begin=head;
		ListItem<T> * End=NULL;
		while (Begin!=NULL)
		{
			End=Begin->next;
			Begin->next=Begin->prev;
			Begin->prev=End;

			if (Begin->prev==NULL)
				head=Begin;

			Begin=Begin->prev;
		}
	}


}
template <class T>
void LinkedList<T>::parityArrangement()
{
	ListItem<T>* mynode=head;
	int i=0;	
	while (i<length())
	{
		
		if(mynode->value%2!=0)
		{//	cout<<v<<endl;
			insertAtTail(mynode->value);
			deleteElement(mynode->value);
		}
		mynode=mynode->next;
		i++;

	}
}

#endif




