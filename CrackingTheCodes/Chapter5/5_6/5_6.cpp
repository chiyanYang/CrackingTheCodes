#include "5_6.h"

// Conversion
void test5_6()
{
	int number1;
	int number2;

	cout << "Enter number1: ";
	cin >> number1;
	cout << endl;
	cout << "Enter number2: ";
	cin >> number2;
	cout << endl;

	intToBinaryStringPrintOnly(number1);
	intToBinaryStringPrintOnly(number2);

	int result = Conversion(number1, number2);

	cout << "Result = " << result << endl;
}

int Conversion(int number1, int number2)
{
	int count = 0;
	int xorResult = number1 ^ number2;

	while (xorResult != 0)
	{
		count++;
		xorResult = (xorResult & (xorResult - 1));
	}

	return count;
}