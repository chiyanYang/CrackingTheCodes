#include "4_12.h"

// Paths with Sum
void test4_12()
{
	vector<int> v{ 1, 2, -3, 4, 5, -6, 7, 8, 9 };

	TreeNode* t1 = createBinaryTree(v, 0, v.size() - 1);

	printBinaryTree(t1);

	int targetSum;

	cout << "Enter the target: ";
	cin >> targetSum;
	cout << endl;

	int count1 = Bruth_And_Forced_GetTotalPathsWithSum(t1, targetSum);
	int count2 = BottomUp_GetTotalPathsWithSum(t1, targetSum);

	cout << "Total paths of Count1 = " << count1 << endl;
	cout << "Total paths of Count2 = " << count2 << endl << endl;
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
	sunInCurPath.insert(pair<int, int>(0, 1));

	return BottomUp_GetTotalPathsWithSumPreOrder(rootNode, targetSum, 0, sunInCurPath);
}

int BottomUp_GetTotalPathsWithSumPreOrder(TreeNode* curNode, int targetSum, int preSum, map<int, int>& sunInCurPath)
{
	int totalCount = 0;

	if (curNode == NULL)
	{
		return totalCount;
	}

	int value = curNode->getValue();
	int curSum = preSum + value;

	int curTarget = curSum - targetSum;

	map<int, int>::iterator it;

	// find the matched moving sum
	it = sunInCurPath.find(curTarget);
	if (it != sunInCurPath.end())
	{
		totalCount += it->second;
	}

	// Add curSum to the hash table
	it = sunInCurPath.find(curSum);
	if (it != sunInCurPath.end())
	{
		it->second++;
	}
	else
	{
		sunInCurPath.insert(pair<int, int>(curSum, 1));
	}

	totalCount += BottomUp_GetTotalPathsWithSumPreOrder(curNode->getLeft(), targetSum, curSum, sunInCurPath);
	totalCount += BottomUp_GetTotalPathsWithSumPreOrder(curNode->getRight(), targetSum, curSum, sunInCurPath);

	// remove curSum from the hash table
	it = sunInCurPath.find(curSum);

	if (it != sunInCurPath.end() && it->second > 1)
	{
		it->second--;
	}
	else if(it != sunInCurPath.end() && it->second == 1)
	{
		sunInCurPath.erase(it);
	}
	else
	{
		cout << "Somehow there is an error" << endl;
	}


	return totalCount;
}