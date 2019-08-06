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

TreeNode* createRandomBTree(vector<int>& v, int start, int end)
{
	if (start > end)
		return NULL;

	/* initialize random seed: */
	srand(time(NULL));

	int range = end - start + 1;
	int randomNum = rand() % range;

	int index = start + randomNum;

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

void printBinaryTree(TreeNode* treeRoot)
{
	queue<TreeNode*> qToBeVisited;
	int lastLevel = 0;
	int negCount = 0;
	int nextLevel = 0;
	int spaceCount = 20;

	printSpace(spaceCount);
	spaceCount -= 1;

	qToBeVisited.push(treeRoot);
	lastLevel++;
	negCount++;

	while (qToBeVisited.size() != 0)
	{
		TreeNode* cur = qToBeVisited.front();
		qToBeVisited.pop();

		cout << cur->getValue() << " ";

		lastLevel--;

		if (cur->getValue() == 0)
		{
			negCount--;
		}

		TreeNode* left = cur->getLeft();
		TreeNode* right = cur->getRight();

		if (left)
		{
			qToBeVisited.push(left);
		}
		else
		{
			qToBeVisited.push(createZeroTreeNode());
		}

		if (right)
		{
			qToBeVisited.push(right);
		}
		else
		{
			qToBeVisited.push(createZeroTreeNode());
		}

		nextLevel += 2;

		if (lastLevel == 0)
		{
			cout << endl;

			if (negCount == 0)
			{
				cout << endl;
				return;
			}

			printSpace(spaceCount);
			spaceCount -= 2;

			lastLevel = nextLevel;
			negCount = nextLevel;
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

TreeNode* createZeroTreeNode()
{
	return new TreeNode(0);
}