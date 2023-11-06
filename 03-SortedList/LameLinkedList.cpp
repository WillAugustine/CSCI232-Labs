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