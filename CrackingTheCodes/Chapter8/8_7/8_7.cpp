#include "8_7.h"

// Permutations without Dups
void test8_7()
{
	string uniChars = "abcde";
	vector<string> permutations = permutationsWithoutDups(uniChars);

	cout << "Counts of result = " << permutations.size() << endl;
	printVectorString(permutations);
}

vector<string> permutationsWithoutDups(string uniChars)
{
	vector<string> permutations;
	getPermutation(permutations, uniChars, "");

	return permutations;
}

void getPermutation(vector<string>& permutations, string uniChars, string thisPermutation)
{
	if (uniChars.length() == 0)
	{
		permutations.push_back(thisPermutation);
		return;
	}

	for(char& c : uniChars)
	{
		string curS = uniChars;
		curS.erase(remove(curS.begin(), curS.end(), c), curS.end());
		string nextPermutation = thisPermutation;
		nextPermutation += c;
		getPermutation(permutations, curS, nextPermutation);
	}
}