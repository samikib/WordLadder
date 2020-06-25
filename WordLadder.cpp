#include "WordLadder.h"

WordLadder::WordLadder(const string& inputFile)
{
	std::ifstream inFile;
	string words;
	try
	{
		inFile.open(inputFile);
		if (!inFile.is_open())
		{
			throw inputFile;
		}

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

		makeLadder(start, end, ladder);

		if (ladder.empty())
		{
			throw ladder;
		}

		reverseStack(ladder, orderedLadder);


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
	queue<stack<string>> ladders;
	string topWordFront;

	words.push(start);
	ladders.push(words);
	try
	{
		if (start == end)
		{
			compLadder = words;
			return;
		}

		while (!ladders.empty())
		{
			
			topWordFront = ladders.front().top();
			list<string>::iterator i = dict.begin();
			while (i != dict.end())
			{
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
					i = dict.erase(i);

				}
				else
				{
					i++;
				}
			}

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

void WordLadder::reverseStack(stack<string> og, stack<string>& rev)
{
	while (!og.empty())
	{
		rev.push(og.top());
		og.pop();
	}
}