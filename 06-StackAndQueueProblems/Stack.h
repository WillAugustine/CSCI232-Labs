/*
Header file for the Queue class

File: Queue.h
Author: Will Augustine
Assignment: CSCI 232 Lab 6
*/

// If the Queue class is not already defined, define it
#ifndef STACK_H
#define STACK_H 

#include <iostream>
#include <ostream>

using namespace std;

// Set the size of circular stack
//	const so the size variable cannot be changed
int const maxStackSize = 25;

// Queue class
class Stack {

// Variables and methods that are only to be used in the Stack class
private:
	
	// Create the array of the pre-determined size
	char stack[maxStackSize];
	
	// Int variable to keep track of the top of the stack
	int top;

// Variables and methods to be accessed outside of the Queue class
public:
	// Variable to track the size of the stack
	int size = 0;

	// Default constructor
	Stack();
	
	// Checks if the stack is full or not
	bool isFull();

	// Checks if the stack is empty or not
	bool isEmpty();

	// Adds an element to the stack
	void push(char element);

	// Removes the next up (top) element from the stack, returning
	//	its value
	char pop();

	// Prints the stack
	void print();

	// Returns the size of the stack
	int length();

	// Combines the elements of the stack into a single string
	string toString();
};

#endif