#include "4_6.h"

// Successor
void test4_6()
{
	vector<int> v{ 1, 2, 3, 9, 5, 6, 7 ,8 };

	TreeNode* treeRoot = createRandomBTree(v, 0, v.size() - 1);

	printBinaryTree(treeRoot);

	TreeNode* result = findNextNode(treeRoot);

	if (result == NULL)
	{
		cout << "No next Node" << endl;
	}
	else
	{
		cout << "NextNode: " << result->getValue() << endl;
	}
}

TreeNode* findNextNode(TreeNode* curNode)
{
	int type = -1;

	TreeNode* left = curNode->getLeft();
	TreeNode* right = curNode->getRight();
	TreeNode* parent = curNode->getParent();
	TreeNode* parentLeft = NULL;
	TreeNode* parentRight = NULL;

	if (parent)
	{
		parentLeft = parent->getLeft();
		parentRight = parent->getRight();
	}
	

	if (left == NULL && right == NULL && parentLeft == curNode)
	{
		type = 1;
	}
	else if (left == NULL && right == NULL && parentRight == curNode)
	{
		type = 2;
	}
	else if (left == NULL)
	{
		type = 3;
	}
	else if (right == NULL)
	{
		type = 1;
	}
	else
	{
		type = 3;
	}

	switch (type)
	{
		case 1: return parent;
		case 2: return findAncesterMatchLeft(curNode);
		case 3: return leftMostNode(right);
		default: cout << "There is an error" << endl << endl;
				 return NULL;
	}
}

// Find the node, which is the node ancester, and the node is the ancester's left node. 
TreeNode* findAncesterMatchLeft(TreeNode* curNode)
{
	TreeNode* parent = curNode->getParent();

	if (parent == NULL)
	{
		return NULL;
	}

	TreeNode* parentLeft = parent->getLeft();
	TreeNode* parentRight = parent->getRight();

	if (parentLeft == curNode)
	{
		return parentLeft;
	}

	// parentRight == curNode
	return findAncesterMatchLeft(parent);
}

TreeNode* leftMostNode(TreeNode* curNode)
{
	TreeNode* leftNode = curNode->getLeft();

	if (leftNode == NULL)
	{
		return curNode;
	}

	return leftMostNode(leftNode);
}