#include "1_4.h"

// Palindrome Permutation
void test1_4()
{
	int result;

	string s1 = "Tact Coa";

	cout << "Input string" << endl << s1 << endl;
	result = isPalindrome_BitVector(s1);

	cout << "is Palindrome: " << result << endl << endl;

	int length;

	cout << "Enter the length: ";
	cin >> length;

	string s2 = generateTestStringInAlphabet(length);

	cout << "Generated string = " << s2 << endl;

	result = isPalindrome_BitVector(s2);

	cout << "is Palindrome: " << result << endl << endl;

}

// Assume only a to z
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

	if (getNonPair(c, 26) <= 1)
	{
		return true;
	}
	
	return false;
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

// Assume only a to z
// Reduced array check, but not necessary faster because using modular.
bool isPalindromeReducedArrayCheck(string& s)
{
	char c[26] = { 0 };
	int oddCounts = 0;

	transform(s.begin(), s.end(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), isspace), s.end());

	for (auto it = s.begin(); it != s.end(); ++it)
	{
		int index = *it - 'a';
		c[index] += 1;

		if (c[index] % 2 == 0)
		{
			oddCounts--;
		} 
		else
		{
			oddCounts++;
		}
	}

	if (oddCounts <= 1)
	{
		return true;
	}

	return false;
}

// Assume only a to z
// Use bit vector
bool isPalindrome_BitVector(string& s)
{
	int bitVector = 0;

	transform(s.begin(), s.end(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), isspace), s.end());

	for (auto it = s.begin(); it != s.end(); ++it)
	{
		int locInBitVector = *it - 'a';
		int valueInInt = 1 << locInBitVector;

		if ((bitVector & valueInInt) == 0)
		{
			// loc is 0, change to 1
			bitVector |= valueInInt;
		}
		else 
		{
			// loc is 1, change to 0
			bitVector &= ~valueInInt;
		}
	}

	if (bitVector == 0) // even times of all chars
	{
		return true;
	}

	if ((bitVector & (bitVector - 1)) == 0) // only one odd times of all chars
	{
		return true;
	}

	return false;
}