#ifndef doublehashing__CPP
#define doublehashing__CPP
#include <iostream>
#include <fstream>
#include<math.h>
#include <vector>
#include "doubleHash.h"
using namespace std;
	DoubleHash :: DoubleHash(int A)
{
	a=A;
	tableSize=20000;
	collisions=0;
	current_size=0;
	hashTable=new string[tableSize];
	
	for (int i = 0; i < tableSize; i++)
		hashTable[i]=" ";

		    	   	
} 

int DoubleHash :: hash2(string word)
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

int DoubleHash :: hash1(string word)
{
	unsigned int hash1=0;
		
		for(int i=0; i<word.size(); i++)
		{
			hash1 ^= (hash1 << 5) + (hash1 >> 2) + word[i];
		}
		return hash1% tableSize;
		
}

void DoubleHash :: insertItem(string word)
{
	resize();	
unsigned int H=0;
 int i=0;
	for (i=0;i<100;i++)
	{
			H=(hash2(word) + i*hash1(word))% tableSize;
			
	 		if(hashTable[H]==" ")
			{
				//cout << "hash :" <<H << " i: "<<i << endl;
				//cout << "yeah"<< endl;
				hashTable[H]=word;
				current_size++;			 
				break;
			}
			else if (hashTable[H]!=" ")
			{
				//cout << "purana hash:" << H  << "  1+2: " << hash2(word)*i + hash1(word)<<" i: "<<i << endl ;
				collisions++;  
			}
	}
	if (i==100)
	{
		hashTable[tableSize-1]=word;
		current_size++;
	}
	
		
} 
void DoubleHash :: Load(char* file)
{
	vector <string> n;
	ifstream Input;
	Input.open(file);
    string lines;
	while (getline(Input,lines))
	{
	    n.push_back(lines);
	}
	Input.close();
	for (int i=0;i<n.size();i++)
	insertItem(n[i]);
}

string DoubleHash :: lookUp (string word)
{
	unsigned int H;
	int i;
	for ( i=0;i<100;i++)
	{
	
	H=(hash2(word) + i*hash1(word)) % tableSize;
	 if (hashTable[H]==word)
	 {
	 
	 return hashTable[H];
	 break;
	}
	}
	if (i==100)
	{
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
}
int DoubleHash:: Collisions()
{
	return collisions;
}
long DoubleHash:: getSize()
{
	return tableSize;
}
void DoubleHash :: resize()
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


#endif
