#ifndef OPENADDRESSING__CPP
#define OPENADDRESSING__CPP
#include <iostream>
#include <fstream>
#include<math.h>
#include "openAddress.h"
# include <vector>
using namespace std;

OpenAddress :: OpenAddress(int _a)
{
	a=_a;
	tableSize=20000;
	collisions=0;
	current_size=0;
	hashTable=new string[tableSize];
	
	for (int i = 0; i < tableSize; i++)
		hashTable[i]=" ";

		    	   	
} 

int OpenAddress :: hash(string word)
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

void OpenAddress :: insertItem(string word)
{
	resize();
	int H=hash(word);
	if (hashTable[H]==" ")
	{
		hashTable[H]=word;
		current_size++;
	}
	else if(hashTable[H]!=" ")
	{
		collisions++;
		int check=0;
		for (int i=H+1;i<tableSize;i++)
		{
			if (hashTable[i]==" ")	
			{
				check=1;
				hashTable[i]=word;
				current_size++;
				break;				
			}
			else
			collisions++;
			
		}
		if (check==0) 
		{
			for (int i=0;i<H;i++) //circling
			{
				if (hashTable[i]==" ")	
				{
					hashTable[i]=word;
					current_size++;
					break;				
				}
				else
				collisions++;
			}
		}

		 
	}
} 
void OpenAddress :: Load(char* file)
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
	insertItem(n[i]);
}

string OpenAddress :: lookUp (string word)
{
	int H=hash(word);
	 if (hashTable[H]==word)
	 return hashTable[H];
	
		int check=0;
		int check2=0;
for (int i=H+1; i<tableSize; i++)
		{
			if (hashTable[i]==word)	
			{
				check=1;
				return word;				
			}
		}
		
		if (check==0) 
		{
			for (int i=0;i<H;i++) //circling
			{
				if (hashTable[i]==word)	
				{
					check2=1;
					return word;				
				}
			}
			if (check2==0)
			{
				return " ";
			}
		}	
	
	
}
int OpenAddress:: Collisions()
{
	return collisions;
}
long OpenAddress:: getSize()
{
	return tableSize;
}
void OpenAddress :: resize()
{
	if (current_size==tableSize)
	{
		
		tableSize=2*tableSize;
		string * newarray=new string [tableSize];
		for (int i=0;i<tableSize;i++)
		{
			newarray[i]=" ";
		}
		for (int i=0;i<current_size;i++)
		{
			newarray[i]=hashTable[i];
		}
		hashTable=newarray;
	}
}
# endif 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
