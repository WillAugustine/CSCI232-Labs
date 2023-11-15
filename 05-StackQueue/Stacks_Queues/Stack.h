/*
File: Stack.h
Assignment: CSCI 232 Lab 5
Author: Will Augustine

Description: The header file for the Stack class.
	The Stack class is a linked list structure but ordered as a stack (LIFO)
*/

#ifndef STACK_H
#define STACK_H

#include "LameLinkedList.h"

using namespace std;

// Inherits the LameLinkedList class
class Stack : private LameLinkedList
{
private:
	Node* head;
	int length = 0;

public:
	// Default constructor for the Stack class
	Stack();

	/*
	Adds the inputted Node object to the back of the linked list using
		the LameLinkedList::insertEnd method.

	Inputs:
		Node*: The node to be added to the stack

	Outputs: None
	*/
	void push(Node*);

	/*
	Looks at the next Node object up in the stack (the last Node to be added)
		and returns the data of that Node

	Inputs: None

	Outputs:
		string: the data of the node on top of the stack
	*/
	string peek();

	/*
	Looks at the next Node object up in the stack (the last Node to be added)
		and deletes that Node, then returns the data of that Node

	Inputs: None

	Outputs:
		string: the data of the node on top of the stack
	*/
	Node* pop();

	void printList();
	int getLength();
	bool erase();
};

#endif // !STACK_H

