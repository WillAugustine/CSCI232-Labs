// -----------------------------------------------------------------------------
// CSCI 232 Data Structures
// Programming Lab Assignment 7
// Assignment Parts 4, 5, and 6
// File Name: BST.cpp
// Author: Jason Decker
// 
// Description: C++ file to define the functions of the binary search tree (BST) class 
//	Part 4: Implement a Binary Search Tree. Read the text file into the tree.
//  Part 5:	Measure the execution time of finding words in the tree.
//  Part 6: Count the number of levels of the BST.
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

using namespace chrono;

#pragma once

class BST {

	struct node {
		string data;
		node* left;
		node* right;
	};

	int maxLevel = 0;

	node* root;

	node* insert(string s, node* t) {
		
		if (t == NULL) {
			t = new node;
			t->data = s;
			t->left = t->right = NULL;
			//if (maxLevel < level) {
			//	maxLevel = level;
			//}
			//cout << level;
		}
		else if (s < t->data) {
			t->left = insert(s, t->left);
			//cout << level;
		}
		else if (s > t->data) {
			t->right = insert(s, t->right);
			//cout << level;
		}
		return t;
	}


	/*
	node* findMin(node* t) {
		if (t == NULL) {
			return NULL;
		}
		else if (t->left == NULL) {
			return t;
		}
		else
			return findMin(t->left);
	}

	node* findMax(node* t) {
		if (t == NULL) {
			return NULL;
		}
		else if (t->right == NULL) {
			return t;
		}
		else
			return findMax(t->right);
	}
	
	node* remove(string s, node* t) {
		node* temp;
		if (t == NULL)
			return NULL;
		else if (s < t->data)
			t->left = remove(s, t->left);
		else if (s > t->data)
			t->right = remove(s, t->right);
		else if (t->left and t->right) {
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data, t->right);
		}
		else {
			temp = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			delete temp;
		}
		return t;
	}
	*/
	void inorder(node* t) {
		if (t == NULL)
			return;
		inorder(t->left);
		cout << t->data << " " << endl;
		inorder(t->right);
	}
	
	node* find(node* t, string s) {
		if (t == NULL)
			return NULL;
		else if (s < t->data)
			return find(t->left, s);
		else if (s > t->data)
			return find(t->right, s);
		else
			return t;
	}

public:
	BST() { // Create an empty BST
		root = NULL;
	}


	bool isEmpty() {
		if (root == NULL) {
			return true;
		}
		return false;
	}

	void insert(string s, int level = 10) {
		root = insert(s, root);
		if (maxLevel < level) {
			maxLevel = level;
		}
		level++;
	}
	/*
	void remove(string s) {
		root = remove(s, root);
	}
	*/
	void display() {

		// Record start time for printing the BST
		auto startPrintBST = high_resolution_clock::now();

		inorder(root);

		cout << endl;
		
		// Record stop time for printing the BST
		auto stopPrintBST = high_resolution_clock::now();

		// Calculate duration of printing the BST in microseconds
		auto durationPrintBST = duration_cast<microseconds>(stopPrintBST - startPrintBST);

		// Calculate duration of printing the BST in seconds
		auto printSeconds = durationPrintBST / 1000000;

		// Output the time for printing the BST
		cout << "The BST was printed in " << durationPrintBST.count() << " microseconds (" << printSeconds.count() << " seconds)." << endl;
	}

	void search(string s) {

		// Record start time for finding the word
		auto start = high_resolution_clock::now();

		root = find(root, s);
		
		// Record stop time for finding the word
		auto stop = high_resolution_clock::now();

		// Calculate the duration of finding the word
		auto duration = duration_cast<microseconds>(stop - start);

		// Calculate duration of finding the word in seconds
		auto durationSeconds = duration_cast<seconds>(stop - start);

		if (root == NULL) // Output the time to finde a word that doesn't exist
			cout << "The word '" << s << "' does not exist. The search was completed in "
				<< duration.count() << " micorseconds (" << durationSeconds.count() << " seconds)." << endl;
		else // Output the time to find the word
			cout << "The word '" << s << "' was found in " << duration.count() << " microseconds (" << durationSeconds.count() << " seconds)." << endl;
	}
	int getMaxLevel() {
		cout << "The total number of levels for the BST is " << maxLevel << endl;
		return maxLevel;
	}
};

	int main() {

		BST a; // Create and empty binary search tree

		string myArray[1600]; // Create an array to read in the text file

		ifstream file("dictionary1600.txt"); // Input stream to operate on file

		// Record start time for reading in the text file
		auto start = high_resolution_clock::now();

		// Statement to read in the words from the text file
		if (file.is_open()) {

			// Record start time for building the BST
			auto startBuildBST = high_resolution_clock::now();

			for (int i = 0; i < 1600; ++i) { // for loop to add each word
				file >> myArray[i]; // Add each word to the array
				a.insert(myArray[i]); // Add each word to the BST
			}

			// Record stop time for  reading in the text file and building the BST
			auto stopBuildBST = high_resolution_clock::now();
			auto stop = stopBuildBST;

			// Calculate duration of reading in the text file in microseconds
			auto totalduration = duration_cast<microseconds>(stop - start);

			// Calculate duration of reading in the text file in seconds
			auto durationSeconds = totalduration / 1000000;

			// Calculate time for building the BST in microseconds
			auto durationBuildBST = duration_cast<microseconds>(stopBuildBST - startBuildBST);

			// Calculate time for building the BST in seconds
			auto buildSeconds = durationBuildBST / 1000000;

			// Output the time for reading in the text file
			cout << "The text file was read in " << totalduration.count() << " microseconds (" << durationSeconds.count() << " seconds)." << endl;

			// Output the time for building the BST
			cout << "The BST was built in " << durationBuildBST.count() << " microseconds (" << buildSeconds.count() << " seconds)." << endl;
		}

		//a.display(); // Print the BST

		BST ci = a; // Create a copy of the BST 'a' called 'ci'
		BST basics = a; // Create a copy of the BST 'a' called 'basics'
		BST zebra = a; // Create a copy of the BST 'a' called  'zebra'

		a.getMaxLevel();

		// Search for the first word in the BST 'a'
		a.search("a");

		// Searth for the last word in the BST 'ci'
		ci.search("ci");

		// Search for the middle word in the BST 'basics'
		basics.search("basics");

		// Searchy for a word that does not exist
		zebra.search("zebra");
	};