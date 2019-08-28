#include "5_3.h"

// Flip Bit to Win
void test5_3()
{
	int target;

	cout << "Enter the number: ";
	cin >> target;
	cout << endl;

	int result1 = FlipBitToWinInString(target);
	int result2 = FlipBitToWinInInt(target);

	cout << "Result1 = " << result1 << endl;
	cout << "Result2 = " << result2 << endl;
}

int FlipBitToWinInInt(int target)
{
	if ((~target) == 0)
	{
		return sizeof(int) * 8;
	}

	int cur1s = 0;
	int pre1s = 0;
	int maxResult = 0;

	while (target != 0)
	{
		if ((target & 1) == 1)
		{
			cur1s++;
		}
		else // 0 case
		{
			if ((target & 2) == 1)
			{
				pre1s = cur1s;
				cur1s = 0;
			}
			else // 0s case
			{
				pre1s = 0;
			}
		}

		int curResult = cur1s + pre1s + 1;

		if (curResult > maxResult)
		{
			maxResult = curResult;
		}

		target = target >> 1;
	}

	return maxResult;
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

