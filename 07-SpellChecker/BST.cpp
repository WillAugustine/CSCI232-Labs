/*
Author: Will Augustine
Assignment: CSCI 232 Lab 7
File: BST.cpp

The implementation file for the BST class
*/

#include "BST.h"

/*
Parameterized constructor for the BST class. Reads the inputted file and inserts each word
    in the text file into the BST.

Inputs:
    string filename: The file to be read

Outputs: None
*/
BST::BST(string filename) : root(nullptr) {
    // Open the inputted file
    ifstream file(filename);

    // If the file could not open, let the user know
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Variable to store the current word (one word per line) in the inputted file
    string word;
    while (file >> word) {
        // Add the word to the BST
        insert(word);
    }

    // Close the file
    file.close();
}

/*
Private part of the insert method. Inserts a node recursively into the BST

Inputs:
    Node* root: The top Node object of the BST subtree
    string key: The string you are trying to input

Outputs: None
*/
BST::Node* BST::insert(Node* root, string key) {
    // If you are at the end of the BST, insert the new node
    if (root == nullptr)
        return new Node{ key, nullptr, nullptr };

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Public function to insert a string into the BST tree
void BST::insert(string s) {
    root = insert(root, s);
}

// Helper function to find a word in the BST tree
int BST::findWord(Node* root, string key, int count) {
    if (root == nullptr)
        return count; // Word not found

    if (key < root->key)
        return findWord(root->left, key, count + 1);
    else if (key > root->key)
        return findWord(root->right, key, count + 1);
    else
        return count; // Word found
}

// Public function to find a word in the BST tree
int BST::findWord(string s, int count) {

    // Record start time for beginning of the action
    auto start = high_resolution_clock::now();

    int numOfComparisions = findWord(root, s, count);

    // Record stop time for end of action
    auto stop = high_resolution_clock::now();

    // Calculate duration of action in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Convert duration to seconds
    auto seconds = duration / 1000000;

    // Let the user know the execution time
    cout << "\tFound the word in " << duration.count() << " microseconds (" << seconds.count() << " seconds)." << endl;


    return numOfComparisions;
}

// Helper function to calculate the height of the BST
int BST::getHeightHelper(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = getHeightHelper(root->left);
    int rightHeight = getHeightHelper(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Public function to get the height of the BST
int BST::getHeight() {
    return getHeightHelper(root);
}

string BST::getTopWord() {
    if (root == nullptr) {
        cerr << "Error: Tree is empty." << endl;
        return "";
    }
    return this->root->key;
}
