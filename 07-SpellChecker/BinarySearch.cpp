/*
Author: Will Augustine
File: BinarySearch.cpp

The implementation file for the BinarySearch class
*/

#include "BinarySearch.h"

/*
Parameterized constructor for the BinarySearch class. Reads in the inputted file into the
    dictionary array while timing how long it takes

Inputs:
    string fileName: The text file to be read in

Outputs: None
*/
BinarySearch::BinarySearch(string fileName) {

    // Record start time for beginning of the action
    auto start = high_resolution_clock::now();

    // Open the inputted file
    ifstream file(fileName);

    // If the file cannot open, let the user know
    if (!file.is_open()) {
        cout << "Error opening file '" << fileName << "'" << endl;
        return;
    }

    // Starting at the first line of the inputted file until the dictionary array is full
    for (int i = 0; i < dictionarySize; ++i) {
        // Add the word (current line) to the dictionary array
        file >> dictionary[i];
    }

    // Record stop time for end of action
    auto stop = high_resolution_clock::now();

    // Calculate duration of action in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Convert duration to seconds
    auto seconds = duration / 1000000;

    // Let the user know the execution time
    cout << "\tBinarySearch read the file in " << duration.count() << " microseconds (" << seconds.count() << " seconds)." << endl;
    
    // Close the inputted file
    file.close();
}

/*
Looks for the inputted word in the dictionary array by using a recursive binary search
    algorithm. The execution time is marked and reported to the user

Inputs:
    string word: The word to look in the dictionary array for
    int count: The number of executions that took place (default = 1)

Outputs:
    int: The number of executions that took place
*/
int BinarySearch::findWord(string word, int count) {
    // Record start time for beginning of the action
    auto start = high_resolution_clock::now();

    // Set the low index of the subsection of the dictionary array
    int low = 0;
    // Set the high index of the subsection of the dictionary array
    int high = dictionarySize - 1;

    // While the search is still valid
    while (low <= high) {
        // Get the middle point
        int mid = low + (high - low) / 2;

        // If the current word is the word we are looking for
        if (dictionary[mid] == word) {

            // Record stop time for end of action
            auto stop = high_resolution_clock::now();

            // Calculate duration of action in microseconds
            auto duration = duration_cast<microseconds>(stop - start);

            // Convert duration to seconds
            auto seconds = duration / 1000000;

            // Let the user know the execution time
            cout << "\tFound the word in " << duration.count() << " microseconds (" << seconds.count() << " seconds)." << endl;

            // Return the number of comparisons
            return count;
        }
        // If the word is greater than the mid point
        else if (dictionary[mid] < word) {
            // Search in the right half
            low = mid + 1;
        }
        // If the word is less than the mid point
        else {
            // Search in the left half
            high = mid - 1;
        }

        // Increment the number of comparisons
        count++;
    }

    // Record stop time for end of action
    auto stop = high_resolution_clock::now();

    // Calculate duration of word search in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Convert duration to seconds
    auto seconds = duration / 1000000;

    // Let the user know the execution time
    cout << "\tIt took " << duration.count() << " microseconds (" << seconds.count() << " seconds) to determine the word is not there." << endl;

    // Word not found, return -1
    return -1;
}

/*
Traverses through the dictionary array, printing each element. The execution time of printing the
    whole array is tracked and displayed to the user

Inputs: None

Outputs: None
*/
void BinarySearch::printDictionaryWithTimer() {
    // Record start time for beginning of the action
    auto start = high_resolution_clock::now();

    // For each item in the dictionary array, display it
    for (int i = 0; i < dictionarySize; ++i) {
        cout << dictionary[i] << " ";
    }
    cout << endl;

    // Record stop time for end of action
    auto stop = high_resolution_clock::now();

    // Calculate duration of action in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Convert duration to seconds
    auto seconds = duration / 1000000;

    // Let the user know the execution time
    cout << "\tPrinted the dictionary in " << duration.count() << " microseconds (" << seconds.count() << " seconds)." << endl;
}

/*
Traverses through the dictionary array, printing each element. The execution time is not tracked.

Inputs: None

Outputs: None
*/
void BinarySearch::printDictionary() {
    // For each item in the dictionary array, display it
    for (int i = 0; i < dictionarySize; ++i) {
        cout << dictionary[i] << " ";
    }
    cout << endl;
}
