#include "4_4.h"

// Check Balanced
void test4_4()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7 ,8 };

	TreeNode* treeRoot = createRandomBTree(v, 0, v.size() - 1);

	printBinaryTree(treeRoot);

	bool result = IsBalanced(treeRoot);

	cout << "IsBalanced: " << result << endl;
}

bool IsBalanced(TreeNode* rootNode)
{
	int height = getTreeHeight(rootNode);

	if (height == -1)
	{
		return false;
	}

	return true;
}

// Ge the height of tree, -1 if is not balanced
int getTreeHeight(TreeNode* rootNode)
{
	if (rootNode == NULL)
	{
		return 0;
	}

	TreeNode* leftNode = rootNode->getLeft();
	TreeNode* rightNode = rootNode->getRight();

	int leftHeight = getTreeHeight(leftNode);
	int rightHeight = getTreeHeight(rightNode);

	if (leftHeight == -1 || rightHeight == -1)
	{
		return -1;
	}

	int diff = abs(leftHeight - rightHeight);

	if (diff > 1)
	{
		return -1;
	}

	return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
}