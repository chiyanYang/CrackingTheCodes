#include "1_1.h"

// Is Unique
void test1_1()
{
	string stringLength;
	cout << "Set the length of the string" << endl;

	while (true)
	{
		getline(cin >> ws, stringLength); // cin >> ws is to remove white space / new line from last input that cause getline to return
		if (is_number(stringLength))
			break;
		cout << "Not a number, reEnter please" << endl;
	}

	cout << "Generating the string" << endl;

	string testString = generateTestString(atoi(stringLength.c_str()));
	cout << "The random string is" << endl << testString << endl;
	bool result = isUnique_ASCII(testString);

	cout << "The unique result = " << result << endl << endl;

	string tmpTestString = testString;
	mergeSort(tmpTestString, 0, tmpTestString.size() - 1);

	cout << "The sorted string is" << endl << tmpTestString << endl;


	result = isUnique_ASCII_SortedString(tmpTestString);
	cout << "The unique result for sorted string = " << result << endl << endl;

	tmpTestString = testString;
	mergeSortInplace(tmpTestString, 0, tmpTestString.size() - 1);

	cout << "The sorted in place string is" << endl << tmpTestString << endl;

	result = isUnique_ASCII_SortedString(tmpTestString);
	cout << "The unique result for sorted in place string = " << result << endl << endl;

	string sAlphabet = generateTestStringInAlphabet(atoi(stringLength.c_str()));
	cout << "The alphabet string is" << endl << sAlphabet << endl;
	result = isUnique_Alphabet_Int(sAlphabet);

	cout << "The unique result for isUnique_Alphabet_Int = " << result << endl << endl;
}

// 1. Assume AscII code char only, extention not included
// 2. AscII code char / symbol start from 33 ~ 126
bool isUnique_ASCII(const string& s)
{
	if (s.length() > 94) // AscII code char / symbol start from 33 ~ 126. The amount of char / symbol is 94
		return false;

	bool totalChar[256] = { false };
	for (auto c : s) // bytes(char)
	{
		if (totalChar[c] != false)
			return false;
		totalChar[c] = true;
	}
	return true;
}

// Assume Alphabet char only(a~z)
bool isUnique_Alphabet_Int(const string& s)
{
	if (s.length() > 26) // a~z has 26 char
		return false;

	int bitVector = 0;
	for (auto c : s) // bytes(char)
	{
		int locInBitVector = c - 'a';
		int valueInInt = 1 << locInBitVector;

		if ((bitVector & valueInInt) != 0)
			return false;

		bitVector |= valueInInt;
	}
	return true;
}

bool isUnique_ASCII_SortedString(const string& s)
{
	if (s.length() == 0 || s.length() == 1)
		return true;

	char pre = s.at(0);
	for (auto it = s.cbegin() + 1; it != s.cend(); ++it)
	{
		if (pre == *it)
			return false;

		pre = *it;
	}
	return true;
}

void mergeSort(string& s, int begin, int end)
{
	if (s.length() == 0 || s.length() == 1)
		return;

	if (end == begin)
		return;

	int middle = (begin + end) / 2;
	mergeSort(s, begin, middle);
	mergeSort(s, middle + 1, end);

	int size = end - begin + 1;

	char* pFirst = &s[begin];
	char* pSecond = &s[middle + 1];
	char* pFirstEnd = pSecond - 1;
	char* pSecondEnd = pFirst + size - 1;

	
	char* tmp = new char[size];
	
	for (int i = 0; i < size; i ++)
	{
		if (pFirst > pFirstEnd)
		{
			tmp[i] = *pSecond;
			pSecond++;
		}
		else if (pSecond > pSecondEnd)
		{
			tmp[i] = *pFirst;
			pFirst++;
		}
		else if (*pFirst <= *pSecond)
		{
			tmp[i] = *pFirst;
			pFirst++;
		}
		else 
		{
			tmp[i] = *pSecond;
			pSecond++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		s[i + begin] = tmp[i];
	}

	free(tmp);
}

void mergeSortInplace(string& s, int begin, int end)
{
	if (s.length() == 0 || s.length() == 1)
		return;

	if (begin == end)
		return;

	int middle = begin + (end - begin) / 2;
	mergeSortInplace(s, begin, middle);
	mergeSortInplace(s, middle + 1, end);

	mergeTwoParts(s, begin, middle + 1, end);
}

void mergeTwoParts(string& s, int first, int second, int end)
{
	int firstEnd = second - 1;

	while (first < second && second <= end)
	{
		if (s[first] <= s[second])
		{
			first++;
		}
		else if (s[first] > s[second])
		{
			int tmp = s[second];

			int index = second;
			while (index - 1 >= first)
			{
				s[index] = s[index - 1];
				index--;
			}

			s[first] = tmp;
		}
	}

}
