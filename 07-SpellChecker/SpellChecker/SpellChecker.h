#pragma once

#include <string>

using namespace std;

class BST
{
	struct node {
		string data;
		node* left;
		node* right;
	};

	node* head;
	BST();
	bool isEmpty();
	void insert(string dataToInsert, node* currNode = NULL);
	void display();
	void search(string s);
	node* find(node* t, string s);


};