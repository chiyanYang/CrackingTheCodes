#include "8_1.h"

// Triple Step
void test8_1()
{
	int totalSteps;

	cout << "Input the total steps: ";
	cin >> totalSteps;
	cout << endl;

	int result;
	result = tripleStep(totalSteps);
	cout << "tripleStep result = " << result << endl;

	vector<int> stepsResult(totalSteps + 1, -1);
	result = tripleStep_BottomUp(totalSteps, stepsResult);
	cout << "tripleStep_BottomUp result = " << result << endl << endl;

}

int tripleStep(int remainSteps)
{ 
	if (remainSteps < 0)
	{
		return 0;
	}
	else if (remainSteps == 0)
	{
		return 1;
	}
	else
	{
		return tripleStep(remainSteps - 1) + tripleStep(remainSteps - 2) + tripleStep(remainSteps - 3);
	}
}

int tripleStep_BottomUp(int remainSteps, vector<int>& stepsResult)
{
	if (remainSteps < 0)
	{
		return 0;
	}
	else if (stepsResult[remainSteps] != -1)
	{
		return stepsResult[remainSteps];
	}
	else if (remainSteps == 0)
	{
		return 1;
	}
	else
	{
		int result = tripleStep_BottomUp(remainSteps - 1, stepsResult) +
				     tripleStep_BottomUp(remainSteps - 2, stepsResult) +
				     tripleStep_BottomUp(remainSteps - 3, stepsResult);

		stepsResult[remainSteps] = result;
		return result;
	}
}