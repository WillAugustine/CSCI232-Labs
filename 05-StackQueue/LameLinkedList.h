/*
File: LameLinkedList.h
Assignment: CSCI 232 Lab 3
Author: Will Augustine

Description: The header file for the LameLinkedList class
*/

// If the header file is not already defined
#ifndef LAMELINKEDLIST_H
// Define the contents of the header file
#define LAMELINKEDLIST_H

// Include the Node class
#include "Node.h"

// LameLinkedList class
class LameLinkedList
{
// Private variables/methods
private:
	// Pointer to head node in list
	Node* head;

// Public variables/methods
public:
	// Default constructor for LameLinkedList class
	LameLinkedList();
	// Parameterized constructor for LameLinkedList class
	LameLinkedList(string);

	// Prints the linked list
	void printList();
	// Inserts string into the linked list
	void insert(string);

// Protected variables/methods
protected:
	// Inserts node into an empty linked list
	void insertEmpty(Node*);
	// Inserts node into the end of linked list
	void insertEnd(Node*, Node* = NULL);
};

#endif
