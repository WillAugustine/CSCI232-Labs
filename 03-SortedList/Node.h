#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Node
{
public:
	string data;
	Node* next;

	Node();
	Node(string);
};

#endif
