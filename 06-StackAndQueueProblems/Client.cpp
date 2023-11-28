/*
Main file for testing Stack, Queue, and Palindrome

File: Client.cpp
Author: Will Augustine
Assignment: CSCI 232 Lab 6
*/

#include "Queue.h"
#include "Palindrome.h"

int main() {
	cout << "------ TESTING QUEUE CLASS ------" << endl;
	
	// Create Queue object
	Queue q;

	// Try dequeuing an empty queue
	q.dequeue();

	// Add 5 elements to the queue
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	
	// Try adding element to full queue
	q.enqueue(5);

	// Display the queue
	q.print();

	// Remove an item from the queue
	q.dequeue();

	// Display the queue
	q.print();

	// Add an element to the queue
	q.enqueue(6);

	// Display the queue
	q.print();

	// Remove an item from the queue
	q.dequeue();
	// Display the queue
	q.print();

	// Remove an item from the queue
	q.dequeue();
	// Display the queue
	q.print();

	// Add an element to the queue
	q.enqueue(8);
	// Display the queue
	q.print();

	cout << "\n------ TESTING PALINDROME ------" << endl;

	// Test that palindrome checker works with the string 'racecar'
	string palindromeInput1 = "racecar";
	Palindrome palindrome1(palindromeInput1);
	cout << "\n\nIs '" << palindromeInput1 << "' a palindrome? " << boolalpha << palindrome1.isPalindrome() << endl;

	// Test that the palindrome checker is not case sensitive by using string 'TAcocaT'
	string palindromeInput2 = "TAcocaT";
	Palindrome palindrome2(palindromeInput2);
	cout << "\n\nIs '" << palindromeInput2 << "' a palindrome? " << boolalpha << palindrome2.isPalindrome() << endl;

	// Test that the palindrome checker works with strings that are not palindromes
	string palindromeInput3 = "notApalindrome";
	Palindrome palindrome3(palindromeInput3);
	cout << "\n\nIs '" << palindromeInput3 << "' a palindrome? " << boolalpha << palindrome3.isPalindrome() << endl;

}