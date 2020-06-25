#include "WordLadder.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

/*bool offByOne(string a, string b)
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

int main1()
{
	bool test = false;

	test = offByOne("hello", "hella");
	test = offByOne("hello", "yello");
	test = offByOne("hello", "hello");
	test = offByOne("hello", "hallo");
	test = offByOne("hello", "today");
	test = offByOne("hello", "yelpo");

	return 0;
}

int main()
{
	WordLadder wl("dictionary.txt");

	wl.outputLadder("reads", "brats", "out.txt");

	return 0;
}
*/




int main() 
{
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
	while (wordBegin.size() != 5) {
		cout << "Word must have exactly 5 characters." << endl
			<< "Please reenter the first word: ";
		cin >> wordBegin;
		cout << endl;
	}
	cout << "Enter the last word: ";
	cin >> wordEnd;
	cout << endl;
	while (wordEnd.size() != 5) {
		cout << "Word must have exactly 5 characters." << endl
			<< "Please reenter the last word: ";
		cin >> wordEnd;
		cout << endl;
	}

	WordLadder wl(dictFile);

	wl.outputLadder(wordBegin, wordEnd, outFile);

	return 0;
}

