#include "1_1.h"

void test1_1()
{
	int toStop = 0;

	while (toStop != 1)
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

		cout << "To stop enter 1" << endl;
		cin >> toStop;
	}
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