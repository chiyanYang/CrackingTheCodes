#include "4_10.h"

// Check Subtree
void test4_10()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	TreeNode* t1 = createRandomBTree(v, 0, v.size() - 1);

	printBinaryTree(t1);

	TreeNode* t2 = getRandomNodeInTree(t1);

	printBinaryTree(t2);

	bool result = CheckSubtree(t1, t2);

	cout << "result = " << result << endl << endl;
}

bool CheckSubtree(TreeNode* t1, TreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
	{
		return true;
	}

	if (t1 == NULL || t2 == NULL)
	{
		return false;
	}

	bool isSubTree = false;

	if (t1->getValue() == t2->getValue())
	{
		bool isSubTree = isSubtreeStartsCurNode(t1, t2);
		if (isSubTree == true)
		{
			return true;
		}
	}
	else
	{
		isSubTree = CheckSubtree(t1->getLeft(), t2);
		
		if (isSubTree == true)
		{
			return true;
		}

		isSubTree = CheckSubtree(t1->getRight(), t2);
		
		if (isSubTree == true)
		{
			return true;
		}
	}

	return isSubTree;
}

bool isSubtreeStartsCurNode(TreeNode* t1, TreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
	{
		return true;
	}

	if (t1 == NULL || t2 == NULL)
	{
		return false;
	}

	if (t1->getValue() != t2->getValue())
	{
		return false;
	}

	bool isSubtree = isSubtreeStartsCurNode(t1->getLeft(), t2->getLeft());

	if (isSubtree == false)
	{
		return false;
	}

	isSubtree = isSubtreeStartsCurNode(t1->getRight(), t2->getRight());

	if (isSubtree == false)
	{
		return false;
	}

	return true;
}