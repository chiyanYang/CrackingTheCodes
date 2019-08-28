#include "5_4.h"

// Next Number
void test5_4()
{
	int number;

	cout << "Enter the current number: ";
	cin >> number;

	cout << endl << "Current Number is: " << number << endl;
	intToBinaryString(number);

	int nextBigNumber = nextNumber(number);

	intToBinaryString(nextBigNumber);

	cout << "nextBigNumber = " << nextBigNumber << endl << endl;
}

int nextNumber(int number)
{
	// (1) Search from the least digit, find the first zero following 1(s). 
	int tmp = number;
	int shiftDigit = 0;
	int count1s = 0;

	if (number == 0 || number == INT_MAX)
	{
		cout << "No next number" << endl;
		return 0;
	}

	while (tmp & 1 == 0)
	{
		tmp = tmp >> 1;
		shiftDigit++;
	}

	while (tmp & 1 == 1)
	{
		tmp = tmp >> 1;
		count1s++;
		shiftDigit++;
	}

	// (2) Use mask to set the zero to 1 and other least digits to zero.
	int maskZero = ((~0) << shiftDigit); 
	number = number & maskZero; // 1001110 -> 1000000

	int maskOne = 1 << shiftDigit;
	number = number | maskOne; // 1000000 -> 1010000

	// (3) Use mask to set rest 1(s) from the least digit.
	count1s--; // A 1 is set at step (2)
	int maskOnes = (1 << count1s) - 1;

	number = number | maskOnes;

	return number;
}