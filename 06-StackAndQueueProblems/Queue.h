/*
Header file for the Queue class

File: Queue.h
Author: Will Augustine
Assignment: CSCI 232 Lab 6
*/

// If the Queue class is not already defined, define it
#ifndef QUEUE_H
#define QUEUE_H 

#include <iostream>
#include <ostream>

using namespace std;

// Set the size of circular queue
//	const so the size variable cannot be changed
int const maxQueueSize = 5;

// Queue class
class Queue {

// Variables and methods that are only to be used in the Queue class
private:
	
	// Create the array of the pre-determined size
	int arr[maxQueueSize];
	
	// Int variable to keep track of the front of the queue
	int front;
	
	// Int variable to keep track of the back of the queue
	int rear;

// Variables and methods to be accessed outside of the Queue class
public:
	// Variable to track the size of the queue
	int size = 0;

	// Default constructor
	Queue();
	
	// Checks if the queue is full or not
	bool isFull();

	// Checks if the queue is empty or not
	bool isEmpty();

	// Adds an element to the queue
	void enqueue(int element);

	// Removes the next up (first) element from the queue, returning
	//	its value
	int dequeue();

	// Prints the queue
	void print();
};

#endif