/*
File: Node.h
Assignment: CSCI 232 Lab 3
Author: Will Augustine

Description: The header file for the Node class
*/

// If the header file is not already defined
#ifndef NODE_H
// Define the contents of the header file
#define NODE_H

// Since Node.h is used by all other files, include imports to be used
#include <iostream>
#include <string>
#include <typeinfo>

// Set the namespace to standard namespace
using namespace std;

// Node class
class Node
{
// Public variables/methods
public:
	// Data for each node in the lists
	string data;
	// Pointer to the following node in list
	Node* next;

	// Default constructor
	Node();
	// Parameterized constructor
	Node(string);
};

#endif
