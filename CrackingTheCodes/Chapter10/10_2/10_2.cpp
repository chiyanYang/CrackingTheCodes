#include "10_2.h"

// Group Anagrams
void test10_2()
{
	vector<string> sVec1 {"ab", "cde", "abc", "ccc", "edc", "cc", "acb", "bac", "cba", "ccccc" };
	vector<string> sVec2 {"ab", "cde", "abc", "ccc", "edc", "cc", "acb", "bac", "cba", "ccccc" };
	groupAnagrams(sVec1);
	printVecString(sVec1);

	vector<string> result = groupAnagramsByHash(sVec2);

	printVecString(result);
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


vector<string> groupAnagramsByHash(vector<string>& stringVec)
{
	map<pair<int, int>, vector<string>> anagramsMap;

	for (int i = 0; i < stringVec.size(); i++)
	{
		string curS = stringVec[i];
		int score = calculateScore(curS);

		auto curSKey = make_pair(curS.size(), score);

		auto search = anagramsMap.find(curSKey);
		if (search == anagramsMap.end())
		{
			vector<string> initVec;
			anagramsMap[curSKey] = initVec;
		}

		anagramsMap[curSKey].push_back(curS);
	}

	vector<string> result;

	for (auto& it : anagramsMap) 
	{
		result.insert(result.end(), it.second.begin(), it.second.end());
	}

	return result;
}

int calculateScore(string& s)
{
	int result = 0;

	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		result += c;
	}

	return result;
}