/*
.cpp file for the Queue class

File: Queue.cpp
Author: Will Augustine
Assignment: CSCI 232 Lab 6
*/

#include "Queue.h"

/*
Default constructor for the Queue class. Sets the front and rear index
	values to the starting point

Inputs: None

Outputs: None
*/
Queue::Queue()
{
	// Set the front index to -1
	this->front = -1;
	// Set the rear index to 0
	this->rear = -1;
	// Set the size to 0
	this->size = 0;
}

/*
Checks if the queue is full or not

Inputs: None

Outputs:
	bool: true if the queue is full, otherwise false
*/
bool Queue::isFull()
{
	// If the front is in the same place as the end of the queue
	//	the queue is full
	if (this->size >= maxQueueSize)
	{
		return true;
	}
	// Otherwise, the queue is not full
	return false;
}

/*
Checks if the queue is empty or not

Inputs: None

Outputs:
	bool: true if the queue is empty, otherwise false
*/
bool Queue::isEmpty()
{
	// If the size of the queue is equal to 0 the queue must be empty
	if (this->size == 0)
	{
		return true;
	}
	// Otherwise, the queue is not empty
	else
	{
		return false;
	}
}

/*
Adds an element to the back of the queue if the queue is not full

Inputs:
	int element: the element to add

Outputs: None
*/
void Queue::enqueue(int element)
{
	// If the queue is full, let the user know the element cannot be added
	if (this->isFull()) {
		cout << "\nERROR: The queue is at maximum capacity - no more elements can be added" << endl;
		return;
	}
	// If the queue is empty
	if (this->isEmpty()) {
		// Set the front index of the queue to 0
		this->front = 0;
	}
	// Increment the rear index
	this->rear++;

	// If the rear index is larger than the max size of the queue
	//	reset the rear index to 0 (front of the array)
	if (this->rear >= maxQueueSize)
	{
		this->rear = 0;
	}
	// Add the element to the queue
	this->arr[this->rear] = element;

	// Increment the size of the queue
	this->size++;

	// Let the user know what was inserted
	//cout << "\nInserted the element '" << element << "' at index " << this->rear	<< endl;
}

/*
Removes the element at the front of the queue

Inputs: None

Outputs:
	int: The element that was removed
*/
int Queue::dequeue()
{
	// If the queue is empty, let the user know
	if (this->isEmpty())
	{
		cout << "\nERROR: The queue is empty so there are no elements remove." << endl;
		return NULL;
	}
	// Keep track of the element that is being removed
	int element = this->arr[this->front];
	// Keep track of the index of the element that is being removed
	int index = this->front;

	// If this is the last element in the queue, update front and rear
	//	index values to their default values
	if (this->size == 1)
	{
		this->front = -1;
		this->rear = 0;
	}
	else
	{
		// Increment the front index
		this->front++;

		// If the front index is larger than the max size of the queue
		//	reset the front index to 0 (front of the array)
		if (this->front >= maxQueueSize)
		{
			this->front = 0;
		}
	}
	// Decrement the size of the queue
	this->size--;

	// Let the user know what was removed
	//cout << "\nRemoved the element '" << element << "' at index " << index << endl;
	return element;
}

/*
Displays the front and rear index values in the queue as well as
	each element in the queue

Inputs: None

Outputs: None
*/
void Queue::print() {
	// If the queue is empty, let the user know
	if (this->isEmpty())
	{
		cout << "\nERROR: The queue is empty so there are no elements to display" << endl;
		return;
	}
	// Display the front and rear indicies
	cout << "\nThe front index is " << this->front << " and the rear index is " << this->rear << endl;
	cout << "The elements of the queue are:\n";
	
	// Starting at the front until the index reaches the rear
	for (int i = this->front; i != this->rear;  i = (i + 1) % maxQueueSize)
	{
		// Print the element at the current position
		cout << this->arr[i] << " -> ";
	}
	
	cout << "END OF QUEUE" << endl;
}
