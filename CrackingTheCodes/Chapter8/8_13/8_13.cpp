#include "8_13.h"

// Stack of Boxes
void test8_13()
{

}

void GetTallestStackofBoxes()
{
	stacksOfBox* totalBoxs = new stacksOfBox();
	int maxHeight = 0;

	for (int i = 0; i < totalBoxs->getNumOfBox(); i++)
	{
		totalBoxs->usedBox.push_back(i);

		int curHeight = getTallestStackofBoxes(totalBoxs);

		if (curHeight > maxHeight)
		{
			maxHeight = curHeight;
		}

		vector<int>& usedBox = totalBoxs->usedBox;
		usedBox.erase(remove(usedBox.begin(), usedBox.end(), i), usedBox.end());
	}
}

int getTallestStackofBoxes(stacksOfBox* totalBoxs)
{

}