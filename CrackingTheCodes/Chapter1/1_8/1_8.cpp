#include "1_8.h"

// Zero Matrix
void test1_8()
{
	int toStop = 0;

	int m = 3;
	int n = 5;
	srand(time(NULL));

	int** arr = new int*[m];
	for (int i = 0; i < m; ++i)
		arr[i] = new int[n];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}

	printArr(arr, m, n);

	cout << endl;

	zeroArrayInplace(arr, m, n);

	printArr(arr, m, n);

	cin >> toStop;

	// free dynamically allocated memory
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i]; // delete array within matrix
	}
	// delete actual matrix
	delete[] arr;
}

// Method 1
// A vector to store 0s, Space = O(k), k is number of zeros
void zeroArrayExtraSpace(int** array, int m, int n)
{
	vector<pair<int, int>> zeroIdx;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[i][j] == 0)
				zeroIdx.push_back(make_pair(i, j));
		}
	}

	while (zeroIdx.size() > 0)
	{
		pair<int, int> pColLine = zeroIdx.back();
		zeroIdx.pop_back();
		zeroCol(array, m, pColLine.second);
		zeroLine(array, n, pColLine.first);
	}
}

// Method 2
// A column and a Line to store desired clean line and column, Space = O(m+n), m, n is the height and width
void zeroArrayFixedSpace(int** array, int m, int n)
{
	int* col = new int[m];
	int* line = new int[n];

	// Init col to 1
	for (int i = 0; i < m; i++)
		col[i] = 1;

	// Init line to 1
	for (int j = 0; j < m; j++)
		line[j] = 1;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[i][j] == 0)
			{
				col[i] = 0;
				line[j] = 0;
			}
		}
	}

	// Fullfill 0s in line
	for (int i = 0; i < m; i++)
	{
		if (col[i] == 0)
			zeroLine(array, n, i);
	}

	// Fullfill 0s in col
	for (int j = 0; j < n; j++)
	{
		if (line[j] == 0)
			zeroCol(array, m, j);
	}

	free(zeroCol);
	free(zeroLine);
}

// Method 3
// Use the space in the array of a column and a Line to store desired clean line and column
// Find the first zero and uses its column and line
// Space = O(1)
void zeroArrayInplace(int** array, int m, int n)
{
	int colIdx; // col can not be performed as array
	int* line = NULL;
	int lineIdx;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[i][j] == 0)
			{
				colIdx = j;
				lineIdx = i;
				line = array[i];
				break;
			}
		}
	}

	if (line == NULL)
		return;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[i][j] == 0)
			{
				array[i][colIdx] = 0;
				line[j] = 0;
			}
		}
	}

	// Fullfill 0s in line
	for (int i = 0; i < m; i++)
	{
		if (array[i][colIdx] == 0 && i != lineIdx)
			zeroLine(array, n, i);
	}

	// Fullfill 0s in col
	for (int j = 0; j < n; j++)
	{
		if (line[j] == 0 && j != colIdx)
			zeroCol(array, m, j);
	}

	// Fullfill 0s in tmp line and col
	zeroLine(array, n, lineIdx);
	zeroCol(array, m, colIdx);
}

void zeroCol(int** arr, int m, int idx)
{
	for (int i = 0; i < m; i++)
	{
		arr[i][idx] = 0;
	}
}

void zeroLine(int** arr, int n, int idx)
{
	for (int j = 0; j < n; j++)
	{
		arr[idx][j] = 0;
	}
}

void printArr(int** arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}