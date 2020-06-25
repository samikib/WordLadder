#include "WordLadder.h"

//constructor, builds dictionary
WordLadder::WordLadder(const string& inputFile)
{
	//using input file to build dictionary
	std::ifstream inFile;
	string words;
	try
	{
		//checks that input file opens
		inFile.open(inputFile);
		if (!inFile.is_open())
		{
			throw inputFile;
		}

		//while file still has contents to read, push a word to back of list
		while (!inFile.eof())
		{
			inFile >> words;
			if (!inFile.fail())
			{
				if (words.size() == 5)
				{
					dict.push_back(words);
				}
				else
				{
					throw words;
				}
			}
		}
	}
	catch (string errSource)
	{
		cout << "Error reading " << errSource << " from file" << std::endl;
	}

	inFile.close();
}

//output function
void WordLadder::outputLadder(const string& start, const string& end, const string& outputFile)
{
	stack<string> ladder;
	stack<string> orderedLadder;
	std::ofstream outFile;

	try
	{
		outFile.open(outputFile);
		if (!outFile.is_open())
		{
			throw outputFile;
		}

		//builds word ladder and stores in ladder
		makeLadder(start, end, ladder);

		if (ladder.empty())
		{
			throw ladder;
		}

		//flips ladder for output
		reverseStack(ladder, orderedLadder);

		//writes ladder to output file
		while(!orderedLadder.empty())
		{
			outFile << orderedLadder.top() << " ";
			orderedLadder.pop();
		}

	}
	catch (string errSource)
	{
		cout << "Problem writing to " << errSource << std::endl;
	}
	catch (stack<string> emptyLadder)
	{
		outFile << "No Word Ladder Found." << std::endl;
	}

	outFile.close();

}

// helper function: checks that 2 given string vary in exactly 1 location, returns true if strings vary by exactly 1
bool WordLadder::offByOne(string a, string b)
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

//in- start, end
//out- compLadder
void WordLadder::makeLadder(const string& start, const string& end, stack<string>& compLadder)
{
	stack<string> words;
	stack<string> newWords;
	queue<stack<string>> ladders; //stores potential ladders
	string topWordFront;

	//initiallizes the first ladder with the start word
	words.push(start);
	ladders.push(words);
	try
	{

		//checks if start and end words are the same
		if (start == end)
		{
			compLadder = words;
			return;
		}

		//while there are still potential ladders
		while (!ladders.empty())
		{
			topWordFront = ladders.front().top();
			list<string>::iterator i = dict.begin();
			//traverses dictionary
			while (i != dict.end())
			{
				//if dictionary item is off by 1 checks that word is end. if end is reached, stores in final ladder. otherwise, pushes new word to end of stack and adds potential ladder to queue
				if (offByOne(topWordFront, *i))
				{

					newWords = ladders.front();
					newWords.push(*i);
					if (*i == end)
					{

						compLadder = newWords;
						return;
					}

					ladders.push(newWords);

					//removes used words
					i = dict.erase(i);

				}
				else
				{
					i++;
				}
			}
			
			//pops old ladder
			ladders.pop();
		}

		if (ladders.empty())
		{
			throw start;
		}
	}
	catch (string badWord)
	{
		cout<< "Word ladder for " << start << " and " << end << " doesn't exist." << std::endl;
	}
	
}

//helper function, reverses the order of a stack
void WordLadder::reverseStack(stack<string> og, stack<string>& rev)
{
	while (!og.empty())
	{
		rev.push(og.top());
		og.pop();
	}
}