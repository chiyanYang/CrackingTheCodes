#include "10_2.h"

// Group Anagrams
void test10_2()
{
	vector<string> sVec {"ab", "cde", "abc", "ccc", "edc", "cc", "acb", "bac", "cba", "ccccc" };
	groupAnagrams(sVec);
	printVecString(sVec);
}

void groupAnagrams(vector<string>& stringVec)
{
	sort(stringVec.begin(), stringVec.end(), compareAnagrams);
}

bool compareAnagrams(string s1, string s2)
{
	sortString(s1);
	sortString(s2);

	return s1 < s2;
}

void sortString(string& s)
{
	sort(s.begin(), s.end());
}

void printVecString(vector<string> sVec)
{
	for (int i = 0; i < sVec.size(); i++)
	{
		cout << sVec[i] << " ";
	}

	cout << endl;
}