#include "1_5.h"

// One Away
void test1_5()
{
	int toStop = 0;
	int result;

	string s1 = "ale";
	string s2 = "pale";

	cout << "Input string" << endl << s1 << endl;
	cout << "Input string" << endl << s2 << endl;
	result = isOneWay(s1, s2);

	cout << "Is One Way: " << result << endl;

	cin >> toStop;
}

bool isOneWay(string& s1, string& s2)
{
	if (s1.length() == s2.length())
	{
		return isOneWayByModifyChar(s1, s2);
	}
	else if (s1.length() == s2.length() + 1)
	{
		return isOneWayByAddChar(s1, s2);
	}
	else if (s2.length() == s1.length() + 1)
	{
		return isOneWayByAddChar(s2, s1);
	}
	else
		return false;
}

bool isOneWayByAddChar(string& sLong, string& sShort)
{
	bool foundDif = false;

	for (unsigned int i = 0, j = 0; j < sShort.size(); i++, j++)
	{
		if (sLong[i] != sShort[j])
		{
			if (foundDif)
			{
				return false;
			}
			foundDif  = true;
			j--;
		}
	}
	return true;
}

bool isOneWayByModifyChar(string& s1, string& s2)
{
	bool foundDif = false;

	for (unsigned int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			if (foundDif)
			{
				return false;
			}
				
			foundDif = true;
		}
	}
	return true;
}