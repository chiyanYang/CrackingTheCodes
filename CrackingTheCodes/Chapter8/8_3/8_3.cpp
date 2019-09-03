#include "8_3.h"

// Magic Index
void test8_3()
{
	int resultIdx = -1;
	vector<int> curVector { -2, -1, 0, 1, 2, 3, 4, 5, 8 };

	resultIdx = MagicIndexBS(curVector, 0, 8);

	if (resultIdx == -1)
	{
		cout << "Magic Index NOT FOUND" << endl << endl;
	}
	else
	{
		cout << "ResultIdx = " << resultIdx << "  " << "ResultValue = " << curVector[resultIdx] << endl << endl;
	}
	
}

int MagicIndexBS(vector<int>& curVector, int begin, int end)
{
	if (begin > end)
	{
		return -1;
	}

	int mid = begin + (end - begin) / 2;

	if (curVector[mid] == mid)
	{
		return mid;
	}
	else if (curVector[mid] > mid)
	{
		return MagicIndexBS(curVector, begin, mid - 1);
	}
	else // curVector[mid] < mid
	{
		return MagicIndexBS(curVector, mid + 1, end);
	}
}

int MagicIndexBS_NonDistinct(vector<int>& curVector, int begin, int end)
{
	if (begin > end)
	{
		return -1;
	}

	int mid = begin + (end - begin) / 2;

	if (curVector[mid] == mid)
	{
		return mid;
	}
	else if (curVector[mid] > mid)
	{
		return MagicIndexBS(curVector, begin, mid - 1);
	}
	else // curVector[mid] < mid
	{
		return MagicIndexBS(curVector, mid + 1, end);
	}
}