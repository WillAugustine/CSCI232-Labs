#include <iostream>
#include <string>

using namespace std;

string word = "racecar";
int length = word.length();

char* originalStack = new char[length];
int originalHead = -1;

char* reverseStack = new char[length];
int reverseHead = -1;

void createStack(string word)
{
	for (int i = 0; i < length; i++)
	{
		originalStack[i] = word[i];
	}
	originalHead = length - 1;
}

void createReversedStack(string word)
{
	int tempOriginalHead = originalHead;
	while (tempOriginalHead >= 0)
	{
		reverseHead++;
		reverseStack[reverseHead] = originalStack[tempOriginalHead];
		tempOriginalHead--;
	}
}

bool isPalindrome(string word)
{
	createStack(word);
	createReversedStack(word);
	for (int i = 0; i < length; i++)
	{
		if (originalStack[i] != reverseStack[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << "Is '" << word << "' a palindrome? " << boolalpha << isPalindrome(word);
}

