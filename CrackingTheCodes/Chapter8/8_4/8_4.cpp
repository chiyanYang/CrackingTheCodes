#include "8_4.h"

// Power Set
void test8_4()
{
	vector<int> intSet{ 1, 2, 3, 4, 5, 6 };

	vector<vector<int>> allSubSet = powerSet(intSet);

	cout << "Number of total subset: " << allSubSet.size() << endl;
	print2DVector(allSubSet);
}

vector<vector<int>> powerSet(vector<int>& intSet)
{
	vector<vector<int>> allSubIntSet;
	vector<int> curSubIntSet;

	if (intSet.size() != 0)
	{
		getASubIntSet(intSet, allSubIntSet, curSubIntSet, 0);
	}

	return allSubIntSet;
}

void getASubIntSet(vector<int>& intSet, vector<vector<int>>& allSubIntSet, vector<int>& curSubIntSet, int curIdx)
{
	int curValue = intSet[curIdx];

	vector<int> curVectorIncCurValue(curSubIntSet);

	curVectorIncCurValue.push_back(curValue);

	if (curIdx == intSet.size() - 1)
	{
		allSubIntSet.push_back(curVectorIncCurValue);
		allSubIntSet.push_back(curSubIntSet);
		return;
	}

	getASubIntSet(intSet, allSubIntSet, curVectorIncCurValue, curIdx + 1);
	getASubIntSet(intSet, allSubIntSet, curSubIntSet, curIdx + 1);
}
