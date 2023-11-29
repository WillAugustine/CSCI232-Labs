/*
Author: Will Augustine
Assignment: CSCI 232 Lab 7
File: AVL.h

The header file for the AVL class
*/

#include <string>
#include <fstream>
#include <chrono>
#include <iostream>

// Standard namespace
using namespace std;

// Namespace for keeping track of time
using namespace chrono;

// The AVL class
class AVL
{
// Variables and methods only accessible to the AVL class
private:
    // Struct that represents a node in the tree
    struct Node
    {
        // The node's data
        string key;
        // The child node to the left
        Node* left;
        // The child node to the right
        Node* right;
        // The height of the node
        int height;
    };

    // The top of the AVL tree
    Node* root;

    // Helper function to get the height of a node
    int getHeight(Node* n);

    // Helper function to get the balance factor of a node
    int getBalanceFactor(Node* n);

    // Helper function to perform a left rotation
    Node* leftRotate(Node* n);

    // Helper function to perform a right rotation
    Node* rightRotate(Node* n);

    // Helper function to insert a node into the AVL tree
    Node* insert(Node* root, string key);

    // Helper function to find a word in the AVL tree
    int findWord(Node* root, string key, int count);

public:
    // Constructor that reads in the words from the inputted file
    AVL(string filename);

    // Insert a string into the AVL tree
    void insert(string s);

    // Trys to find a word in the AVL tree
    int findWord(string s, int count = 1);

    // Gets the height of the AVL tree
    int getHeight();

    // Return the word on the top of the AVL tree
    string getTopWord();
};
