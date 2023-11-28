/*
Header file for the Palindrome class

File: Palindrome.h
Author: Will Augustine
Assignment: CSCI 232 Lab 6
*/

#ifndef PALINDROME_H
#define PALINDROME_H

#include "Stack.h"
#include <string>
#include <cstring>

using namespace std;

// The Palindrome class
class Palindrome
{
// Variables and methods that are only to be used in the Palindrome class
private:
	// The string that is inputted to the constructor
	string stringToCheck;

	// A Stack object to store the inputted string characters in reverse order
	Stack reversedPalindromeStack;

// Variables and methods to be accessed outside of the Palindrome class
public:
	// Parameterized constructor
	Palindrome(string);

	// Returns if the inputted string is a palindrome
	bool isPalindrome();

};

#endif // !PALINDROME_H

