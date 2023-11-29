/*
Author: Will Augustine
Assignment: CSCI 232 Lab 7
File: BST.h

The header file for the BST class
*/

#include <string>
#include <fstream>
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

// The BST class
class BST
{
// Variables and methods to be accessed only by the BST class
private:
    // Struct that represents a node in the tree
    struct Node
    {
        // The data of a node
        string key;
        // The child node to the left
        Node* left;
        // The child node to the right
        Node* right;
    };

    // The top of the BST tree
    Node* root;

    // Helper function to insert a node into the BST tree
    Node* insert(Node* root, string key);

    // Helper function to find a word in the BST tree
    int findWord(Node* root, string key, int count);

    // Helper function to calculate the height of the BST
    int getHeightHelper(Node* root);

// Variables and methods to be used by external methods
public:
    // Parameterized constructor for BST class
    BST(string filename);

    // Inserts a string into the BST tree
    void insert(string s);

    // Trys to find the inputted in the BST tree
    int findWord(string s, int count = 1);

    // Returns the height of the BST
    int getHeight();

    // Return the word on the top of the BST tree
    string getTopWord();
};
