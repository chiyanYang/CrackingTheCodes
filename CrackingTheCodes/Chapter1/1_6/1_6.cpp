#include "1_6.h"

// String Compression
void test1_6()
{
	int toStop = 0;

	string sToCompress = "aabcccccaaa";
	string result;

	cout << "Input string" << endl << sToCompress << endl;

	string sCompressed = stringCompression(sToCompress);

	if (sCompressed.length() != 0)
		result = sCompressed;
	else
		result = sToCompress;

	cout << "Result: " << result << endl;

	cin >> toStop;
}

string stringCompression(string& sToCompress)
{
	int compressedLength = checkComressedLength(sToCompress);

	if (compressedLength >= sToCompress.length())
	{
		return string();
	}

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

int checkComressedLength(string& sToCompress)
{
	int length = 0;

	for (unsigned int i = 0; i < sToCompress.size(); i++)
	{
		int count = 1;
		char c = sToCompress.at(i);

		while (i + 1 < sToCompress.size() && c == sToCompress.at(i + 1))
		{
			count++;
			i++;
		}

		int compressedNumLength = to_string(count).length(); // Can be furthur improving the performance
		length = length + compressedNumLength + 1;
	}

	return length;
}