#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include "list.cpp"
#include <cstdlib>
using namespace std;
class HashC
{
	protected:
		long int tableSize;
		int collisions; 
		int a; 
		
		public:
	List<long>*hashTable;
		HashC()
		{
				hashTable=new List<long>[tableSize];
		for (int i = 0; i < tableSize; i++)
		{
			hashTable[i].head = NULL;
		}
		}
};
ListItem<long> * merge (ListItem<long> *a ,ListItem<long> *b)
{	
		ListItem <long> * merged;
	
	while (a!=NULL || b!=NULL)
	{
		if (a->value<=b->value)
		{
			merged->value=a->value;
			a=a->next;
		}
		else
		{
			merged->value=b->value;
			b=b->next;
		}
		merged=merged->next;
	}
	if (a!=NULL)
	{
		while (a!=NULL)
		{
			merged->value=a->value;
			a=a->next;
			merged=merged->next;
		}
	}
	if (b!=NULL)
	{
		while (b!=NULL)
		{
			merged->value=b->value;
			b=b->next;
			merged=merged->next;
		}
	}
	return merged;
	
//	if (a==NULL)
//	return b;
//	if (b==NULL)
//	return a;
//	
//	if (a->value <= b->value)
//	{
//		node=a;
//		node->next=merge(a->next,b);
//	}
//	else
//	{
//		node=b;
//		node->next=merge(a,b->next);
//	}
//	return node;
	
}
void partition(ListItem<long> * head,ListItem<long> **front,ListItem<long> **back)
{
	ListItem<long> * slow;
	ListItem<long> * fast;
	if (head==NULL || head->next==NULL)
	{
		*front=head;  // first half of linked list
		*back=NULL; // second half of linked list
	}
	else
	{
		slow=head;
		fast=head->next;
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

vector<long> InsertionSort(vector<long> nums)
{
	int k;
	long int size=nums.size();
	long int my_array[size];
	for (int i=0;i<size;i++)
	{
		my_array[i]=nums[i];
	}
	for (int i=1;i<size;i++)
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
	// copying the elements into vector
	for (int i=0;i<size;i++)
	{
		nums.push_back(my_array[i]);
	}
	return nums;
	
}

vector<long> InsertSort(vector<long> nums)
{
	int k;
	vector <long> sorted;
	long int size=nums.size();
	long int my_array[size];
	for (int i=0;i<size;i++)
	{
		my_array[i]=nums[i];
	}
	for (int i=1;i<size;i++)
	{
		int key=my_array[i];
		k=i;
		while(my_array[k-1]>key )
		{
			my_array[k]=my_array[k-1];
			k--;
		}
		my_array[k]=key;
	}
	// copying the elements into vector
	for (int i=0;i<size;i++)
	{
		sorted.push_back(my_array[i]);
	}
	return sorted;
	

}
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
 
 //  QUICK SOrt K FUNC
 
void SWAP(long a[],int index1,int index2)
{
	int temp=a[index1];
	a[index1]= a[index2];
	a[index2]=temp;
}
void swap ( long* a, long* b )
{   long t = *a; 
     *a = *b;
	        *b = t;
  
  }
  
  
ListItem <long> * partitionLinkedlist (ListItem <long> **first,ListItem <long> ** end)
{
	int pivot =(*end)->value;
	ListItem<long> * temp=(*first)->prev;
	ListItem<long> * i;
	for (i=*first;i!=*end;i=i->next)
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
	swap(&(temp->value),&((*end)->value));
	return temp;
}
ListItem<long> **  quicksortlinkedlist (ListItem <long> ** head,ListItem<long> ** tail)
{
	if ((*head)!=NULL && (*tail)!=NULL&& (*tail)->next!=NULL)
	{
		ListItem<long> * temp= partitionLinkedlist(head,tail);
		quicksortlinkedlist(head,&temp->prev);
		quicksortlinkedlist(&temp->next,tail);
	}
	else
	return head;
}

vector<long> QuickSortList(vector<long> nums)
{
List<long> mylist;
	vector <long> myvec;
	for (int i=0;i<nums.size();i++)
		mylist.insertAtHead(nums[i]);
		
		ListItem <long> * head=mylist.getHead();
		ListItem <long> * tail=mylist.getTail();
	ListItem <long> ** myhead=quicksortlinkedlist(&head,&tail);
		ListItem<long>* node=mylist.getHead();
		for (int i=0;i<nums.size();i++)
		{
			
			myvec.push_back((*myhead)->value);
			(*myhead)=(*myhead)->next;
		}
		return myvec;
}

int find_median (long array[],int index1,int index2,int index3)
{
	int k;
	int my_array[3];
	my_array[0]=array[index1];
	my_array[1]=array[index2];
	my_array[2]=array[index3];
	for (int i=1;i<3;i++)  // insertion sor
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

int partitionQ(long myarray[], int start, int end,int select) // BAIG
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
	
} 
void quicksortarray(long my_array [],int start,int end,int select) //BAIG
{
	if (start<end)
	{
			int pivot_index=partitionQ(my_array,start,end,select);
			quicksortarray(my_array,start,pivot_index-1,select);
			quicksortarray(my_array,pivot_index+1,end,select);
	}
}
vector<long> QuickSortArray(vector<long> nums) // BAIG
{
	vector <long> Nums;
	int select;
	cout << "press 1 for selecting pivot from end, 2 for start" << endl;
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
void  check_heap_prop(long myarray[],long size)
{
	int p;
	int lchild;
	int rchild;
	for (int i=size/2;i>0;i--)
	{
		p=i;
		lchild=2*i;
		rchild=2*i+1;
		if (lchild<size && myarray[p]>myarray[lchild])
		{
			if (myarray[lchild]>myarray[rchild])
			p=rchild;
			else
			p=lchild;
		}
		if (rchild<size && myarray[p]>myarray[rchild])
		{
			if (myarray[lchild]>myarray[rchild])
			p=rchild;
			else
			p=lchild;
		}	
		if (p!=i || p==lchild || p==rchild )
		{
			long temp=myarray[i];
			myarray[i]=myarray[p];
			myarray[p]=temp;
		check_heap_prop(myarray,size);
			
		}
	}
}
 vector <long>   make_minheap(long heap [],long size)
  {
  	vector <long> sorted;
  	for (int i=size;i>1;i--)
  	{
  		check_heap_prop(heap,i);
  		sorted.push_back(heap[1]);
  		heap[1]=heap[i-1];
		  	
	}
	cout << "size :" << sorted.size()<< endl;
	return sorted;
  }
vector<long> HeapSort(vector<long> nums)
{
	long size= nums.size()+1;
		long heaparray[size];
		for (int i=0;i<=size;i++)
		{
			heaparray[i+1]=nums[i];  // copying the elements into the array
		}
		vector <long> sortedvector;
  	for (int i=size;i>1;i--)
  	{
  		check_heap_prop(heaparray,i);
  		sortedvector.push_back(heaparray[1]);
  		heaparray[1]=heaparray[i-1];
	}
	return sortedvector;
		
}
vector<long> BucketSort(vector<long> nums, int max)
{
	HashC bucket;
	vector<long> sorted_vector;
	int tablesize=max;
	//HashC bucket(max);
	for (int i=0;i<nums.size();i++)
	{
		
		unsigned int key= nums[i] % tablesize;
		

		bucket.hashTable[key].insertAtHead(nums[i]);
	}
	for (int i=0;i<tablesize;i++)
	{
		if (bucket.hashTable[i].head!=NULL)
		{
			ListItem <long> * head=	bucket.hashTable[i].getHead();
			while (head!=NULL)
			{
				sorted_vector.push_back(head->value);
				head=head->next;
			}
		}
	}
	return sorted_vector;
}

int main ()
{
	List<int> mylist;
	vector <long> b,c;
	int size=14;
	int a[size]={0,-1,3,2,4,5,1,6,7,4,0,3,5,9};
	for (int i=0;i<size;i++)
//	mylist.insertAtHead(a[i]);
	b.push_back(a[i]);
	
	cout << "list before sorting" << endl;
		for (int i=0;i<size;i++)
		{
			cout << b[i]<<endl;
		}
	//	c=InsertSort(b);
	//c=HeapSort(b);
	c=MergeSort(b);
	cout << "AFTER SORTING" << endl;
		for (int i=0;i<c.size();i++)
		{
			cout <<"value :"<< c[i]<<endl;
			//cout << "key :"	<< c[i]%10	<<endl;
		}
	
	
}

