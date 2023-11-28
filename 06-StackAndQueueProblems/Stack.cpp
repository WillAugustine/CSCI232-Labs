/*
.cpp file for the Stack class

File: Stack.cpp
Author: Will Augustine
Assignment: CSCI 232 Lab 6
*/

#include "Stack.h"

/*
Default constructor for the Stack class. Sets the top index to the starting point

Inputs: None

Outputs: None
*/
Stack::Stack()
{
	// Set the top index to 0
	this->top = -1;
	// Set the size to 0
	this->size = 0;
}

/*
Checks if the stack is full or not

Inputs: None

Outputs:
	bool: true if the stack is full, otherwise false
*/
bool Stack::isFull()
{
	// If the front is in the same place as the end of the stack
	//	the stack is full
	if (this->size >= maxStackSize)
	{
		return true;
	}
	// Otherwise, the stack is not full
	return false;
}

/*
Checks if the stack is empty or not

Inputs: None

Outputs:
	bool: true if the stack is empty, otherwise false
*/
bool Stack::isEmpty()
{
	// If the size of the stack is equal to 0 the stack must be empty
	if (this->size == 0)
	{
		return true;
	}
	// Otherwise, the stack is not empty
	else
	{
		return false;
	}
}

/*
Adds an element to the back of the stack if the stack is not full

Inputs:
	int element: the element to add

Outputs: None
*/
void Stack::push(char element)
{
	// If the stack is full, let the user know the element cannot be added
	if (this->isFull()) {
		cout << "\nERROR: The stack is at maximum capacity - no more elements can be added" << endl;
		return;
	}
	
	// Increment the top of the stack
	this->top++;

	// Add the element to the stack
	this->stack[this->top] = element;

	// Increment the size of the stack
	this->size++;

	// Let the user know what was inserted
	//cout << "\nInserted the element '" << element << "' at index " << this->top	<< endl;
}

/*
Removes the element at the top of the stack

Inputs: None

Outputs:
	int: The element that was removed
*/
char Stack::pop()
{
	// If the stack is empty, let the user know
	if (this->isEmpty())
	{
		cout << "\nERROR: The stack is empty so there are no elements remove." << endl;
		return NULL;
	}
	// Keep track of the element that is being removed
	char element = this->stack[this->top];
	// Keep track of the index of the element that is being removed
	int index = this->top;

	// If this is the last element in the stack, update front and rear
	//	index values to their default values
	if (this->size == 1)
	{
		this->top = -1;
	}
	else
	{
		this->top--;
	}
	// Decrement the size of the stack
	this->size--;

	// Let the user know what was removed
	//cout << "\nRemoved the element '" << element << "' at index " << index << endl;
	return element;
}

/*
Displays the front and rear index values in the stack as well as
	each element in the stack

Inputs: None

Outputs: None
*/
void Stack::print() {
	// If the stack is empty, let the user know
	if (this->isEmpty())
	{
		cout << "\nERROR: The stack is empty so there are no elements to display" << endl;
		return;
	}
	// Display the front and rear indicies
	cout << "\nThe top index is " << this->top << endl;
	cout << "The elements of the stack are:\n";
	
	// Starting at the front until the index reaches the rear
	for (int i = 0; i != this->top; i++)
	{
		// Print the element at the current position
		cout << this->stack[i] << " -> ";
	}
	
	cout << "TOP OF STACK" << endl;
}

/*
Returns the size of the stack

Inputs: None

Outputs:
	int: The size of the stack
*/
int Stack::length()
{
	return this->size;
}

/*
Returns a string value of all combined elements in the stack

Inputs: None

Outputs:
	string: The combined string of all elements in the stack
*/
string Stack::toString()
{
	// Create the empty string to be returned
	string toReturn = "";

	// Create an array of the pre-determined size to copy stack onto
	char stackCopy[maxStackSize];
	// Copy this->stack to stackCopy so popping does not affect this->stack
	copy(begin(this->stack), end(this->stack), begin(stackCopy));

	// While the stack is not empty
	while (!this->isEmpty())
	{
		// Add the character to the final string
		toReturn.push_back(this->pop());
	}

	// Reset the stack to before the popping occured
	copy(begin(stackCopy), end(stackCopy), begin(this->stack));

	// Return the combined string
	return toReturn;

}
