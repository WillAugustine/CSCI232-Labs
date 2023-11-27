#ifndef STACK_H
#define STACK_H

#include "LameLinkedList.h"

using namespace std;

class Stack : private LameLinkedList
{
private:
	

public:
	void push(Node*);
	Node* peek();
	Node* pop();
};

#endif // !STACK_H

