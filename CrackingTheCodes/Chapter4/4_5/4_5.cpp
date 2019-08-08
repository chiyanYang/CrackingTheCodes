#include "4_5.h"

// Validate BST
void test4_5()
{
	vector<int> v{ 1, 2, 3, 9, 5, 6, 7 ,8 };

	TreeNode* treeRoot = createRandomBTree(v, 0, v.size() - 1);

	printBinaryTree(treeRoot);

	bool result = IsBST(treeRoot);

	cout << "IsBST: " << result << endl;
}

bool IsBST(TreeNode* rootNode)
{
	int lastValue = INT_MIN;
	return InOrderTraversal(rootNode, lastValue);
}

bool InOrderTraversal(TreeNode* rootNode, int& lastValue)
{
	bool resultLeft = true;
	bool resultRight = true;

	TreeNode* left = rootNode->getLeft();

	if (left)
	{
		resultLeft = InOrderTraversal(left, lastValue);
	}

	if (rootNode->getValue() <= lastValue)
	{
		return false;
	}

	lastValue = rootNode->getValue();
	
	TreeNode* right = rootNode->getRight();

	if (right)
	{
		resultRight = InOrderTraversal(right, lastValue);
	}

	return resultLeft && resultRight;
}