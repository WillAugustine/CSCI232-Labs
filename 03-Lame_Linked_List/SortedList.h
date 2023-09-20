#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "LameLinkedList.h"

class SortedList : LameLinkedList
{
private:
	int length;
	void insertMid(Node);
	bool searchVal(string);

public:
	SortedList();
	SortedList(string);

	string searchList(int);
	void insert(string);
	int getLength();
	void remove(string);
	void removeAtPosition(int);
	bool erase();
};

#endif
