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

using namespace std;

using namespace chrono;

class AVL
{
private:
    struct Node
    {
        string key;
        Node* left;
        Node* right;
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
    // Default constructor
    AVL(string filename);

    // Public function to insert a string into the AVL tree
    void insert(string s);

    // Public function to find a word in the AVL tree
    int findWord(string s, int count = 1);

    // Public function to return the word on the top of the AVL tree
    string getTopWord();
};
