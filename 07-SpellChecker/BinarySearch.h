/*
Author: Will Augustine
File: BinarySearch.h

The header file for the BinarySearch class
*/

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

// Standard namespace
using namespace std;

// Namespace for timing executions
using namespace chrono;

// Sets the size of the dictionary that will be used
const int dictionarySize = 1400;

// The BinarySearch class
class BinarySearch
{
// Variables and methods only accessable to the BinarySearch class
private:

    // An array of strings that represents the binary search array
    string dictionary[dictionarySize];

// Variables and methods accessable to external classes and methods
public:
    // Parameterized constructor that adds words from the inputted file to dictionary array
    BinarySearch(string fileName);

    // Perform binary search on the array and return the number of comparisions conducted
    int findWord(string word, int count = 1);

    // Prints all items in the array WITHOUT the execution time being printed
    void printDictionary();

    // Prints all items in the array WITH the execution time being printed
    void printDictionaryWithTimer();
};
