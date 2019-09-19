#include "10_5.h"

// Sparse Search
void test10_5()
{
	vector<string> v { "at","", "", "", "ball", "", "", "car", "", "", "dad", "", "" };
	string target = "ball";

	int targetIdx = sparseSearch(v, target);

	cout << "target index = " << targetIdx << endl;
}

int sparseSearch(vector<string>& v, string target)
{
	int begin = 0;
	int end = v.size() - 1;
	int middle = begin + (end - begin) / 2;
	string midValue = v[middle];

	if (midValue == "")
	{
		middle = getNearestString(v, middle, 0, end);

		if (middle == -1)
		{
			return -1;
		}

		midValue = v[middle];
	}

	while (midValue != target)
	{
		if (midValue > target) // search left
		{
			end = middle - 1;
		}
		else // search right
		{
			begin = middle + 1;
		}

		if (begin > end)
		{
			return -1;
		}

		middle = begin + (end - begin) / 2;

		if (middle >= v.size() || middle < 0)
		{
			return -1;
		}

		midValue = v[middle];

		if (midValue == "")
		{
			middle = getNearestString(v, middle, begin, end);

			if (middle == -1)
			{
				return -1;
			}

			midValue = v[middle];
		}
	}

	return middle;
}

int getNearestString(vector<string>& v, int idx, int begin, int end)
{
	int shift = 0;
	int count = 0;

	while (true)
	{
		shift = shift + 1;
		shift = -shift;

		idx += shift;

		if (begin > idx || end < idx)
		{
			count++;

			if (count == 2)
			{
				return -1;
			}

			continue;
		}
		else
		{
			if (v[idx] != "")
			{
				return idx;
			}

			count = 0;
		}
	}

	return -1;
}