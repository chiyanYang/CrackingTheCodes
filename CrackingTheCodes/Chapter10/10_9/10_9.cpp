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

	int result = sortedMatrixSearch(vMatrix, 0, 0, vMatrix.size() - 1, vMatrix[0].size() - 1 ,target);

	cout << "result: " << result << endl;
}

int sortedMatrixSearch(vector<vector<int>>& vMatrix, int beginRow, int beginCol, int endRow, int endCol, int target)
{
	// Step1: search diagonal:
	int begin = 0;
	int end = endCol > endRow ? endRow : endCol;
	int middle = begin + (end - begin) / 2;
	int result = INT_MIN;

	int matrixColSize = vMatrix[0].size();
	int matrixRowSize = vMatrix.size();

	if (vMatrix[end][end] == target)
	{
		return end * matrixColSize + end;
	}

	while (true)
	{
		if (vMatrix[middle][middle] == target)
		{
			return middle * matrixColSize + middle;
		}
		else if (vMatrix[middle][middle] < target) // Target is excluded from top.
		{
			if (vMatrix[end][end] > target)
			{
				if (begin + 1 == end)
				{
					result = sortedMatrixSearch(vMatrix, int beginRow, int beginCol, int endRow, int endCol, int target);
					result = sortedMatrixSearch(vMatrix, int beginRow, int beginCol, int endRow, int endCol, int target);
				}

				begin = middle;
				middle = begin + (end - begin) / 2;
			}
			else
			{
				return sortedMatrixSearch(vMatrix, end, end, matrixRowSize - 1, matrixColSize - 1, target);
			}
		}
		else // Target is excluded from down.
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
				int result = searchTopRight(vMatrix, target, end);

				if (result != -1)
				{
					return end * column + result;
				}

				return result;
			}
			else
			{
				int result = searchDownLeft(vMatrix, target, end);

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
		int result = searchTopRight(vMatrix, target, begin);

		if (result != -1)
		{
			return begin * column + result;
		}

		result = searchDownLeft(vMatrix, target, end);

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