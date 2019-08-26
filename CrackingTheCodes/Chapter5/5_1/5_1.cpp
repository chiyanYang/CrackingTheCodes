#include "5_1.h"

// Insertion
void test5_1()
{
	int N = 0b10000000000;
	int M = 0b10011;
	int i = 2;
	int j = 6;
	int result;

	result = insertion(N, M, i, j);

	cout << "Result = " << bitset<16>(result) << endl;
}

int insertion(int N, int M, int i, int j)
{
	// (1) Do a zero mask from ith~jth in N. e.g. 2th~6th -> 1s0000011
	int zeroMaskJ = ~0; // 1s

	zeroMaskJ = zeroMaskJ << (j + 1); // 1s0000000 (j = 6)

	int oneMaskI = 1; // 0s1

	oneMaskI = oneMaskI << i;  // 0s100 (i = 2)
	oneMaskI -= 1;  // 0s11 (i = 2)

	int maskIJ = zeroMaskJ | oneMaskI;

	N = N & maskIJ; // 1s0000011

	// (2) Create the mask of M.
	int maskM = M << i;

	// (3) Combined.
	int result = N | maskM;

	return result;
}