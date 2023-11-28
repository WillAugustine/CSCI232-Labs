/*
File: Stack.h
Assignment: CSCI 232 Lab 5
Author: Will Augustine

Description: The header file for the Stack class
*/

#ifndef STACK_H
#define STACK_H

#include "SortedList.h"

using namespace std;

class Stack : private SortedList
{
public:
	/*
	Default constructor for the Stack class

	Description: Creates an empty stack based on the SortedList class

	Input: None

	Output: None
	*/
	Stack();

	/*
	Pushes a Node onto the stack using SortedList's inherited (from LameLinkedList) insertEnd method

	Input:
		Node* n: The Node object to add to the stack

	Output: None
	*/
	void push(Node* n);

	/*
	Looks at the next up (top) Node on the stack using SortedList's searchList method,
		passing in the length of the list to get the last node in the stack. Peek does
		but does not remove the node at that position

	Input: None

	Output: 
		int: The data in the last/top node in the stack
	*/
	int peek();

	/*
	Returns the next up (top) Node on the stack using SortedList's searchList method,
		passing in the length of the list to get the last node in the stack. It then calls
		SortedList's removeAtPosition method, passing in the length again.

	Input: None

	Output:
		int: The data in the last/top node in the stack that was removed
	*/
	int pop();
};

#endif // !STACK_H

