#ifndef CHAINING__H
#define CHAINING__H
#include <iostream>
#include "list.cpp" // Your Own Implementation
#include <cstring>

using namespace std;

class HashC
{
	protected:
		long int tableSize;
		int collisions; 
		int a; 
		
		public:
	List<long>*hashTable;
		HashC(int max);
		void Load(char* file); // Load a file of Strings into your Hash table
		int hash(string word); // Given a String, return its hash
		void insert(long num); // Takes a hash of 'word' and inserts it into hashTable accordingly
		ListItem<long>* lookup(string word);
		int Collisions(); // Return number of collisions in hashTable
};
#endif
