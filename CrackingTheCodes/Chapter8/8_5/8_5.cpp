#include "8_5.h"

// Recursive Multiply
void test8_5()
{
	int num1 = 0;
	int num2 = 0;

	cout << "Please enter num1: ";
	cin >> num1;
	cout << endl;

	cout << "Please enter num2: ";
	cin >> num2;
	cout << endl;

	cout << "Result by mul operation is: " << num1 * num2 << endl << endl;
	cout << "Result by RecursiveMultiply is: " << RecursiveMultiply(num1, num2) << endl << endl;
}

int RecursiveMultiply(int num1, int num2)
{
	int largeNum = (num1 > num2) ? num1 : num2;
	int smallNum = (num1 > num2) ? num2 : num1;

	int result = 0;
	int multiple = -1;

	addedByMul2(result, multiple, largeNum, smallNum);

	return result;
}

void addedByMul2(int& result, int& multiple, int& largeNum, int& smallNum)
{
	if (smallNum == 0)
	{
		return;
	}

	multiple++;
	
	int curSmallNum = smallNum >> 1;
	int remaining = smallNum - (curSmallNum << 1);
	
	if (remaining == 1)
	{
		result = result + (largeNum << multiple);
	}
	
	addedByMul2(result, multiple, largeNum, curSmallNum);
}