/*
File: SortedList.cpp
Assignment: CSCI 232 Lab 3
Author: Will Augustine

Description: The cpp file for the SortedList class.
	The SortedList class is a linked list of objects of the Node class that are 
		stored in alphabetical order
*/

// Includes the header file for the class
#include "SortedList.h"

/*
Inserts a node into the correct alphabetical position of the list

Inputs:
	Node* n: Node object pointer to be added to the list

Outputs: None
*/
void SortedList::insertMid(Node* n)
{
	// Set the current position at the start (head)
	Node* currNode = this->head;

	// While not at the end of the list
	while (currNode != NULL)
	{
		// If the new node should be inserted at the end of the list
		//		if the new node is after current node alphabetically and the
		//			current node is the last item in the list
		if ((n->data > currNode->data) && (currNode->next == NULL))
		{
			// Insert the node into the end of the list, passing in the last node (currNode)
			this->insertEnd(n, currNode);
			cout << "Inserted node at end of list" << endl;
			return;
		}
		// If the new node falls between the current node and the following node
		//		if the new node is after current node alphabetically and the
		//			new node is before current node's next alphabetically
		else if ((n->data > currNode->data) && (n->data <= currNode->next->data))
		{
			// Set the node after the new node
			n->next = currNode->next;
			// Set the node before the new node
			currNode->next = n;
			cout << "Inserted node into middle of list" << endl;
			return;
		}
		// Move on to the next node
		currNode = currNode->next;
	}
}

/*
Inserts a node into the front of the list

Inputs:
	Node* n: Node object pointer to be added to the list

Outputs: None
*/
void SortedList::insertFront(Node* n)
{
	// Get the current head of the list
	Node* oldHead = this->head;
	// Update the head to the new node
	this->head = n;
	// Set the node after the new node
	this->head->next = oldHead;
}

/*
Searches for a value in the list and returns a boolean of if the 
	inputted item is in the list

Inputs:
	string s: the value you are looking for

Outputs:
	bool: true if the value is in the list, otherwise false
*/
bool SortedList::searchVal(string s)
{
	// Set the current position (to be used in printing if value is found)
	int currPos = 0;

	// Set the current node to the start of the list
	Node* currNode = this->head;

	// If the start of the list is null (the list is empty)
	if (currNode == NULL)
	{
		cout << "The list is empty, so the value does not exist..." << endl;
		return false;
	}

	// If the value is the first item in the list
	if (currNode->data == s)
	{
		cout << s << " is the first item in the list!" << endl;
		return true;
	}

	// While the current node's data is not the inputted value
	while (currNode->data != s)
	{
		// Move on to the next node
		currNode = currNode->next;
		// Increment the position variable
		currPos++;
		// If the current node is the end of the list, the inputted value was not in the list
		if (currNode == NULL)
		{
			cout << "'" << s << "' could not be found in the list." << endl;
			return false;
		}
	}

	// Since we stopped traversing the list without reaching the end, the value is in the list
	cout << "'" << s << "' was found at position " << currPos << "!" << endl;
	return true;
}

/*
Default constructor for SortedList class

Inputs: None

Outputs: None
*/
SortedList::SortedList()
{
	// Create a new Node object
	Node* newNode = new Node();
	// Set the first item in list to new Node object
	this->head = newNode;
	// Update the length of the list
	this->length = 1;
}

/*
Parameterized constructor for SortedList class

Inputs:
	string s: The string to set the Node's data to

Outputs: None
*/
SortedList::SortedList(string s)
{
	// Create a new Node object using the inputted string
	Node* newNode = new Node(s);
	// Set the first item in list to new Node object
	this->head = newNode;
	// Update the length of the list
	this->length = 1;
}

/*
Traverses through the list, printing each item's data

Inputs: None

Outputs: None
*/
void SortedList::printList()
{
	// Set current node place to the start (head) of list
	Node* currNode = this->head;

	// If there are no items in the linked list, let the user know
	if (currNode == NULL)
	{
		cout << "The sorted linked list is empty." << endl;
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
Search for the value in the list at an inputted index

Inputs:
	int index: the index you are looking at

Outputs:
	string: the node's data at the inputted index
*/
string SortedList::searchList(int index)
{
	// Set the current node at the start of the list
	Node* currNode = this->head;
	// Starting at 0, increment i until it is greater than or equal to the inputted index
	for (int i = 0; i < index; i++)
	{
		// Move on to the next node
		currNode = currNode->next;
		// If the current node is the end of the list, let the user know the index is larger than the list length
		if (currNode == NULL)
		{
			return "The inputted index of " + to_string(index) + " exceeds the size of the list (" + to_string(this->length) + ")";
		}
	}
	// Return the current node's data
	return currNode->data;
}

/*
Inserts a node into the linked list in alphabetical order

Inputs:
	string s: the new node's data

Outputs: None
*/
void SortedList::insert(string s)
{
	// Create a new Node object with the inputted data
	Node* newNode = new Node(s);

	// Increment the length tracker
	this->length++;

	// If the start of the list is null (the list is empty)
	if (this->head == NULL)
	{
		// Add the new node to the empty list and let the user know
		this->insertEmpty(newNode);
		cout << "Inserted node into empty list" << endl;
		return;
	}
	
	// If the inputted data is less than or equal to the first node's data
	if (s <= this->head->data)
	{
		// Add the new node to the front of the list and let the user know
		this->insertFront(newNode);
		cout << "Inserted node into front of list" << endl;
		return;
	}

	// Add the node to the middle (not first or last spot) of the list
	this->insertMid(newNode);
}

/*
Gets the length of the list

Inputs: None

Outputs:
	int: the length of the list
*/
int SortedList::getLength()
{
	// Return the length class variable
	return this->length;
}

/*
Removes the first occurance of a node with data equal to the inputted data

Inputs:
	string s: the node data that you wish to delete from the list

Outputs: None
*/
void SortedList::remove(string s)
{
	// Set the current node to the start of the list
	Node* currNode = this->head;
	// If the start of the list is null (the list is empty)
	if (currNode == NULL)
	{
		// Let the user know the list is empty and nothing can be removed
		cout << "The list is empty..." << endl;
		return;
	}

	// Decrement the length of the list
	this->length--;

	// If the start of the list's data is equal to the inputted data
	if (currNode->data == s)
	{
		// Update the head to be the second item in the list
		this->head = currNode->next;
		// Free the current head from memory
		free(currNode);
		// Let the user know the item was removed
		cout << "Removed the item '" << s << "' from the list!" << endl;
		return;
	}

	// While the current node's data does not equal the inputted data
	while (currNode->data != s)
	{
		// Move on to the next node
		currNode = currNode->next;
		// If the current node is the end of the list
		if (currNode == NULL)
		{
			// Let the user know the item is not in the list
			cout << "The item '" << s << "' was not found in the list..." << endl;
			return;
		}
	}

	// Get the node two after the current node
	Node* afterCurrNode = currNode->next->next;
	// Delete the node after current node from memory
	delete currNode->next;
	// Update the node after the current node
	currNode->next = afterCurrNode;
	// Let the user know the item was removed from the list
	cout << "Removed the item '" << s << "' from the list!" << endl;
}

/*
Removes the node at the inputted index from the list

Inputs:
	int pos: the position you want to remove a node at

Outputs: None
*/
void SortedList::removeAtPosition(int pos)
{
	// Set the current node to the first item in the list
	Node* currNode = this->head;

	// If the first item in the list is null (the list is empty)
	if (currNode == NULL)
	{
		// Let the user know the list is empty and no value was removed
		cout << "The list is empty..." << endl;
		return;
	}

	// Decrement the length of the list
	this->length--;

	// If you are supposed to remove the first item in the list
	if (pos == 0)
	{
		// Update the head to the second item in list
		this->head = currNode->next;
		// Free the old head from memory
		free(currNode);
		// Let the user know a node was removed
		cout << "Removed the item at position " << pos << " from the list!" << endl;
		return;
	}

	// Starting at 0, increment i until it is greater than or equal to one less than the inputted position
	for (int i = 0; i < pos - 1; i++)
	{
		// Move on to the next node
		currNode = currNode->next;
		// If the current node is the end of the list
		if (currNode == NULL)
		{
			// Let the user know their inputted index is larget than the length of the list
			cout << "The inputted position of " << pos << " exceeds the size of the list (" << this->length << ")" << endl;
			return;
		}
	}

	// Get the node two after the current node
	Node* afterCurrNode = currNode->next->next;
	// Delete the node after current node from memory
	delete currNode->next;
	// Update the node after the current node
	currNode->next = afterCurrNode;
	// Let the user know a node was removed
	cout << "Removed the item at position " << pos << " from the list!" << endl;
}

/*
Delete all items in the list and reset the length of the list

Inputs: None

Outputs:
	bool: true if the list reset was successful, otherwise false
*/
bool SortedList::erase()
{
	// Set the current node to the start of the list
	Node* currNode = this->head;
	// While the current node is not the end of the list
	while (currNode != NULL)
	{
		// Update the head to the second node in the list
		this->head = this->head->next;
		// Delete the old head from memory
		delete currNode;
		// Move on to the next node
		currNode = this->head;
	}

	// Reset the length of the list to 0
	this->length = 0;

	// Return that the list reset was a success
	return true;
}

