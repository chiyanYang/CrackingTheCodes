#include "8_13.h"

// Stack of Boxes
void test8_13()
{
	stacksOfBox* totalBoxs = new stacksOfBox();
	vector<int> boxsequences;
	totalBoxs->printBoxs();

	int result = getTallestStackofBoxes(totalBoxs, NULL, boxsequences);

	cout << "Result = " << result << endl;
	printSequences(boxsequences);

	delete totalBoxs;
}

int getTallestStackofBoxes(stacksOfBox* totalBoxs, box* preBox, vector<int>& boxsequences)
{
	int maxHeight = 0;
	int idxOfMax = -1;
	vector<int> curBoxsequences;

	for (int i = 0; i < totalBoxs->getNumOfBox(); i++)
	{
		if (totalBoxs->usedBox[i] == 1 || !isValidBoxOn(&totalBoxs->stackBoxs[i], preBox))
		{
			continue;
		}

		totalBoxs->usedBox[i] = 1;
		vector<int> remainingBoxsequences;
		remainingBoxsequences.push_back(i);

		int curHeight = getTallestStackofBoxes(totalBoxs, &totalBoxs->stackBoxs[i], remainingBoxsequences);
		curHeight += totalBoxs->stackBoxs[i].edge[1];

		totalBoxs->usedBox[i] = 0;

		if (curHeight > maxHeight)
		{
			curBoxsequences = remainingBoxsequences;

			idxOfMax = i;

			maxHeight = curHeight;
		}
	}

	if (idxOfMax != -1)
	{
		boxsequences.insert(boxsequences.end(), curBoxsequences.begin(), curBoxsequences.end());
	}
	
	return maxHeight;
}

bool isValidBoxOn(box* curBox, box* preBox)
{
	if (preBox == NULL)
	{
		return true;
	}

	for (int i = 0; i < 3; i++)
	{
		if (curBox->edge[i] > preBox->edge[i])
		{
			return false;
		}
	}
	
	return true;
}

void printSequences(vector<int>& boxsequences)
{
	for (int i = 0; i < boxsequences.size(); i++)
	{
		cout << boxsequences[i] << " ";
	}

	cout << endl;
}