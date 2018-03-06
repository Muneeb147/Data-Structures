#ifndef __LIST_H
#define __LIST_H
#include <cstdlib>
#include <string>
using namespace std;

/* This class just holds a single data item. */

struct ListItem
{
    string value;
    ListItem *next;
    ListItem *prev;

    ListItem(string theVal)
    {
        this->value = theVal;
        this->next = NULL;
        this->prev = NULL;
    }
};

/* This is the generic List class */

class LinkedList
{
	public:
    ListItem *head;
    string Value;


    // Constructor
    LinkedList();

    // Copy Constructor
    LinkedList(const LinkedList& otherList);

    // Destructor
    ~LinkedList();

    // Insertion Functions
    void insertAtHead( string item);
    void insertAtTail(string item);
    void insertAfter(string toInsert, string afterWhat);
    void insertSorted(string item);

    // Lookup Functions
    ListItem *getHead();
    ListItem *getTail();
    ListItem *searchFor(string item);

    // Deletion Functions
    void deleteElement(string item);
    void deleteHead();
    void deleteTail();

    // Utility Functions
    int length();
    void reverse();
    void parityArrangement();
};

#endif
