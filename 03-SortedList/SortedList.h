/*
File: SortedList.h
Assignment: CSCI 232 Lab 3
Author: Will Augustine

Description: The header file for the SortedList class
*/

// If the header file is not already defined
#ifndef SORTEDLIST_H
// Define the contents of the header file
#define SORTEDLIST_H

// Include the LameLinkedList class for inheritance
#include "LameLinkedList.h"

// SortedList class inherits public members of LameLinkedList class
class SortedList : public LameLinkedList
{
// Private variables/methods
private:
	// Length tracker for list
	int length = 0;
	// Pointer to first node in list
	Node* head;
	
	// Inserts node into front of list
	void insertFront(Node*);
	// Inserts node into middle of list
	void insertMid(Node*);
	// Searches of string is in list
	bool searchVal(string);

// Public variables/methods
public:
	// Default constructor
	SortedList();
	// Parameterized constructor
	SortedList(string);

	// Prints the list
	void printList();
	// Gets the value at the inputted index of list
	string searchList(int);
	// Inserts item into list (in order insertion)
	void insert(string);
	// Gets the length of the list
	int getLength();
	// Removes the first occurance of inputted value from list
	void remove(string);
	// Removes node at inputted position from list
	void removeAtPosition(int);
	// Erases entire list
	bool erase();
};

#endif
