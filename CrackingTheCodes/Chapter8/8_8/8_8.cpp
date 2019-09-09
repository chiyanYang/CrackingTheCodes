#include "8_8.h"

// Permutations with Dups
void test8_8()
{
	string dupChars = "abbccde";
	vector<string> permutations = permutationsWithDups(dupChars);

	cout << "Counts of result = " << permutations.size() << endl;
	printVectorString(permutations);
}

vector<string> permutationsWithDups(string dupChars)
{
	vector<string> permutations;
	map<char, int> charCountMap;
	buildMapOfCharCount(charCountMap, dupChars);
	getPermutation(permutations, charCountMap, dupChars.length(), "");

	return permutations;
}

void getPermutation(vector<string>& permutations, map<char, int>& charCountMap, int length, string prefix)
{
	if (length == 0)
	{
		permutations.push_back(prefix);
		return;
	}

	for (auto& charCount : charCountMap)
	{
		if (charCount.second != 0)
		{
			char c = charCount.first;
			charCount.second--;
			string nextPrefix = prefix;
			nextPrefix += c;
			getPermutation(permutations, charCountMap, length - 1, nextPrefix);
			charCount.second++;
		}
	}
}

void buildMapOfCharCount(map<char, int>& charCountMap, string dupChars)
{
	for (char& c : dupChars)
	{
		if (charCountMap.find(c) != charCountMap.end())
		{
			charCountMap[c]++;
		}
		else
		{
			charCountMap[c] = 1;
		}
	}
}