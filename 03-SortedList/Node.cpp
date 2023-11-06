#include "Node.h"

Node::Node()
{
	this->next = NULL;
}

Node::Node(string s)
{
	this->data = s;
	this->next = NULL;
}