#include "Ch5Common.h"


string intToBinaryString(int target)
{
	string s = bitset< 32 >(target).to_string(); // string conversion

	cout << "Target string is: " << s << endl << endl;

	return s;
}

void intToBinaryStringPrintOnly(int target)
{
	string s = bitset< 32 >(target).to_string(); // string conversion

	cout << "Target string is: " << s << endl << endl;
}