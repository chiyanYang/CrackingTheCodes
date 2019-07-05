#include "1_2.h"

// Check Permutation
void test1_2()
{
	int toStop = 0;

	string s = "abcdef";
	getPermutations(s);

	while (toStop != 1)
	{
		string stringLength1;
		string stringLength2;
		cout << "Set the length of the string" << endl;

		while (true)
		{
			getline(cin >> ws, stringLength1); // cin >> ws is to remove white space / new line from last input that cause getline to return
			if (is_number(stringLength1))
				break;
			cout << "Not a number, reEnter please" << endl;
		}

		cout << "Generating the string" << endl;

		string testString1 = generateTestString(atoi(stringLength1.c_str()));
		cout << "The random string1 is" << endl << testString1 << endl;

		while (true)
		{
			getline(cin >> ws, stringLength2); // cin >> ws is to remove white space / new line from last input that cause getline to return
			if (is_number(stringLength2))
				break;
			cout << "Not a number, reEnter please" << endl;
		}

		cout << "Generating the string" << endl;

		// Random string inteval should be more than 1 sec.
		this_thread::sleep_for(chrono::seconds(1));
		string testString2 = generateTestString(atoi(stringLength2.c_str()));
		cout << "The random string2 is" << endl << testString2 << endl;

		bool result = isPermutation(testString1, testString2);

		cout << "The permutation result = " << result << endl << endl;

		string perS = getPermutations(testString1);
		cout << "The random string1 " << testString1  << endl;
		cout << "The permutation of string1 " << perS << endl;
		result = isPermutation(testString1, perS);
		cout << "The permutation result = " << result << endl << endl;

		cout << "To stop enter 1" << endl;
		cin >> toStop;
	}
}

// Use array to store the amount of each char, and check the two string has equal numbers.
bool isPermutation(string& s1, string& s2)
{
	if (s1.length() != s2.length())
		return false;

	const int length = 128;
	char c[length] = { 0 }; // ASCII Table

	for (auto it = s1.cbegin(); it != s1.cend(); ++it)
		c[*it]++;
	for (auto it = s2.cbegin(); it != s2.cend(); ++it)
	{
		if (c[*it] == 0)
			return false;
		c[*it]--;
	}

	for (int i = 0; i < length; i++)
	{
		if (c[i] != 0)
			return false;
	}

	return true;
}

// Helper function to get all the permutation of string s
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


