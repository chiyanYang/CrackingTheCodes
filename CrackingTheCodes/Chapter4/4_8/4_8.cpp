#include "4_8.h"

// First Common Ancestor
void test4_8()
{
	vector<int> v{ 1, 2, 3, 9, 5, 6, 7 ,8, 11, 13, 14, 16 };

	TreeNode* treeRoot = createRandomBTree(v, 0, v.size() - 1);

	printBinaryTree(treeRoot);
	
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(7);

	TreeNode* commonAncestorNode = findCommanAncester(treeRoot, node1, node2);

	if (commonAncestorNode == NULL)
	{
		cout << "No common Ancestor" << endl << endl;
	}
	else
	{
		cout << "Common Ancestor is: " << commonAncestorNode->getValue() << endl << endl;
	}

	delete node1;
	delete node2;
}

TreeNode* findCommanAncester(TreeNode* treeRoot, TreeNode* node1, TreeNode* node2)
{
	if (treeRoot == NULL || node1 == NULL || node2 == NULL)
	{
		return NULL;
	}

	TreeNode* leftResult = findCommanAncester(treeRoot->getLeft(), node1, node2);
	TreeNode* rightResult = findCommanAncester(treeRoot->getRight(), node1, node2);

	if (leftResult != NULL && rightResult != NULL)
	{
		return treeRoot;
	}
	else if (leftResult != NULL && rightResult == NULL)
	{
		return leftResult;
	}
	else if (rightResult != NULL && leftResult == NULL)
	{
		return rightResult;
	}

	if (treeRoot->getValue() == node1->getValue() || treeRoot->getValue() == node2->getValue())
	{
		return treeRoot;
	}

	return NULL;
}