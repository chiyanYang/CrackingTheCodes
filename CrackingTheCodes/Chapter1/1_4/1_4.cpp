#include "1_4.h"

// Palindrome Permutation
void test1_4()
{
	int toStop = 0;
	int result;

	string s1 = "Tact Coa";

	cout << "Input string" << endl << s1 << endl;
	result = isPalindrome(s1);

	cout << "is Palindrome: " << result << endl;

	cin >> toStop;
}

// (1) Remove capital and space
// (2) Count the amount of each char
// (3) Judge
bool isPalindrome(string& s)
{
	char c[26] = { 0 };

	transform(s.begin(), s.end(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), isspace), s.end());

	for (auto it = s.begin(); it != s.end(); ++it)
	{
		c[*it - 'a'] += 1;
	}

	if (s.length() % 2 == 0)
	{
		return 0 == getNonPair(c, 26);
	}
	else
	{
		return 1 == getNonPair(c, 26);
	}
}

int getNonPair(char c[], int size)
{
	int nonPairNum = 0;

	for (int i = 0; i < size; i++)
	{
		if (c[i] % 2 != 0)
			nonPairNum++;
	}

	return nonPairNum;
}