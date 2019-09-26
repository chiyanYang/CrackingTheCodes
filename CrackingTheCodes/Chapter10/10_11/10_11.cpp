#include "10_11.h"

// Peaks and Valleys
void test10_11()
{
	vector<int> v{ 5, 3, 1, 7, 4, 9, 8, 6 };

	peaksAndValleys(v);

	printVector(v);
}

void peaksAndValleys(vector<int>& v)
{
	for (int i = 1; i < v.size(); i += 2)
	{
		int firstIdx = i - 1;
		int lastIdx = i + 1;

		int& first = v[firstIdx];
		int& middle = v[i];

		if (lastIdx < v.size())
		{
			int& last = v[lastIdx];

			int maxValue = max(max(first, middle), last);

			if (maxValue == first)
			{
				swap(first, middle);
			}
			else if (maxValue == last)
			{
				swap(last, middle);
			}
		}
		else
		{
			if (first > middle)
			{
				swap(first, middle);
			}
		}
	}
}