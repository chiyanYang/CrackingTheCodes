#include "10_3.h"

// Search in Rotated Array
void test10_3()
{
	int target = 5;
	vector<int> v { 1, 3, 4, 5, 7, 10, 14, 15, 16, 19, 20, 25 };

	printVector(v);

	rotate(v);

	printVector(v);

	int result = searchRotatedArr(v, target);

	cout << "Search target = 5, Result = " << result << endl << endl;
}

void rotate(vector<int>& v)
{
	int randomNum = getRandomNum(0, v.size());

	cout << "rotate num = " << randomNum << endl;

	rotate(v.begin(), v.begin() + randomNum, v.end());
}

int searchRotatedArr(vector<int>& v, int target)
{
	if (v.size() == 0)
	{
		return -1;
	}

	int begin = 0;
	int end = v.size() - 1;
	int middle = 0 + (end - begin) / 2;

	if (v[middle] == target)
	{
		return middle;
	}

	int result = binarySearch(v, begin, middle, target);

	if (result != -1)
	{
		return result;
	}

	return binarySearch(v, middle + 1, end, target);
}

int binarySearch(vector<int>& v, int begin, int end, int target)
{
	if (end < begin)
	{
		return -1;
	}

	if (end == begin)
	{
		if (v[end] == target)
		{
			return end;
		}

		return -1;
	}

	int middle = begin + (end - begin) / 2;

	if (v[middle] == target)
	{
		return middle;
	}

	int result = binarySearch(v, begin, middle, target);

	if (result != -1)
	{
		return result;
	}

	return binarySearch(v, middle + 1, end, target);
}

