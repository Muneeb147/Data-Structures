#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "list.h"
#include "list.cpp"
#include "HashC.cpp"
#include <time.h>

//=====================================================================================
ListItem<long> * merge (ListItem<long> *a ,ListItem<long> *b)
{
	ListItem<long> * node=NULL;
	if (a==NULL)
	return b;
	if (b==NULL)
	return a;
	
	if (a->value <= b->value)
	{
		node=a;
		node->next=merge(a->next,b);
	}
	else
	{
		node=b;
		node->next=merge(a,b->next);
	}
	return node;
	
}
void partition(ListItem<long> * head,ListItem<long> **front,ListItem<long> **back)
{
//	List<long> LINKEDLIST;
//	LINKEDLIST.setHead(head);
	ListItem<long> * slow;
	ListItem<long> * fast;
	if (head==NULL || head->next==NULL)
	{
		*front=head;  // first half of linked list
		*back=NULL; // second half of linked list
	}
	else
	{
		//slow=LINKEDLIST.getHead();
		slow=head;
		fast=head->next;
		//for (int i=0;i<(LINKEDLIST.length()/2)-1;i++)
		//{
		//	slow=slow->next;
		//}
		
		while (fast!=NULL)
		{
			fast=fast->next;
			if (fast!=NULL)
			{
				fast=fast->next;
				slow=slow->next;
			}
		}
		*front=head; // first half
		*back=slow->next; // second half
		slow->next=NULL; // breaking the contact
	}
}
void SWAP(long a[],int index1,int index2)
{
	int temp=a[index1];
	a[index1]= a[index2];
	a[index2]=temp;
}
int find_median (long array[],int index1,int index2,int index3)
{
	int k;
	int my_array[3];
	my_array[0]=array[index1];
	my_array[1]=array[index2];
	my_array[2]=array[index3];
	for (int i=1;i<3;i++)  // insertion sort
	{
		int key=my_array[i];
		k=i-1;
		while(my_array[k]>key && k>=0)
		{
			my_array[k+1]=my_array[k];
			k--;
		}
		my_array[k+1]=key;
	}
	int median = my_array[1];
	if (median==array[index1])
	return index1;
	if (median==array[index2])
	return index2;
	
	return index3;
}

int partitionQ(long myarray[], int start, int end,int select)
{
	srand (time(NULL));
	if (select==1)
	{
    	int pivot = myarray[end]; // selecting end as pivot 
    	int i = start - 1;
    	for (int j=start ; j<end; j++)
    	{
        	if (myarray[j] <= pivot)
       	 	{
            	i++;
            	SWAP(myarray,i,j);
        	}	
    	}
    	SWAP (myarray,i+1,end);
    	return i + 1;
	} // index of pivot
	else if (select==2)
	{ 	
		int pivot_index=start;								// selecting start index pivot 
		SWAP (myarray,pivot_index,end);
		int pivot=myarray[end]; 
    	int i = start - 1;
    	for (int j=start ; j<end; j++)
    	{
        	if (myarray[j] <= pivot)
       	 	{
            	i++;
            	SWAP(myarray,i,j);
        	}	
    	}
    	SWAP (myarray,i+1,end);
    	return i + 1;
	}
	else if (select==3)
	{ 
		// median wala
		if (end-start==1)
		{
			int pivot = myarray[end]; // selecting end as pivot 
    		int i = start - 1;
    		for (int j=start ; j<end; j++)
    		{
        		if (myarray[j] <= pivot)
       	 		{
            		i++;
            		SWAP(myarray,i,j);
        		}	
    		}
    	SWAP (myarray,i+1,end);
    	return i + 1;
		}
	else 
		{
		
		int first,second,third;
		first =rand () % (end-start+1) + start;
		while (1)
		{
			second = rand () % (end-start+1) + start;
			if (second!=first)
			break; 
		}
		while (1)
		{
			third=rand () % (end-start+1) + start;
			if (third!=second && third!=first)
			break;
		}
		int pivot_index=find_median(myarray,first,second,third);
    	 SWAP(myarray,pivot_index,end); // moving that pivot to last
		 int pivot=myarray[end]; 
    	int i = start - 1;
    	for (int j=start ; j<end; j++)
    	{
        	if (myarray[j] <= pivot)
       	 	{
            	i++;
            	SWAP(myarray,i,j);
        	}	
    	}
    	SWAP (myarray,i+1,end);
    	return i + 1;
	}
	}
} 
void quicksortarray(long my_array [],int start,int end,int select)
{
	if (start<end)
	{
			int pivot_index=partitionQ(my_array,start,end,select);
			quicksortarray(my_array,start,pivot_index-1,select);
			quicksortarray(my_array,pivot_index+1,end,select);
	}
}

void mergesort (ListItem<long> **node)
{
	ListItem<long> * head=*node;
	ListItem<long> * temp=NULL;
	ListItem<long> * temp2=NULL;
	if (head==NULL || head->next==NULL)
	{
		return ; // base case
	}
	partition (head,&temp,&temp2);
	mergesort(&temp);
	mergesort(&temp2);
	*node=merge(temp,temp2);	
}
void swap ( int* a, int* b )
{   int t = *a;      *a = *b;       *b = t;   }
/*ListItem <long> * partitionLinkedlist (ListItem <long> * first,ListItem <long> * end)
{
	int pivot =end->value;
	ListItem<long> * temp=first->prev;
	ListItem<long> * i;
	for (i=first;i!=end;i=i->next)
	{
		if (i->value<= pivot)
		{
			temp=temp->next;
			//swapping temp and i k value
			swap(&(temp->value),&(i->value));
		//	int x=i->value;
		//	i->value=temp->value;
		//	temp->value=x;
		}
	}
	temp=temp->next;
	//int x=temp->value;
	//temp->value=end->value;
	//end->value=x;
	swap(&(temp->value),&(end->value));
	return temp;
	
}
void quicksortlinkedlist (ListItem <long> * head,ListItem<long> * tail)
{
	if (head!=NULL && tail!=NULL)
	{
		ListItem<long> * temp= partitionLinkedlist(head,tail);
		quicksortlinkedlist(head,temp->prev);
		quicksortlinkedlist(temp->next,tail);
	}
}
*/
vector<long> InsertionSort(vector<long> nums)
{
	int k;
	vector<long>New;
	 long size=nums.size();
	 long my_array[size];
	for (int i=0;i<size;i++)
	{
		my_array[i]=nums[i];
	}
	for (int i=1;i<size;i++)
	{
		long key=my_array[i];
		k=i-1;
		while(my_array[k]>key && k>=0)
		{
			my_array[k+1]=my_array[k];
			k--;
		}
		my_array[k+1]=key;
	}
	// copying the elements into vector
	for (int i=0;i<size;i++)
	{
		New.push_back(my_array[i]);
	}
	return New;
	

}

//=====================================================================================
vector<long> MergeSort(vector<long> nums)
{
	List<long> mylist;
	vector <long> myvec;
	for (int i=0;i<nums.size();i++)
		mylist.insertAtHead(nums[i]);
		
		ListItem <long> * temp=mylist.getHead();
		mergesort(&temp);
		mylist.setHead(temp);
		ListItem<long> * NEWHEAD=mylist.getHead();
		for (int i=0;i<nums.size();i++)
		{
			myvec.push_back(NEWHEAD->value);
			NEWHEAD=NEWHEAD->next;
		}
		return myvec;

}

//=====================================================================================
vector<long> QuickSortArray(vector<long> nums)
{
	vector <long> Nums;
	int select;
	cout << "press 1 for selecting pivot from end, 2 for start, 3 for 3-elements median " << endl;
	cin >> select;
	
	long int size=nums.size();
	long int my_array[size];
	for (int i=0;i<size;i++)
	{
		my_array[i]=nums[i];
	}
	int start=0,end=size-1;
	
	quicksortarray(my_array,start,end,select);
	
	for (int i=0;i<nums.size();i++)
	{
		Nums.push_back(my_array[i]);
	}
	return Nums;
	
	
}

//=====================================================================================
vector<long> QuickSortList(vector<long> nums)
{
	/*List<long> mylist;
	vector <long> myvec;
	for (int i=0;i<nums.size();i++)
		mylist.insertAtHead(nums[i]);
		
		ListItem <long> * head=mylist.getHead();
		ListItem <long> * tail=mylist.getTail();
		quicksortlinkedlist(head,tail);
		Listitem<long>* node=mylist.getHead();
		for (int i=0;i<nums.size();i++)
		{
			
			myvec.push_back(node);
			node=node->next;
		}
		return myvec;
		*/
}

//=====================================================================================
void  balance_extractmin(long heap[],long size)
{
	int parent,leftchild,rightchild;
 	//parent=2childindex;
 	//leftchild=2i 
	 //rightchild=2i+1
	for (int i=size/2;i>=1;i--)
	{
		parent=i;
		leftchild=2*i;
		rightchild=2*i+1;
		if (leftchild<size && heap[parent]>heap[leftchild])
		{
			parent=leftchild;
		}
		if (rightchild<size && heap[parent]>heap[rightchild])
		{
			parent=rightchild;
		}	
		if (parent!=i)
		{
			int val=heap[i];
			heap[i]=heap[parent];
			heap[parent]=val;
			balance_extractmin(heap,size);
			
		}
	}
}
 vector <long>   make_minheap(long heap [],long size)
  {
  	vector <long> sorted;
  	for (int i=size;i>1;i--)
  	{
  		balance_extractmin(heap,i);
  		sorted.push_back(heap[1]);
  		heap[1]=heap[i-1];
		  	
	}
	//cout << "size :" << sorted.size()<< endl;
	return sorted;
  }
vector<long> HeapSort(vector<long> nums)
{
		long heap[nums.size()+1];
		for (int i=0;i<nums.size();i++)
		{
			heap[i+1]=nums[i];
		}
		
	return(make_minheap(heap,nums.size()+1));
		
}

//=====================================================================================
vector<long> BucketSort(vector<long> nums, int max)
{
	vector<long> sorted;
	HashC bucket(max);
	for (int i=0;i<nums.size();i++)
	{
		bucket.insert(nums[i]);
	}
	for (int i=0;i<max;i++)
	{
		if (bucket.hashTable[i].head!=NULL)
		{
			ListItem <long> * node=	bucket.hashTable[i].head;
			while (node!=NULL)
			{
				sorted.push_back(node->value);
				node=node->next;
			}
		}
	}
	return sorted;
}
#endif
