#include "5_3.h"

// Flip Bit to Win
void test5_3()
{
	int target;

	cout << "Enter the number: ";
	cin >> target;
	cout << endl;

	int result = FlipBitToWin(target);

	cout << "Result = " << result << endl;
}

int FlipBitToWinInString(int target)
{
	string targetS = intToBinaryString(target);
	int cur1sCount = 0;
	int pre1sCount = 0;
	int pre0sCount = 0;
	int cur0sCount = 0;
	int maxResult = 0;
	
	for (char& c : targetS)
	{
		if (c == '1')
		{
			if (cur0sCount != 0)
			{
				pre0sCount = cur0sCount;
				cur0sCount = 0;
			}

			cur1sCount++;
		}
		else if (c == '0')
		{
			if (cur0sCount == 0)
			{
				if (pre0sCount == 1)
				{
					int curResult = pre1sCount + cur1sCount + 1;

					if (curResult > maxResult)
					{
						maxResult = curResult;
					}
				}
				else
				{
					int curResult = cur1sCount + 1;

					if (curResult > maxResult)
					{
						maxResult = curResult;
					}
				}

				pre1sCount = cur1sCount;
			}
			else // cur0sCount > 0
			{
				int curResult = pre1sCount + 1;

				if (curResult > maxResult)
				{
					maxResult = curResult;
				}

				pre1sCount = 0;
			}

			cur1sCount = 0;
			cur0sCount++;
		}
	}

	if (pre0sCount == 1)
	{
		int curResult = pre1sCount + cur1sCount + 1;

		if (curResult > maxResult)
		{
			maxResult = curResult;
		}
	}
	else
	{
		if (targetS.length() == cur1sCount)
		{
			maxResult = cur1sCount;
		}

		int curResult = cur1sCount + 1;

		if (curResult > maxResult)
		{
			maxResult = curResult;
		}
	}

	return maxResult;
}

string intToBinaryString(int target)
{
	string s = bitset< 32 >(target).to_string(); // string conversion

	cout << "Target string is: " << s << endl << endl;

	return s;
}
