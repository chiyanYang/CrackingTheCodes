#include "10_10.h"

// Rank from Stream
void test10_10()
{
	int target;

	cout << "Enter the value: ";
	cin >> target;
	cout << endl;

	treeNode* root = new treeNode(target);
	int method;

	while (true)
	{
		cout << "Enter the method, 0 for track, others for rank: ";
		cin >> method;
		cout << endl;

		if (method == 0)
		{
			cout << "Enter the value: ";
			cin >> target;
			cout << endl;

			track(root, target);
			treeNode::printTree(root);
		}
		else
		{
			cout << "Enter the value: ";
			cin >> target;
			cout << endl;

			int rank = getRankOfNumber(root, target);

			cout << "rank = " << rank << endl;
		}
	}

	treeNode::freeTree(root);
}

void track(treeNode* root, int target)
{
	treeNode* newNode = new treeNode(target);

	while (true)
	{
		if (root->getValue() >= target)
		{
			root->addLeftTreeCount();

			if (root->getSubNode(0) == NULL)
			{
				root->setSubNode(newNode, 0);
				break;
			}

			root = root->getSubNode(0);
		}
		else
		{
			if (root->getSubNode(1) == NULL)
			{
				root->setSubNode(newNode, 1);
				break;
			}

			root = root->getSubNode(1);
		}
	}
}

int getRankOfNumber(treeNode* root, int target)
{
	int count = 0;

	while (true)
	{
		if (root->getValue() > target)
		{
			if (root->getSubNode(0) == NULL)
			{
				return -1;
			}

			root = root->getSubNode(0);
		}
		else if (root->getValue() < target)
		{
			if (root->getSubNode(1) == NULL)
			{
				return -1;
			}

			count = count + root->getLeftTreeCount() + 1;

			root = root->getSubNode(1);
		}
		else
		{
			count = count + root->getLeftTreeCount();

			return count;
		}
	}
}