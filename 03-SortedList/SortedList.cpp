#include "SortedList.h"

SortedList::SortedList()
{
	Node* node = new Node();
	this->head = node;
	this->length++;
}

SortedList::SortedList(string s)
{
	Node* node = new Node(s);
	this->head = node;
	this->length++;
}

void SortedList::printList()
{
	cout << "entering printList" << endl;
	Node* currNode = this->head;
	cout << "set currNode where data = '" << currNode->data << "'" << endl;
	while (currNode != NULL)
	{
		cout << currNode->data << " -> ";
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}