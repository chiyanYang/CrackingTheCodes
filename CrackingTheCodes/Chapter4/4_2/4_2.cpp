#include "4_2.h"

// Minimal Tree
void test4_2()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7 ,8 };

	TreeNode* treeRoot = createMinBST(v, 0, v.size() - 1);

	printTree(treeRoot);
}

TreeNode* createMinBST(vector<int>& v, int start, int end)
{
	if (start > end)
		return NULL;

	int index = start + (end - start) / 2;

	TreeNode* curNode = new TreeNode(v[index]);

	if (start == end)
	{
		return curNode;
	}
	

	TreeNode* left = createMinBST(v, start, index - 1);
	TreeNode* right = createMinBST(v, index + 1, end);

	curNode->setLeftNode(left);
	curNode->setRightNode(right);

	return curNode;
}

void printTree(TreeNode* treeRoot)
{
	queue<TreeNode*> qToBeVisited;
	int lastLevel = 0;
	int nextLevel = 0;
	int spaceCount = 20;

	printSpace(spaceCount);
	spaceCount -= 1;

	qToBeVisited.push(treeRoot);
	lastLevel++;

	while (qToBeVisited.size() != 0)
	{
		TreeNode* cur = qToBeVisited.front();
		qToBeVisited.pop();

		cout << cur->getValue() << " ";

		lastLevel--;

		TreeNode* left = cur->getLeft();
		TreeNode* right = cur->getRight();

		if (right && cur->getValue() > right->getValue())
		{
			cout << "Error: Parent value is greater than right value" << endl;
		}
		else if (left && cur->getValue() < left->getValue())
		{
			cout << "Error: Parent value is smaller than left value" << endl;
		} 
		else if (left && right && left->getValue() > right->getValue())
		{
			cout << "Error: Right value is smaller than left value" << endl;
		}

		if (left)
		{
			qToBeVisited.push(left);
			nextLevel++;
		}

		if (right)
		{
			qToBeVisited.push(right);
			nextLevel++;
		}

		if (lastLevel == 0)
		{
			cout << endl;
			printSpace(spaceCount);
			spaceCount -= 2;

			lastLevel = nextLevel;
			nextLevel = 0;
		}
	}

	cout << endl << endl;
}

void printSpace(int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << " ";
	}
}