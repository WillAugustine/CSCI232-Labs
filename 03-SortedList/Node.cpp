/*
File: Node.cpp
Assignment: CSCI 232 Lab 3
Author: Will Augustine

Description: The cpp file for the Node class.
	The Node class represents items to be used in a linked list, containing
		a node's data and a pointer to the next node in the list
*/

// Includes the header file for the class
#include "Node.h"

/*
Default constructor for Node class

Inputs: None

Outputs: None
*/
Node::Node()
{
	// Set the next node to null
	this->next = NULL;
}

/*
Parameterized constructor for Node class

Inputs:
	string s: The string to set the Node's data to

Outputs: None
*/
Node::Node(string s)
{
	// Set the node's data to inputted value
	this->data = s;
	// Set the next node to null
	this->next = NULL;
}