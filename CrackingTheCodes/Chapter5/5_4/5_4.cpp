#include "5_4.h"

// Next Number
void test5_4()
{
	int number = 0;

	cout << "Enter the current number: ";
	cin >> number;

	cout << endl << "Current Number is: " << number << endl;
	intToBinaryStringPrintOnly(number);

	int nextBigNumber = getNextBigNumber(number);

	cout << "nextBigNumber = " << nextBigNumber << endl << endl;
	intToBinaryStringPrintOnly(nextBigNumber);

	int nextSmallNumber = getNextSmallNumber(number);

	cout << "nextSmallNumber = " << nextSmallNumber << endl << endl;
	intToBinaryStringPrintOnly(nextSmallNumber);
}

int getNextBigNumber(int number)
{
	// (1) Search from the least digit, find the first zero following 1(s). 
	int tmp = number;
	int shiftDigit = 0;
	int count1s = 0;

	if (number == 0 || number == INT_MAX)
	{
		cout << "No next big number" << endl;
		return 0;
	}

	while ((tmp & 1) == 0)
	{
		tmp = tmp >> 1;
		shiftDigit++;
	}

	while ((tmp & 1) == 1)
	{
		tmp = tmp >> 1;
		count1s++;
		shiftDigit++;
	}

	if (shiftDigit == sizeof(int) * 8)
	{
		cout << "No next big number" << endl;
		return 0;
	}

	// (2) Use mask to set the 0 to 1 and other least digits to zero.
	int maskZero = ~((1 << shiftDigit) - 1); 
	number = number & maskZero; // 1001110 -> 1000000

	int maskOne = 1 << shiftDigit;
	number = number | maskOne; // 1000000 -> 1010000

	// (3) Use mask to set rest 1(s) from the least digit.
	count1s--; // A 1 is set at step (2)
	int maskOnes = (1 << count1s) - 1;

	number = number | maskOnes;

	return number;
}

int getNextSmallNumber(int number)
{
	// (1) Search from the least digit, find the first one following 0(s).
	int tmp = number;
	int shiftDigit = 0;
	int count1s = 0;

	if (number == 0 || number == INT_MAX)
	{
		cout << "No next small number" << endl;
		return 0;
	}

	while ((tmp & 1) == 1)
	{
		tmp = tmp >> 1;
		count1s++;
		shiftDigit++;
	}

	while ((tmp & 1) == 0)
	{
		tmp = tmp >> 1;
		shiftDigit++;
	}

	// (2) Use mask to set the 1 to 0 and other least digits to zero.
	int maskZero = ~((1 << (shiftDigit + 1)) - 1);
	number = number & maskZero; // 1001110 -> 1001100

	// (3) Use mask to set rest 1(s) from the least digit.
	count1s++; // A 1 is set to 0 at step (2)
	int maskLeftOnes = (1 << count1s) - 1;
	int maskOnes = maskLeftOnes << (shiftDigit - count1s);

	number = number | maskOnes;
}