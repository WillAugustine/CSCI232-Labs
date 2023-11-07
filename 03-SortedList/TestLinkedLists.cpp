/*
File: TestLinkedLists.cpp
Assignment: CSCI 232 Lab 3
Author: Will Augustine

Description: The cpp file for testing the Node, LameLinkedList, and SortedList classes.
*/

// Includes the header file for the SortedList class, which includes
//		all other files and libraries
#include "SortedList.h"

int main()
{
	cout << "-------- TESTING LameLinkedList CLASS --------\n" << endl;

	cout << "Creating list with parameterized constructor" << endl;
	LameLinkedList linkedList("first");

	cout << "\nThis is what the list looks like: " << endl;
	linkedList.printList();

	cout << "\nAdding elements to the list:" << endl;
	cout << "Adding 'second'" << endl;
	linkedList.insert("second");
	cout << "Adding 'third'" << endl;
	linkedList.insert("third");
	cout << "Adding 'fourth'" << endl;
	linkedList.insert("fourth");

	cout << "\nThis is what the list looks like: " << endl;
	linkedList.printList();

	cout << "\n-------- TESTING COMPLETE --------" << endl;

	cout << "\n-------- TESTING SortedList CLASS --------\n" << endl;

	cout << "Creating list with parameterized constructor" << endl;
	SortedList sortedList("bb");

	cout << "\nThis is what the list looks like: " << endl;
	sortedList.printList();

	cout << "\nAdding elements to the list:" << endl;
	cout << "Adding 'cc'\n\t";
	sortedList.insert("cc");
	cout << "Adding 'aa'\n\t";
	sortedList.insert("aa");
	cout << "Adding 'zz'\n\t";
	sortedList.insert("zz");
	cout << "Adding 'ab'\n\t";
	sortedList.insert("ab");
	cout << "Adding 'ac'\n\t";
	sortedList.insert("ac");
	cout << "Adding 'bb'\n\t";
	sortedList.insert("bb");
	cout << "Adding 'f'\n\t";
	sortedList.insert("f");
	cout << "Adding 'zzz'\n\t";
	sortedList.insert("zzz");

	cout << "\nThis is what the list looks like: " << endl;
	sortedList.printList();

	cout << "\nThe list has a length of " << sortedList.getLength() << endl;

	cout << "\nRemoving the node 'ac' from the list (node DOES exist)\n\t";
	sortedList.remove("ac");

	cout << "\nThis is what the list looks like: " << endl;
	sortedList.printList();

	cout << "\nThe list has a length of " << sortedList.getLength() << endl;

	cout << "\nRemoving the node 'q' from the list (node DOES NOT exist)\n\t";
	sortedList.remove("q");

	cout << "\nRemoving the node at position 2 from the list (position is less than length)\n\t";
	sortedList.removeAtPosition(2);

	cout << "\nThis is what the list looks like: " << endl;
	sortedList.printList();

	cout << "\nThe list has a length of " << sortedList.getLength() << endl;

	cout << "\nRemoving the node at position 9 from the list (position is NOT less than length)\n\t";
	sortedList.removeAtPosition(9);

	cout << "\nSearching list for item at index 3 (index is less than length)\n\t";
	cout << sortedList.searchList(3) << endl;

	cout << "\nSearching list for item at index 8 (index is NOT less than length)\n\t";
	cout << sortedList.searchList(8) << endl;

	cout << "\nErasing the list" << endl;
	cout << "Erase was successful? " << boolalpha << sortedList.erase() << endl;

	cout << "\nThis is what the list looks like: " << endl;
	sortedList.printList();

	cout << "\nThe list has a length of " << sortedList.getLength() << endl;

	cout << "\n-------- TESTING COMPLETE --------" << endl;
}