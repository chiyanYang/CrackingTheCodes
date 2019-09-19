#include "10_4.h"

// Sorted Search, No Size
void test10_4()
{
	vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8 };
	int target = 2;

	int targetIdx = sortedSearchNoSize(v, target);

	cout << "target index = " << targetIdx << endl;

}

int sortedSearchNoSize(vector<int>& v, int target)
{
	int begin = 0;
	int end = getLengthOfVector(v);
	
	int middle = getMiddle(begin, end);
	int middleValue = getValue(v, middle);
	
	while (middleValue != target)
	{
		if (begin > end || middleValue == INT_MIN)
		{
			return INT_MIN;
		}

		if (middleValue > target || middleValue == -1) // Search left.
		{
			end = middle - 1;
			middle = getMiddle(begin, end);
		}
		else
		{
			begin = middle + 1;
			middle = getMiddle(begin, end);
		}

		middleValue = getValue(v, middle);
	}

	return middle;
}

int getValue(vector<int>& v, int idx)
{
	int value = INT_MIN;

	try {
		value = v.at(idx);
	}
	catch (...) {
		value = -1;
	}

	return value;
}

int getLengthOfVector(vector<int>& v)
{
	int length = 0;
	int shift = 1;

	while (getValue(v, length) != -1)
	{
		length += shift;
		shift = shift << 1;
	}

	return length;
}

int getMiddle(int begin, int end)
{
	return begin + (end - begin) / 2;
}