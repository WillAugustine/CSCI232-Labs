/*
File: LameLinkedList.cpp
Assignment: CSCI 232 Lab 3
Author: Will Augustine

Description: The cpp file for the LameLinkedList class.
	The LameLinkedList class is a linked list of objects of the Node class
*/

// Includes the header file for the class
#include "LameLinkedList.h"

/*
Default constructor for LameLinkedList class

Inputs: None

Outputs: None
*/
LameLinkedList::LameLinkedList()
{
	// Create Node object
	Node* node = new Node();
	// Set the head node pointer to the new Node object
	this->head = node;
}

/*
Parameterized constructor for LameLinkedList class

Inputs:
	string s: The string to set the Node's data to

Outputs: None
*/
LameLinkedList::LameLinkedList(string s)
{
	// Create Node object
	Node* node = new Node(s);
	// Set the head node pointer to the new Node object
	this->head = node;
}

/*
Traverses through the list, printing each item's data

Inputs: None

Outputs: None
*/
void LameLinkedList::printList()
{
	// Set current node place to the start (head) of list
	Node* currNode = this->head;

	// If there are no items in the linked list, let the user know
	if (currNode == NULL)
	{
		cout << "The lame linked list is empty." << endl;
		return;
	}

	// While not at the end of the list
	while (currNode != NULL)
	{
		// Print the current node's data
		cout << currNode->data << " -> ";
		// Update currNode to the next item in list
		currNode = currNode->next;
	}
	// Print 'NULL' to represent what the last node points to
	cout << "NULL" << endl;
}

/*
Inserts an item into the list. The insertion is always at the end of the list since
	the list is not sorted

Inputs:
	string s: the string to set the new node's data to

Outputs: None
*/
void LameLinkedList::insert(string s)
{
	Node* newNode = new Node(s);

	// If the list is empty, use insertEmpty to add node to empty list
	if (this->head == NULL)
	{
		this->insertEmpty(newNode);
		return;
	}

	// If the list is not empty, use insertEnd to add node to the end
	this->insertEnd(newNode);
}

/*
Inserts an item into an empty list. Can assume this method is only being called if list
	is actually empty

Inputs:
	Node* n: the node to add to the empty list

Outputs: None
*/
void LameLinkedList::insertEmpty(Node* n)
{
	// Update the head/first item in list to the inputted node
	this->head = n;
}

/*
Inserts an item into the end of the list. Can assume this method is only being
	called if list is NOT empty

Inputs:
	Node* n: the node to add to the end of the list
	Node* lastNode (default = NULL): The last node in the list, if already determined

Outputs: None
*/
void LameLinkedList::insertEnd(Node* n, Node* lastNode)
{
	// If the last node in the list was provided
	if (lastNode != NULL)
	{
		lastNode->next = n;
		return;
	}
	// Create tracker for current node and set it to first item in list
	Node* currNode = this->head;
	// While not on the last node
	while (currNode->next != NULL)
	{
		// Update currNode to go to the next node in list
		currNode = currNode->next;
	}
	// Set the next item in the list (last item) to the inputted node
	currNode->next = n;
}