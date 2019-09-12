#include "10_1.h"

// Sorted Merge
void test10_1()
{
	vector<int> largeA { 0, 1, 2, 4, 6, 8, 10 };
	
	int itemCountsInA = largeA.size();
	largeA.resize(11);

	vector<int> smallB { 11, 12, 13, 14 };

	sortedMerge(largeA, itemCountsInA, smallB);

	printVectorInt(largeA);
}

void sortedMerge(vector<int>& largeA, int itemCountsInA, vector<int> smallB)
{
	moveItemToBack(largeA, itemCountsInA);

	int idxA = largeA.size() - itemCountsInA;
	int idxB = 0;
	int target = 0;

	while (target != largeA.size())
	{
		if (idxA == largeA.size())
		{
			copy_n(smallB.begin(), smallB.size() - idxB, &largeA[target]);
			break;
		}
		else if (idxB == smallB.size())
		{
			break;
		}

		if (largeA[idxA] <= smallB[idxB])
		{
			largeA[target] = largeA[idxA];
			idxA++;
		}
		else
		{
			largeA[target] = smallB[idxB];
			idxB++;
		}

		target++;
	}
}

void moveItemToBack(vector<int>& v, size_t itemCountsInA)
{
	rotate(v.begin(), v.begin() + itemCountsInA, v.end());
}

void printVectorInt(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}