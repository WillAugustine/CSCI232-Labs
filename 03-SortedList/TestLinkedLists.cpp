#include "SortedList.h"
#include "LameLinkedList.h"
#include "Node.h"

#include <string>
#include <iostream>

int main()
{
	LameLinkedList linkedList("test");
	cout << "\nlinkedList has type '" << typeid(linkedList).name() << "'" << endl;
	linkedList.printList();

	SortedList sortedList("another test");
	cout << "\nsortedList has type '" << typeid(sortedList).name() << "'" << endl;
	sortedList.printList();
}