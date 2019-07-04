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

// Check the input is number
bool is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
