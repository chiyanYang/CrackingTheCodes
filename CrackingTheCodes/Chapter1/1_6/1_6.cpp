#include "1_6.h"

// String Compression
void test1_6()
{
	int toStop = 0;

	string sToCompress = "aabcccccaaa";
	string result;

	cout << "Input string" << endl << sToCompress << endl;

	string sCompressed = stringCompression(sToCompress);

	if (sToCompress.length() > sCompressed.length())
		result = sCompressed;
	else
		result = sToCompress;

	cout << "Result: " << result << endl;

	cin >> toStop;
}

string stringCompression(string& sToCompress)
{
	string sCompressing;

	for (unsigned int i = 0; i < sToCompress.size(); i++)
	{
		int count = 1;
		char c = sToCompress.at(i);

		while (i + 1 < sToCompress.size() && c == sToCompress.at(i + 1))
		{
			count++;
			i++;
		}

		sCompressing.push_back(c);
		sCompressing += to_string(count);
	}

	return sCompressing;
}