#include "WordLadder.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;


//test function. Tests that a pair of strings vary at exactly 1 location
bool offByOne(string a, string b)
{
	int count;
	count = 0;

	for (int i = 0; i < 5; i++)
	{
		if (a[i] != b[i])
		{
			count++;
		}
	}

	if (count == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}



int main() 
{
	*/ dictFile - dictionary file name
	   wordBegin - start word
	   wordEnd - goal word
	   outFile - name of output file /*
	string dictFile, wordBegin, wordEnd, outFile;
	cout << "Enter the name of the dictionary file: ";
	cin >> dictFile;
	cout << endl;
	cout << "Enter the name of the output file: ";
	cin >> outFile;
	cout << endl;
	cout << "Enter the first word: ";
	cin >> wordBegin;
	cout << endl;
	
	//checks that words are of length 5
	while (wordBegin.size() != 5) {
		cout << "Word must have exactly 5 characters." << endl
			<< "Please reenter the first word: ";
		cin >> wordBegin;
		cout << endl;
	}
	cout << "Enter the last word: ";
	cin >> wordEnd;
	cout << endl;

	//checks that words are of length 5
	while (wordEnd.size() != 5) {
		cout << "Word must have exactly 5 characters." << endl
			<< "Please reenter the last word: ";
		cin >> wordEnd;
		cout << endl;
	}
	
	//generates ladder and outputs to txt file
	WordLadder wl(dictFile);
	wl.outputLadder(wordBegin, wordEnd, outFile);

	return 0;
}

