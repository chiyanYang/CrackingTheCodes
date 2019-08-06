#include "4_5.h"

// Validate BST
void test4_5()
{
	vector<int> v{ 1, 2, 3, 10, 5, 6, 7 ,8 };

	TreeNode* treeRoot = createRandomBTree(v, 0, v.size() - 1);

	printBinaryTree(treeRoot);

	bool result = IsBST(treeRoot);

	cout << "IsBST: " << result << endl;
}

bool IsBST(TreeNode* rootNode)
{
	bool resultLeft = true;
	bool resultRight = true;

	TreeNode* left = rootNode->getLeft();
	TreeNode* right = rootNode->getRight();

	int middleValue = rootNode->getValue();
	
	if (left)
	{
		if (left->getValue() > middleValue)
		{
			return false;
		}

		resultLeft = IsBST(left);
	}

	if (right)
	{
		if (right->getValue() <= middleValue)
		{
			return false;
		}

		resultRight = IsBST(right);
	}

	return resultLeft && resultRight;
}