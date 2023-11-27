/*
File: Queue.h
Assignment: CSCI 232 Lab 5
Author: Will Augustine

Description: The header file for the Queue class.
	The Queue class is a linked list structure but ordered as a queue (FIFO)
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "LameLinkedList.h"

using namespace std;

// Inherits the LameLinkedList class
class Queue : private LameLinkedList
{
private:
	Node* head;
	int length = 0;

public:
	// Default constructor for the Queue class
	Queue();

	/*
	Adds the inputted Node object to the back of the linked list using
		the LameLinkedList::insertEnd method.

	Inputs:
		Node*: The node to be added to the stack

	Outputs: None
	*/
	void enqueue(Node*);

	/*
	Looks at the next Node object up in the queue (the first Node to be added - the
		head Node) and returns the data of that Node

	Inputs: None

	Outputs:
		string: the data of the node on top of the queue
	*/
	string peek();

	/*
	Looks at the next Node object up in the queue (the first Node to be added - the
		head Node) and deletes that Node, then returns the data of that Node

	Inputs: None

	Outputs:
		string: the data of the node on top of the queue
	*/
	Node* dequeue();

	void printList();
	int getLength();
	bool erase();
};

#endif // !QUEUE_H

