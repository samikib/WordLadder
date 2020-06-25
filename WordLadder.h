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

class WordLadder{
private:
	list<string> dict;
	bool offByOne(string a, string b);
	void makeLadder(const string& start, const string& end, stack<string>& compLadder);
	void reverseStack(stack<string> og, stack<string>& rev);
public:
	WordLadder(const string& inputFile);
	void outputLadder(const string& start, const string& end, const string& outputFile);
};


#endif // WORDLADDER_H__

