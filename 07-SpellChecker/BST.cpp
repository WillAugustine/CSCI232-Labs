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
        cout << "Error opening file '" << filename << "'" << endl;
        return;
    }

    // Variable to store the current word (one word per line) in the inputted file
    string word;

    // While not at the end of the file
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

Outputs:
    Node*: The new root node
*/
BST::Node* BST::insert(Node* root, string key) {
    // If you are at the end of the BST, insert the new node
    if (root == nullptr)
        return new Node{ key, nullptr, nullptr };

    // If the new node should go to the left
    if (key < root->key)
        // Move to the left child node
        root->left = insert(root->left, key);
    // If the new node should go to the right
    else if (key > root->key)
        // Move to the right child node
        root->right = insert(root->right, key);

    // Return the inputted root
    return root;
}

/*
Public part of the insert method. Inserts a node into the BST by using the private
    insert method

Inputs:
    string s: The string you are trying to input

Outputs: None
*/
void BST::insert(string s) {
    // Set the root to the output of the private insert method
    root = insert(root, s);
}

/*
Private part of the findWord method. Looks for a node recursively in the BST and counts the
    number of operations executed

Inputs:
    Node* root: The top Node object of the BST subtree
    string key: The string you are looking for
    int count: The number of executions executed (default = 1)

Outputs:
    int: The number of executions executed
*/
int BST::findWord(Node* root, string key, int count) {
    // If the end of the list is reached, let the user know the word was not found
    if (root == nullptr)
        cout << "The word '" << key << "' was not found in the dictionary!" << endl;
        return count;

    // If the word we are looking for is in the left subtree
    if (key < root->key)
        // Move on to the left subtree
        return findWord(root->left, key, count++);
    // If the word we are looking for is in the right subtree
    else if (key > root->key)
        // Move on to the right subtree
        return findWord(root->right, key, count++);
    // Otherwise, the word must be found
    else
        return count;
}

/*
Public part of the findWord method. The time it takes to find the word is recorded and
    displayed to the user. Calls the private findWord method.

Inputs:
    string s: The string you are looking for
    int count: The number of executions executed (default = 1)

Outputs:
    int: The number of executions executed
*/
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

    // Return the number of comparisons executed
    return numOfComparisions;
}

/*
Private part of the getHeight method. Finds the height of the tree recursively.

Inputs:
    Node* root: The top Node object of the BST subtree

Outputs:
    int: The height of the BST
*/
int BST::getHeightHelper(Node* root) {
    // If the tree is empty, return 0
    if (root == nullptr)
        return 0;

    // Get the height of the left subtree
    int leftHeight = getHeightHelper(root->left);
    // Get the height of the right subtree
    int rightHeight = getHeightHelper(root->right);

    // Return the greater vaue of the two subtrees
    return max(leftHeight, rightHeight) + 1;
}

/*
Public part of the getHeight method. Calls the getHeightHelper method.

Inputs: None

Outputs:
    int: The height of the BST
*/
int BST::getHeight() {
    return getHeightHelper(root);
}

/*
Gets the word that is on top of the BST (what the root node is)

Inputs: None

Outputs:
    string: The key value of the root node
*/
string BST::getTopWord() {
    // If the BST is empty, let the user know
    if (root == nullptr) {
        cerr << "Error: Tree is empty." << endl;
        return "";
    }
    // Return the key value of the root node
    return this->root->key;
}
