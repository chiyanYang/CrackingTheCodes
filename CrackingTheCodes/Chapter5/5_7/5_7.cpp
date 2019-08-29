#include "5_7.h"

// Pairwise Swap
void test5_7()
{
	int number;

	cout << "Enter the number: ";
	cin >> number;
	cout << endl;

	intToBinaryStringPrintOnly(number);

	int result = PairwiseSwap(number);

	intToBinaryStringPrintOnly(result);
}

int PairwiseSwap(int number)
{
	int mask1 = 0xaaaaaaaa; // 10101010
	int mask2 = 0x55555555; // 01010101

	int shiftLeft = (number & mask1) >> 1;
	int shiftRight = (number & mask2) << 1;

	return shiftLeft | shiftRight;
}