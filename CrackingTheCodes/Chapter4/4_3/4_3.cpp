#include "4_3.h"

// List of Depths
void test4_3()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7 ,8 };

	TreeNode* treeRoot = createBinaryTree(v, 0, v.size() - 1);

	vector<list<TreeNode*>> levelLists = CreateLevelLists(treeRoot);

	printLevelLists(levelLists);
}

vector<list<TreeNode*>> CreateLevelLists(TreeNode* treeRoot)
{
	vector<list<TreeNode*>> treeLists;
	list<TreeNode*> treeList;

	queue<TreeNode*> qToBeVisited;
	int lastLevel = 0;
	int nextLevel = 0;

	qToBeVisited.push(treeRoot);

	lastLevel++;

	while (qToBeVisited.size() != 0)
	{
		TreeNode* cur = qToBeVisited.front();
		qToBeVisited.pop();
		treeList.push_back(cur);

		lastLevel--;

		TreeNode* left = cur->getLeft();
		TreeNode* right = cur->getRight();

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
			lastLevel = nextLevel;
			nextLevel = 0;

			treeLists.push_back(treeList);
			treeList.clear();
		}
	}

	return treeLists;
}

void printLevelLists(vector<list<TreeNode*>> levelLists)
{
	for (auto it = levelLists.begin(); it != levelLists.end(); ++it)
	{
		list<TreeNode*> curList = (*it);

		while (curList.size() != 0)
		{
			TreeNode* curNode = curList.front();
			curList.pop_front();
			cout << curNode->getValue() << " ";

			free(curNode);
		}

		cout << endl;
	}

	cout << endl;
}