#include "1_9.h"

// 1.9 String Rotation
void test1_9()
{
	int toStop = 0;
	int result;

	string s1 = "waterbottle";
	string s2 = "erbottlewat";

	result = stringRotation(s1, s2); // Should be true

	cout << "Is Rotation = " << result << endl;

	cin >> toStop;
}

// A vector to store 0s 
bool stringRotation(string& s1, string& s2)
{
	if (s1.length() == 0 || s2.length() == 0 || s1.length() != s2.length())
	{
		return false;
	}

	string combinedS = s1 + s1;
	return isSubtring(combinedS, s2);
}


// Check if s2 is substring of s1
bool isSubtring(string& s1, string& s2)
{
	if (s1.find(s2) != string::npos) {
		return true;
	}
	return false;
}