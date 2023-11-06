#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "LameLinkedList.h"

class SortedList : public LameLinkedList
{
private:
	int length = 0;
	void insertMid(Node);
	bool searchVal(string);
	Node* head;

public:
	SortedList();
	SortedList(string);

	void printList();

	string searchList(int);
	void insert(string);
	int getLength();
	void remove(string);
	void removeAtPosition(int);
	bool erase();
};

#endif
