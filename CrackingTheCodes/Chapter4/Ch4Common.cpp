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

TreeNode* getRandomNodeInTree(TreeNode* rootNode)
{
	int totalNumOfNode = getTotalNumOfNode(rootNode);

	/* initialize random seed: */
	srand(time(NULL));

	int randomNum = rand() % totalNumOfNode;

	return getNodeByNumber(rootNode, randomNum);
}

int getTotalNumOfNode(TreeNode* rootNode)
{
	if (rootNode == NULL)
	{
		return 0;
	}

	int count = 1;

	count += getTotalNumOfNode(rootNode->getLeft());
	count += getTotalNumOfNode(rootNode->getRight());

	return count;
}

// pre-order sequence
TreeNode* getNodeByNumber(TreeNode* rootNode, int& num)
{
	if (rootNode == NULL || num == 0)
	{
		return rootNode;
	}

	num--;

	TreeNode* result = getNodeByNumber(rootNode->getLeft(), num);

	if (result == NULL)
	{
		result = getNodeByNumber(rootNode->getRight(), num);
	}

	return result;
}

// Node with zero value is used for redundant purpose, so don't insert value zeor node in the tree
void printBinaryTree(TreeNode* treeRoot)
{
	if (treeRoot == NULL)
	{
		cout << "NULL" << endl << endl;
		return;
	}

	queue<TreeNode*> qToBeVisited;
	int lastLevel = 0;
	int nextLevel = 0;
	int spaceCount = 20;
	bool isCurrentLevelHasNode = false;
	bool isNextLevelHasNode = false;

	printSpace(spaceCount);
	spaceCount -= 1;

	qToBeVisited.push(treeRoot);
	lastLevel++;
	isCurrentLevelHasNode = true;

	while (qToBeVisited.size() != 0)
	{
		TreeNode* cur = qToBeVisited.front();

		qToBeVisited.pop();

		cout << cur->getValue() << " ";

		lastLevel--;

		if (cur->getValue() != 0 || isCurrentLevelHasNode == true)
		{
			TreeNode* left = cur->getLeft();
			TreeNode* right = cur->getRight();

			if (left != NULL)
			{
				qToBeVisited.push(left);
				isNextLevelHasNode = true;
			}
			else
			{
				qToBeVisited.push(createZeroTreeNode());
			}

			if (right != NULL)
			{
				qToBeVisited.push(right);
				isNextLevelHasNode = true;
			}
			else
			{
				qToBeVisited.push(createZeroTreeNode());
			}

			nextLevel += 2;
		}

		if (lastLevel == 0)
		{
			cout << endl;

			printSpace(spaceCount);
			spaceCount -= 2;

			lastLevel = nextLevel;
			nextLevel = 0;

			isCurrentLevelHasNode = isNextLevelHasNode;
			isNextLevelHasNode = false;
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

void freeTree(TreeNode* curNode)
{
	if (curNode == NULL)
	{
		return;
	}

	freeTree(curNode->getLeft());
	freeTree(curNode->getRight());

	delete curNode;
}