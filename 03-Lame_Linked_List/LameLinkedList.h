#ifndef LAMELINKEDLIST_H
#define LAMELINKEDLIST_H

#include "Node.h"

class LameLinkedList
{
private:
	Node* head;

public:
	LameLinkedList();
	LameLinkedList(string);

	void printList();
	void insert(string);
	void insertEmpty(Node);
	void insertEnd(Node);
};

#endif
