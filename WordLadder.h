#ifndef WORDLADDER_H__
#define WORDLADDER_H__

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <stdexcept>
#include <stack>
#include <queue>

using std::list;
using std::string;
using std::cout;
using std::stack;
using std::queue;

//class definitions for WordLadder class
class WordLadder{
private:
	list<string> dict; //dictionary of available 5 letter words
	bool offByOne(string a, string b); //helper function, returns true if 2 string vary by exactly 1 position
	void makeLadder(const string& start, const string& end, stack<string>& compLadder); //builds ladder
	void reverseStack(stack<string> og, stack<string>& rev); // flips a stack
public:
	WordLadder(const string& inputFile); //constructor that fills dictionary based on text file provided by user
	void outputLadder(const string& start, const string& end, const string& outputFile); //given start and end words and output file name provided by user, builds and outputs word ladder
};


#endif // WORDLADDER_H__

