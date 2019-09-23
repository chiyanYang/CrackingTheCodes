#include "10_9.h"

// Sorted Matrix Search
void test10_9()
{
	vector<vector<int>> vMatrix { 
									{ 0, 1, 2, 3, 4, 5 }, 
									{ 1, 2, 3, 4, 5, 6 }, 
									{ 2, 3, 4, 5, 6, 7 },
									{ 3, 4, 5, 6, 7, 11 },
									{ 4, 5, 6, 7, 8, 15 }
								};

	int target = -1;

	cout << "Input target: ";
	cin >> target;
	cout << endl;

	int result = sortedMatrixSearch(vMatrix, target);

	cout << "result: " << result << endl;
}

int sortedMatrixSearch(vector<vector<int>>& vMatrix, int target)
{
	int row = vMatrix.size();
	int column = vMatrix[0].size();
	// Step1: search diagonal:
	int begin = 0;
	int end = column > row ? row - 1 : column - 1;
	int middle = begin + (end - begin) / 2;
	int result = INT_MIN;

	while (true)
	{
		if (vMatrix[middle][middle] == target)
		{
			result = middle * column + middle;
			break;
		}
		else if (vMatrix[middle][middle] < target) // Target is at right down.
		{
			if (vMatrix[end][end] > target)
			{
				if (begin + 1 == end)
				{
					result = 0;
					break;
				}

				begin = middle;
				middle = begin + (end - begin) / 2;
			}
			else if (vMatrix[end][end] == target)
			{
				result = end * column + end;
				break;
			}
			else
			{
				result = -1;
				break;
			}
		}
		else // Target is excluded from items at right down.
		{
			if (vMatrix[begin][begin] < target)
			{
				if (begin + 1 == end)
				{
					result = 0;
					break;
				}

				end = middle;
				middle = begin + (end - begin) / 2;
			}
			else if (vMatrix[begin][begin] == target)
			{
				result = begin * column + begin;
				break;
			}
			else
			{
				result = -1;
				break;
			}
		}
	}

	cout << "begin: " << begin << endl;
	cout << "end: " << end << endl;
	cout << "r: " << result << endl;

	// Step2: search down and right line:
	if (result == -1) // if matrix is square, search not found, else only down or right line exist
	{
		if (row == column)
		{
			return -1;
		}
		else
		{
			if (column > row)
			{
				int result = searchRight(vMatrix, target, end);

				if (result != -1)
				{
					return end * column + result;
				}

				return result;
			}
			else
			{
				int result = searchDown(vMatrix, target, end);

				if (result != -1)
				{
					return -2;
				}

				return result;
			}
		}
	}
	else if (result == 0) // between begin and end
	{
		int result = searchRight(vMatrix, target, begin);

		if (result != -1)
		{
			return begin * column + result;
		}

		result = searchDown(vMatrix, target, end);

		if (result != -1)
		{
			return -2;
		}

		return result;
	}
	else
	{
		return result;
	}

	return -1;
}

int searchRight(vector<vector<int>>& vMatrix, int target, int diagonal)
{
	vector<int>& searchLine = vMatrix[diagonal];
	int begin = diagonal;
	int end = vMatrix[diagonal].size() - 1;
	int middle = begin + (end - begin) / 2;

	while (searchLine[middle] != target)
	{
		if (searchLine[middle] < target)
		{
			begin = middle + 1;
			middle = begin + (end - begin) / 2;
		}
		else
		{
			end = middle - 1;
			middle = begin + (end - begin) / 2;
		}

		if (begin > end)
		{
			return -1;
		}
	}
	
	return middle;
}

int searchDown(vector<vector<int>>& vMatrix, int target, int diagonal)
{
	return -1;
}