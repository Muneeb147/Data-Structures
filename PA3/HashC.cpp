#ifndef CHAINING__CPP
#define CHAINING__CPP
#include <iostream>
#include <fstream>
#include<math.h>
#include "LinkedList.cpp"
#include "Chaining.h"
#include "LinkedList.h"
# include <vector>
using namespace std;

HashC :: HashC(int _a)
{
	a=_a;
	tableSize=98569;
	collisions=0;
	hashTable=new LinkedList[tableSize];
	for (int i = 0; i < tableSize; i++)
{
	hashTable[i].head = NULL;
}
		    	   	
} 

int HashC :: hash(string word)
{
	unsigned int temp=0;
	int num;
		
		for(int i=0; i<word.size(); i++)
		{
			 num=word[i];
			temp =temp+ (num*(pow(a,i)));
				
		}
		return temp % tableSize ;
		
}

void HashC :: insert(string word)
{
	int H=hash(word);
	if (hashTable[H].head==NULL)
	{
		hashTable[H].insertAtHead(word);
	}
	else if(hashTable[H].head!=NULL)
	{
		collisions++;
		hashTable[H].insertAtTail(word);
	}
} 
void HashC :: Load(char* file)
{
	vector <string> n;
	ifstream Input;
	Input.open(file);
	//head=NULL;
    string lines;
	while (getline(Input,lines))
	{
	    n.push_back(lines);
	}
	Input.close();
	for (int i=0;i<n.size();i++)
	insert(n[i]);
}

ListItem * HashC :: lookup (string word)
{
	int H=hash(word);
	return (hashTable[H].searchFor(word));
}
int HashC:: Collisions()
{
	return collisions;
}

# endif
