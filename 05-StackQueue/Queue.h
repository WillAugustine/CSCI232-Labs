/*
File: Queue.h
Assignment: CSCI 232 Lab 5
Author: Will Augustine

Description: The header file for the Stack class
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "SortedList.h"

using namespace std;

class Queue : private SortedList
{
public:
	/*
	Default constructor for the Queue class

	Description: Creates an empty queue based on the SortedList class

	Input: None

	Output: None
	*/
	Queue();

	/*
	Pushes a Node onto the queue using SortedList's inherited (from LameLinkedList) insertEnd method

	Input:
		Node* n: The Node object to add to the queue

	Output: None
	*/
	void enqueue(Node* n);

	/*
	Looks at the next up (first) Node in the queue using SortedList's searchList method,
		passing in 0 to get the first node in the queue. Peek does but does not remove
		the node at that position

	Input: None

	Output:
		int: The data in the first/next node in the queue
	*/
	int peek();

	/*
	Returns the next up (first) Node in the queue using SortedList's searchList method,
		passing in 0 to get the first node in the queue. It then calls SortedList's
		removeAtPosition method, passing in 0 again.

	Input: None

	Output:
		int: The data in the first/next node in the queue that was removed
	*/
	int dequeue();
};

#endif // !QUEUE_H

