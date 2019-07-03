#include "1_3.h"

// URLify
void test1_3()
{
	int toStop = 0;

	string s1 = "Mr John Smith    ";

	cout << "Input string" << endl << s1 << endl;
	urLify(s1);

	cout << "Output string" << endl << s1 << endl;

	cin >> toStop;
}

// Move the char to the end of the string one by one, encounter a while space then replace it with %20.
void urLify(string& s1)
{
	string whitespaces(" ");
	size_t found = s1.find_last_not_of(whitespaces);

	for (auto rit = s1.rbegin(); rit != s1.rend(); ++rit)
	{
		if (s1[found] != ' ')
		{
			swap(*rit, s1[found]);
		}
		else
		{
			*rit = '0';
			*rit++;
			*rit = '2';
			*rit++;
			*rit = '%';
		}
		found--;
	}
}
