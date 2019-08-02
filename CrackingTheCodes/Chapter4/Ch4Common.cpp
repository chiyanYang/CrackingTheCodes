#include "Ch4Common.h"

TreeNode* createBinaryTree(vector<int>& v, int start, int end)
{
	if (start > end)
		return NULL;

	int index = start + (end - start) / 2;

	TreeNode* curNode = new TreeNode(v[index]);

	if (start == end)
	{
		return curNode;
	}


	TreeNode* left = createBinaryTree(v, start, index - 1);
	TreeNode* right = createBinaryTree(v, index + 1, end);

	curNode->setLeftNode(left);
	curNode->setRightNode(right);

	return curNode;
}