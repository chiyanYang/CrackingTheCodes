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

	coordinate begin{ 0, 0 };
	coordinate end{ vMatrix.size() - 1, vMatrix[0].size() - 1 };

	coordinate result = sortedMatrixSearch(vMatrix, begin, end, target);

	cout << "row: " << result.row << endl;
	cout << "col: " << result.col << endl;
}

coordinate sortedMatrixSearch(vector<vector<int>>& vMatrix, coordinate coordBegin, coordinate coordEnd, int target)
{
	// Check Valid and if the start of the sqaure is the target (for the case of size 1 square)
	if (!isValidSquare(coordBegin, coordEnd))
	{
		return { -1 , -1 };
	}

	if (vMatrix[coordBegin.row][coordBegin.col] == target)
	{
		return coordBegin;
	}

	// Step1: search diagonal:
	int diagEnd = coordEnd.col > coordEnd.row ? coordEnd.row : coordEnd.col;
	coordinate coorDiagEnd{ diagEnd, diagEnd };
	
	coordinate coorMid;
	coordinate tmpBegin = coordBegin;
	coordinate tmpEnd = coordEnd;

	while (isValidSquare(tmpBegin, tmpEnd))
	{
		coorMid = getMiddle(tmpBegin, tmpEnd);

		if (getValue(vMatrix, coorMid) == target)
		{
			return coorMid;
		}
		else if (getValue(vMatrix, coorMid) < target) // Target is excluded from top left square.
		{
			tmpBegin.row = coorMid.row + 1;
			tmpBegin.col = coorMid.col + 1;
		}
		else // Target is excluded from down right.
		{
			tmpEnd.row = coorMid.row - 1;
			tmpEnd.col = coorMid.col - 1;
		}
	}

	// Step2: search down left and right top square:
	coordinate lowerLeftBegin{ tmpBegin.row, coordBegin.col };
	coordinate lowerLeftEnd{ coordEnd.row, tmpBegin.col - 1 };
	coordinate upperRightBegin{ coordBegin.row, tmpBegin.col };
	coordinate upperRightEnd{ tmpBegin.row - 1, coordEnd.col };

	coordinate lowerLeft = sortedMatrixSearch(vMatrix, lowerLeftBegin, lowerLeftEnd, target);
	if (lowerLeft.row == -1) {
		return sortedMatrixSearch(vMatrix, upperRightBegin, upperRightEnd, target);
	}

	return lowerLeft;
}

bool isValidSquare(coordinate coordBegin, coordinate coordEnd)
{
	if (coordBegin.col > coordEnd.col)
		return false;

	if (coordBegin.row > coordEnd.row)
		return false;

	return true;
}

coordinate getMiddle(coordinate coordBegin, coordinate coordEnd)
{
	coordinate coorMid;
	coorMid.row = (coordBegin.row + coordEnd.row) / 2;
	coorMid.col = (coordBegin.col + coordEnd.col) / 2;

	return coorMid;
}

int getValue(vector<vector<int>>& vMatrix, coordinate coordCur)
{
	return vMatrix[coordCur.row][coordCur.col];
}