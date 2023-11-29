/*
Author: Will Augustine
Assignment: CSCI 232 Lab 7
File: AVL.cpp

The implementation file for the AVL class
*/

#include "AVL.h"

// Parameterized constructor to build AVL tree from a file
AVL::AVL(string filename) : root(nullptr) {
    // Record start time for beginning of the action
    auto start = high_resolution_clock::now();

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string word;
    while (file >> word) {
        insert(word);
    }

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

// Helper function to get the height of a node
int AVL::getHeight(Node* n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

// Helper function to get the balance factor of a node
int AVL::getBalanceFactor(Node* n) {
    if (n == nullptr)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Helper function to perform a left rotation
AVL::Node* AVL::leftRotate(Node* n) {
    Node* newRoot = n->right;
    n->right = newRoot->left;
    newRoot->left = n;
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

// Helper function to perform a right rotation
AVL::Node* AVL::rightRotate(Node* n) {
    Node* newRoot = n->left;
    n->left = newRoot->right;
    newRoot->right = n;
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

// Helper function to insert a node into the AVL tree
AVL::Node* AVL::insert(Node* root, string key) {
    if (root == nullptr)
        return new Node{ key, nullptr, nullptr, 1 };

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys not allowed

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor to check if rotation is needed
    int balance = getBalanceFactor(root);

    // Left Heavy
    if (balance > 1) {
        if (key < root->left->key) {
            return rightRotate(root);
        }
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (key > root->right->key) {
            return leftRotate(root);
        }
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Public function to insert a string into the AVL tree
void AVL::insert(string s) {
    root = insert(root, s);
}

// Helper function to find a word in the AVL tree
int AVL::findWord(Node* root, string s, int count) {
    if (root == nullptr)
        return count; // Word not found

    if (s < root->key)
        return findWord(root->left, s, count + 1);
    else if (s > root->key)
        return findWord(root->right, s, count + 1);
    else
        return count; // Word found
}

// Public function to find a word in the AVL tree
int AVL::findWord(string s, int count) {
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

string AVL::getTopWord()
{
    return this->root->key;
}
