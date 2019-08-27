#include "5_2.h"

// Binary to String
void test5_2()
{
	double target = 0.625;
	string result;
	result = binaryToString(target);

	cout << "The result: " << result << endl << endl;
}

string binaryToString(double target)
{
	int count = 0;
	string result = "0.";

	while (count <= 32 && target > 0)
	{
		target = target * 2;

		if (target >= 1)
		{
			result.append("1");
			target--;
		}
		else
		{
			result.append("0");
		}

		count++;
	}

	if (count == 33 && target != 0)
	{
		cout << "ERROR" << endl << endl;
	}

	return result;
}