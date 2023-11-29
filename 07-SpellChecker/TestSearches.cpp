/*
Author: Will Augustine
File: TestSearches.cpp

Test code for the BinarySearch class, BST class, and the AVL class
*/

#include "BinarySearch.h"
#include "BST.h"
#include "AVL.h"

int main()
{
	/*
	string fileName = "dictionary10000.txt";
	string firstWord = "a";
	string middleWord = "languages";
	string lastWord = "zus";
	string randomWord = "programmer";
	*/

	string fileName = "dictionary1400.txt";
	string firstWord = "a";
	string middleWord = "avenue";
	string lastWord = "catalogs";
	string randomWord = "arkansas";


	cout << "\n\n------ TESTING READING FILE ------" << endl;

	BinarySearch readingFile(fileName);
	readingFile.printDictionary();

	cout << "\n\n------ TESTING BinarySearch ------" << endl;

	cout << "Creating BinarySearch object" << endl;
	BinarySearch binarySearch(fileName);

	cout << "Here is the dictionary:" << endl;
	binarySearch.printDictionaryWithTimer();

	cout << "Searching for the first word in the text file (" << firstWord << ")" << endl;
	cout << "\tIt took " << binarySearch.findWord(firstWord) << " comparisions to find the word!" << endl;

	cout << "Searching for the middle word in the text file (" << middleWord << ")" << endl;
	cout << "\tIt took " << binarySearch.findWord(middleWord) << " comparisions to find the word!" << endl;

	cout << "Searching for the last word in the text file (" << lastWord << ")" << endl;
	cout << "\tIt took " << binarySearch.findWord(lastWord) << " comparisions to find the word!" << endl;

	cout << "Searching for a randomly selected word in the text file (" << randomWord << ")" << endl;
	cout << "\tIt took " << binarySearch.findWord(randomWord) << " comparisions to find the word!" << endl;


	cout << "\n\n------ TESTING BST ------" << endl;

	cout << "Creating BST object" << endl;
	BST bst(fileName);

	string topWord = bst.getTopWord();
	cout << "\tThe top word on the tree is '" << topWord << "'" << endl;
	cout << "Searching for the top word in the tree (" << topWord << ")" << endl;
	cout << "\tIt took " << bst.findWord(topWord) << " comparisions to find the word!" << endl;

	cout << "Searching for the first word in the text file (" << firstWord << ")" << endl;
	cout << "\tIt took " << bst.findWord(firstWord) << " comparisions to find the word!" << endl;

	cout << "Searching for the middle word in the text file (" << middleWord << ")" << endl;
	cout << "\tIt took " << bst.findWord(middleWord) << " comparisions to find the word!" << endl;

	cout << "Searching for the last word in the text file (" << lastWord << ")" << endl;
	cout << "\tIt took " << bst.findWord(lastWord) << " comparisions to find the word!" << endl;

	cout << "Searching for a randomly selected word in the text file (" << randomWord << ")" << endl;
	cout << "\tIt took " << bst.findWord(randomWord) << " comparisions to find the word!" << endl;

	cout << "\n\n------ TESTING AVL ------" << endl;

	cout << "Creating AVL object" << endl;
	AVL avl(fileName);

	topWord = avl.getTopWord();
	cout << "\tThe top word on the tree is '" << topWord << "'" << endl;
	cout << "Searching for the top word in the tree (" << topWord << ")" << endl;
	cout << "\tIt took " << avl.findWord(topWord) << " comparisions to find the word!" << endl;

	cout << "Searching for the first word in the text file (" << firstWord << ")" << endl;
	cout << "\tIt took " << avl.findWord(firstWord) << " comparisions to find the word!" << endl;

	cout << "Searching for the middle word in the text file (" << middleWord << ")" << endl;
	cout << "\tIt took " << avl.findWord(middleWord) << " comparisions to find the word!" << endl;

	cout << "Searching for the last word in the text file (" << lastWord << ")" << endl;
	cout << "\tIt took " << avl.findWord(lastWord) << " comparisions to find the word!" << endl;

	cout << "Searching for a randomly selected word in the text file (" << randomWord << ")" << endl;
	cout << "\tIt took " << avl.findWord(randomWord) << " comparisions to find the word!" << endl;
}