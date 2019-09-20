#include "10_9.h"

// Sorted Matrix Search
void test10_9()
{
	
}

int sortedMatrixSearch(vector<vector<int>> vMatrix, int target)
{
	int row = vMatrix.size();
	int column = vMatrix[0].size();
	// Step1: search diagonal:
	int begin = 0;
	int end = column > row ? row - 1 : column - 1;
	int middle = begin + (end - begin) / 2;

	while (vMatrix[middle][middle] != target)
	{

	}


	// Step2: search down and right line:

}