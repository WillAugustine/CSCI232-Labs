/*
.cpp file for the Palindrome class

File: Palindrome.cpp
Author: Will Augustine
Assignment: CSCI 232 Lab 6
*/

#include "Palindrome.h"

/*
Parameterized constructor for the Palindrome class. Sets the stringToCheck, palindromeStack,
	and reversedPalindromeStack

Inputs:
	string input: The input to check if it is a palindrome or not

Outputs: None
*/
Palindrome::Palindrome(string input)
{
	// If the inputted string cannot fit in the stack, let the user know
	if (input.size() >= maxStackSize)
	{
		cout << "ERROR: Use a string less than " << maxStackSize << " characters long!" << endl;
		return;
	}

	// Convert the inputted string to all lowercase
	for (int i = 0; i < input.size(); i++)
	{
		input[i] = tolower(input[i]);
	}

	// Set the stringToCheck variable
	this->stringToCheck = input;

	// For each character in the inputted string
	for (int i = 0; i < this->stringToCheck.size(); i++)
	{
		// Add the character to the top of the reversedPalindromeStack
		this->reversedPalindromeStack.push(this->stringToCheck[i]);
	}
}

/*
Returns if the inputted string is a palindrome or not

Inputs: None

Outputs:
	bool: true if the inputted string is a palindrome, otherwise false
*/
bool Palindrome::isPalindrome()
{
	// Get the combined string representation of the reversedPalindromeStack
	string reversedInput = this->reversedPalindromeStack.toString();

	// Return if the inputted string is the same as the reversed input
	return (this->stringToCheck == reversedInput);
}