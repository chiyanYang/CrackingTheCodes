#include "1_7.h"

// Rotate Maxtrix
void test1_7()
{
	int toStop = 0;

	int length = 3;

	int** arr = new int*[length];
	for (int i = 0; i < length; ++i)
		arr[i] = new int[length];

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			arr[i][j] = i * length + j;
		}
	}

	printArr(arr, length);
	cout << endl;

	rotateArray(arr, length);

	printArr(arr, length);

	cin >> toStop;

	// free dynamically allocated memory
	for (int i = 0; i < length; i++)
	{
		delete[] arr[length]; // delete array within matrix
	}
	// delete actual matrix
	delete[] arr;
}

void rotateArray(int** array, int length)
{
	int layer = length / 2;

	for (int k = 0; k < layer; k++)
	{
		for (int i = k; i < length - k * 2 - 1; i++)
		{
			int top = array[k][i]; // top
			array[k][i] = array[length - 1 - i][k]; // bottom left to top right
			array[length - 1 - i][k] = array[length - 1 - k][length - 1 - i]; // bottom right to bottom left
			array[length - 1 - k][length - 1 - i] = array[i][length - 1 - k]; // top right to bottom right
			array[i][length - 1 - k] = top; // top to top right
		}
	}
}

void printArr(int** arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}