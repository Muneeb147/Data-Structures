#ifndef OPENADDRESSING__H
#define OPENADDRESSING__H
#include <string.h>
#include <string>
using namespace std;

class OpenAddress
{
	public:
		long tableSize;
		string *hashTable;				// Include your linked list class for this!
		int a;							// input to the hash function
		int collisions;
		int current_size;
		OpenAddress(int A);
		void Load(char* file);
		int hash(string);
		long getSize();
		void resize();
		void insertItem(string Word);	// Takes a hash of 'Word' and inserts it into hashTable accordingly
		string lookUp(string Word);		// Looks for 'Word' and if found, returns it
		int Collisions(); // Return number of collisions in hashTable.
};
# endif
