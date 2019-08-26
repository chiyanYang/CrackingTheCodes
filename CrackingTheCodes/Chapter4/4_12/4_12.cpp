#include "4_12.h"

// Paths with Sum
void test4_12()
{
	vector<int> v{ 1, 2, -3, 4, 5, -6, 7, 8, 9 };

	TreeNode* t1 = createBinaryTree(v, 0, v.size() - 1);

	printBinaryTree(t1);

	int targetSum = 1;
	int count = Bruth_And_Forced_GetTotalPathsWithSum(t1, targetSum);

	cout << "Total paths of Count = " << count << endl << endl;
}

int Bruth_And_Forced_GetTotalPathsWithSum(TreeNode* rootNode, int targetSum)
{
	int totalCount = 0;

	if (rootNode != NULL)
	{
		totalCount += Bruth_And_Forced_GetTotalPathsWithSumInCurNode(rootNode, targetSum);

		totalCount += Bruth_And_Forced_GetTotalPathsWithSum(rootNode->getLeft(), targetSum);

		totalCount += Bruth_And_Forced_GetTotalPathsWithSum(rootNode->getRight(), targetSum);
	}

	return totalCount;
}

int Bruth_And_Forced_GetTotalPathsWithSumInCurNode(TreeNode* rootNode, int targetSum)
{
	int totalCount = 0;
	int curSum = 0;

	preOrderTraversal(rootNode, totalCount, curSum, targetSum);

	return totalCount;
}

void preOrderTraversal(TreeNode* rootNode, int& totalCount, int& curSum, int targetSum)
{
	if (rootNode == NULL)
	{
		return;
	}

	curSum += rootNode->getValue();

	if (curSum == targetSum)
	{
		totalCount++;
	}

	preOrderTraversal(rootNode->getLeft(), totalCount, curSum, targetSum);

	preOrderTraversal(rootNode->getRight(), totalCount, curSum, targetSum);

	curSum -= rootNode->getValue();
}

int BottomUp_GetTotalPathsWithSum(TreeNode* rootNode, int targetSum)
{
	map<int, int> sunInCurPath;


}

int BottomUp_GetTotalPathsWithSumInCurNode(TreeNode* curNode, int targetSum, map<int, int>& sunInCurPath)
{
	int totalCount = 0;

	if (curNode == NULL)
	{
		return totalCount;
	}

	int value = curNode->getValue();

	if (value == targetSum)
	{
		totalCount++;
	}

	int curTarget = targetSum - value;

	map<int, int>::iterator it;

	it = sunInCurPath.find(curTarget);
	if (it != sunInCurPath.end())
	{
		totalCount += it->second;
	}



	it = sunInCurPath.find(value);
	if (it != sunInCurPath.end())
	{
		it->second++;
	}
	else
	{
		sunInCurPath.insert(pair<int, int>(value, 1));
	}

	sunInCurPath
}