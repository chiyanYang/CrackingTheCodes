#include "Ch1Common.h"

string generateTestString(int limitLengrh)
{
	int rChar;
	string s;

	srand(time(NULL));  // Initialize random number generator.

	for (int i = 0; i < limitLengrh; i++)
	{
		rChar = (rand() % 94) + 33; // AscII code char start from 33 ~ 126
		s.push_back(static_cast<char>(rChar));
	}

	return s;
}

string generateTestStringInAlphabet(int limitLengrh)
{
	int rChar;
	string s;

	srand(time(NULL));  // Initialize random number generator.

	for (int i = 0; i < limitLengrh; i++)
	{
		rChar = (rand() % 26) + 97; // AscII code char a start from 97
		s.push_back(static_cast<char>(rChar));
	}

	return s;
}

// Check the input is number
bool is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

// Helper function to get all the permutation of string s, and return the last one.
string getPermutations(const string& s)
{
	if (s.length() < 2)
		return s;

	vector<string> sVector;
	string tmp = s;

	getPermutation("", tmp, NULL, sVector);

	return sVector.back();
}

void getPermutation(string cur, string sRemain, char chosen, vector<string>& sVector)
{
	if (chosen != NULL)
		cur.push_back(chosen);

	if (sRemain.length() < 2)
	{
		if (sRemain.length() == 1)
			cur.append(sRemain);
		sVector.push_back(cur);
		return;
	}

	for (unsigned int i = 0; i < sRemain.length(); i++)
	{
		char c = sRemain.at(i);
		string s = sRemain;

		getPermutation(cur, s.erase(i, 1), c, sVector);
	}
	return;
}