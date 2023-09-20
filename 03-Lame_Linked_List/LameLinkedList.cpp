#include "LameLinkedList.h"

LameLinkedList::LameLinkedList()
{
	Node* node = new Node();
	this->head = node;
}

LameLinkedList::LameLinkedList(string s)
{
	Node* node = new Node(s);
	this->head = node;
}

void LameLinkedList::printList()
{
	Node* currNode = this->head;
	while (currNode != NULL)
	{
		cout << currNode->data << " -> ";
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}