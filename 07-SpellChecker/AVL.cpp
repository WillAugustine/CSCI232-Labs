/*
Author: Will Augustine
Assignment: CSCI 232 Lab 7
File: AVL.cpp

The implementation file for the AVL class
*/

#include "AVL.h"

/*
Parameterized constructor for the AVL class. Takes the words from the inputted file and
    puts them into the AVL tree

Inputs: 
    string filename: The file that contains all of the words to be added to the AVL tree

Outputs: None
*/
AVL::AVL(string filename) : root(nullptr) {
    // Record start time for beginning of the action
    auto start = high_resolution_clock::now();

    // Try to open the file
    ifstream file(filename);

    // If the file could not open, let the user know
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Variable to store the current word (one word per line) in the inputted file
    string word;

    // While not at the end of the file
    while (file >> word) {
        insert(word);
    }

    // Close the file
    file.close();

    // Record stop time for end of action
    auto stop = high_resolution_clock::now();

    // Calculate duration of action in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Convert duration to seconds
    auto seconds = duration / 1000000;

    // Let the user know the execution time
    cout << "\tAVL read the file in " << duration.count() << " microseconds (" << seconds.count() << " seconds)." << endl;
}

/*
Gets the height of the inputted node

Inputs:
    Node* n: The node you want to find the height of

Outputs:
    int: The height of the inputted node
*/
int AVL::getHeight(Node* n) {
    // If the inputted node is null, return 0
    if (n == nullptr)
    {
        return 0;
    }
    // Return the height of the node
    return n->height;
}

/*
Gets the balance factor of the inputted node which is the height of the left subtree
    minus the height of the right subtree

Inputs:
    Node* n: The node you want to find the height of

Outputs:
    int: The calculated balance factor
*/
int AVL::getBalanceFactor(Node* n)
{
    // If the inputted node is null, return 0
    if (n == nullptr)
        return 0;
    // Calculate the difference between the left and right subtrees
    return getHeight(n->left) - getHeight(n->right);
}

/*
Rotates the subtree to the left where the inputted node is the root of the subtree

Inputs:
    Node* n: The root node of the subtree you want to rotate

Outputs:
    Node*: The new root node of the rotated subtree
*/
AVL::Node* AVL::leftRotate(Node* n) {
    // Set the new root of the subtree as the right child node
    Node* newRoot = n->right;
    // Update the inputted root node's right child node
    n->right = newRoot->left;
    // Update the new root's left child node to the inputted root node
    newRoot->left = n;
    // Update the height of the old subtree root
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    // Update the height of the new subtree root
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    // Return the new subtree root
    return newRoot;
}

/*
Rotates the subtree to the right where the inputted node is the root of the subtree

Inputs:
    Node* n: The root node of the subtree you want to rotate

Outputs:
    Node*: The new root node of the rotated subtree
*/
AVL::Node* AVL::rightRotate(Node* n) {
    // Set the new root of the subtree as the left child node
    Node* newRoot = n->left;
    // Update the inputted root node's left child node
    n->left = newRoot->right;
    // Update the new root's right child node to the inputted root node
    newRoot->right = n;
    // Update the height of the old subtree root
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    // Update the height of the new subtree root
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    // Return the new subtree root
    return newRoot;
}

/*
The private part of the insert method. Inserts the inputted key as a node into the AVL 
    tree in the correct position and balances it at the end

Inputs:
    Node* root: The root node of the AVL tree
    string key: The string you want to add to the AVL tree

Outputs:
    Node*: The new root node of AVL tree
*/
AVL::Node* AVL::insert(Node* root, string key)
{
    // If the AVL tree is empty, create the new node and add it to the top of the tree
    if (root == nullptr)
    {
        return new Node{ key, nullptr, nullptr, 1 };
    }
    // If the new word should go in the left subtree
    if (key < root->key)
    {
        // Move to the left subtree
        root->left = insert(root->left, key);
    }
    // If the new word should go in the right subtree
    else if (key > root->key)
    {
        // Move to the right subtree
        root->right = insert(root->right, key);
    }
    // If the string is already in the AVL tree
    else
    {
        // Stop without adding the node to the AVL tree
        return root;
    }

    // Set the updated root height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor to check if rotation is needed
    int balance = getBalanceFactor(root);

    // If the AVL tree is left heavy, rotate to balance the AVL tree
    if (balance > 1) {
        if (key < root->left->key) {
            return rightRotate(root);
        }
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // If the AVL tree is right heavy, rotate to balance the AVL tree
    if (balance < -1) {
        if (key > root->right->key) {
            return leftRotate(root);
        }
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    // Return the new root node of the AVL tree
    return root;
}

/*
The public part of the insert method. Inserts the inputted key as a node into the AVL
    tree by calling the private insert method.

Inputs:
    string s: The string you want to add to the AVL tree

Outputs: None
*/
void AVL::insert(string s) {
    // Update the root node of the AVL tree
    root = insert(root, s);
}

/*
The private part of the findWord method. Recursively tries to find the inputted word in 
    the AVL tree, counting the number of executions that are conducted.

Inputs:
    Node* root: The root node of the AVL subtree
    string s: The string you are looking for in the AVL tree
    int count: The number of comparisons conducted (default = 1)

Outputs:
    int: The number of comparisons performed before the word was found
*/
int AVL::findWord(Node* root, string s, int count)
{
    // If the end of the AVL tree has been reached, let the user know
    if (root == nullptr)
    {
        cout << "The word '" << s << "' was not found in the AVL tree" << endl;
        return count;
    }

    // If the word should be in the left subtree
    if (s < root->key)
    {
        // Move to the left subtree
        return findWord(root->left, s, count + 1);
    }
    // If the word should be in the right subtree
    else if (s > root->key)
    {
        // Move to the right subtree
        return findWord(root->right, s, count + 1);
    }
    // Otherwise, the word must have been found
    else
    {
        // Return the number of comparisons it took to find the word
        return count;
    }
}

/*
Public part of the findWord method. The time it takes to find the word is recorded and
    displayed to the user. Calls the private findWord method.

Inputs:
    string s: The string you are looking for
    int count: The number of comparisons executed (default = 1)

Outputs:
    int: The number of comparisons executed
*/
int AVL::findWord(string s, int count) {
    // Record start time for beginning of the action
    auto start = high_resolution_clock::now();

    // Call the private findWord method and get the number of comparisons executed
    int numOfComparisions = findWord(root, s, count);

    // Record stop time for end of action
    auto stop = high_resolution_clock::now();

    // Calculate duration of action in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Convert duration to seconds
    auto seconds = duration / 1000000;

    // Let the user know the execution time
    cout << "\tFound the word in " << duration.count() << " microseconds (" << seconds.count() << " seconds)." << endl;

    // Return the number of comparisons executed before the word was found
    return numOfComparisions;
}

/*
The public part of the getHeight method. Returns the height of the AVL tree by passing
    in the root node into the private getHeight method.

Inputs: None

Outputs:
    int: The height of the AVL tree
*/
int AVL::getHeight()
{
    // Pass the root node into the private getHeight method and return the value
    return getHeight(root);
}

/*
Gets the top word of the AVL tree, or what the root node represents

Inputs: None

Outputs:
    string: The value of the root node
*/
string AVL::getTopWord()
{
    return this->root->key;
}
