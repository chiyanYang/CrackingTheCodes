#pragma once
#include "../Ch4Common.h"

void test4_11();

class TreeNode4_11;
class Tree4_11;

class TreeNode4_11
{
public:
	TreeNode4_11(int v)
	{
		size = 1;
		value = v;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	int getValue()
	{
		return value;
	}

	void setValue(int v)
	{
		value = v;
	}

	TreeNode4_11* getLeft()
	{
		return left;
	}

	TreeNode4_11* getRight()
	{
		return right;
	}

	TreeNode4_11* getParent()
	{
		return parent;
	}

	void setLeftNode(TreeNode4_11* node)
	{
		left = node;

		if (node != NULL)
		{
			node->setParent(this);
		}
	}

	void setRightNode(TreeNode4_11* node)
	{
		right = node;

		if (node != NULL)
		{
			node->setParent(this);
		}
	}

	void setParent(TreeNode4_11* node)
	{
		parent = node;
	}

	int getSize()
	{
		return this->size;
	}

	int setSize(int size)
	{
		this->size = size;
	}

	void addSize()
	{
		this->size++;
	}

	void subSize()
	{
		this->size--;
	}

private:
	int value;
	TreeNode4_11* left;
	TreeNode4_11* right;
	TreeNode4_11* parent;
	int size;
};

class Tree4_11
{
public:
	Tree4_11()
	{
		root = NULL;
	}

	void insertNode(int value)
	{
		if (root == NULL)
		{
			root = new TreeNode4_11(value);
			return;
		}

		bool isAddedToLeft = false;
		TreeNode4_11* parentNode = NULL;
		TreeNode4_11* curNode = root;

		while (curNode != NULL)
		{
			parentNode = curNode;
			parentNode->addSize();

			if (curNode->getValue() < value)
			{
				curNode = curNode->getLeft();
				isAddedToLeft = true;
			}
			else
			{
				curNode = curNode->getRight();
				isAddedToLeft = false;
			}
		}

		curNode = new TreeNode4_11(value);

		if (isAddedToLeft)
		{
			parentNode->setLeftNode(curNode);
		}
		else
		{
			parentNode->setRightNode(curNode);
		}
	}

	// Not update the node size
	void deleteNode(int value)
	{
		TreeNode4_11* nodeToDelete = this->findNode(value);

		if (nodeToDelete == NULL)
		{
			return;
		}

		TreeNode4_11* parentNode = nodeToDelete->getParent();

		if (parentNode == NULL)
		{
			if (nodeToDelete->getRight() == NULL && nodeToDelete->getLeft() == NULL)
			{
				root = NULL;
			}
			if (nodeToDelete->getRight() == NULL)
			{
				root = nodeToDelete->getLeft();
			}
			else if (nodeToDelete->getLeft() == NULL)
			{
				root = nodeToDelete->getRight();
			}
			else
			{
				if (nodeToDelete->getRight()->getLeft() != NULL)
				{
					TreeNode4_11* nodeToMove = this->findLeftMostNode(nodeToDelete->getRight());

					if (nodeToMove->getRight() != NULL)
					{
						nodeToMove->getParent()->setLeftNode(nodeToMove->getRight());
					}
					else
					{
						nodeToMove->getParent()->setLeftNode(NULL);
					}

					nodeToMove->setParent(NULL);

					root = nodeToMove;

					nodeToMove->setLeftNode(nodeToDelete->getLeft());
					nodeToMove->setRightNode(nodeToDelete->getRight());
				}
				else
				{
					root = nodeToDelete->getRight();
					nodeToDelete->getRight()->setLeftNode(nodeToDelete->getLeft());
				}
			}
		}
		else if (nodeToDelete->getRight() != NULL && nodeToDelete->getLeft() != NULL)
		{
			if (nodeToDelete->getRight()->getLeft() != NULL)
			{
				TreeNode4_11* nodeToMove = this->findLeftMostNode(nodeToDelete->getRight());

				if (nodeToMove->getRight() != NULL)
				{
					nodeToMove->getParent()->setLeftNode(nodeToMove->getRight());
				}
				else
				{
					nodeToMove->getParent()->setLeftNode(NULL);
				}
				
				if (parentNode->getLeft() == nodeToDelete)
				{
					parentNode->setLeftNode(nodeToMove);
				}
				else
				{
					parentNode->setRightNode(nodeToMove);
				}

				nodeToMove->setLeftNode(nodeToDelete->getLeft());
				nodeToMove->setRightNode(nodeToDelete->getRight());
			}
			else
			{
				if (parentNode->getLeft() == nodeToDelete)
				{
					parentNode->setLeftNode(nodeToDelete->getRight());
				}
				else
				{
					parentNode->setRightNode(nodeToDelete->getRight());
				}

				nodeToDelete->getRight()->setLeftNode(nodeToDelete->getLeft());
			}
		}
		else if (nodeToDelete->getRight() != NULL && nodeToDelete->getLeft() == NULL)
		{
			if (parentNode->getLeft() == nodeToDelete)
			{
				parentNode->setLeftNode(nodeToDelete->getRight());
			}
			else
			{
				parentNode->setRightNode(nodeToDelete->getRight());
			}
		}
		else if (nodeToDelete->getLeft() != NULL && nodeToDelete->getRight() == NULL)
		{
			if (parentNode->getLeft() == nodeToDelete)
			{
				parentNode->setLeftNode(nodeToDelete->getLeft());
			}
			else
			{
				parentNode->setRightNode(nodeToDelete->getLeft());
			}
		}
		else if (nodeToDelete->getLeft() == NULL && nodeToDelete->getRight() == NULL)
		{
			if (parentNode->getLeft() == nodeToDelete)
			{
				parentNode->setLeftNode(NULL);
			}
			else
			{
				parentNode->setRightNode(NULL);
			}
		}

		free(nodeToDelete);
	}

	TreeNode4_11* findNode(int value)
	{	
		TreeNode4_11* curNode = root;

		while (curNode != NULL)
		{
			if (curNode->getValue() < value)
			{
				curNode = curNode->getLeft();
			}
			else if (curNode->getValue() > value)
			{
				curNode = curNode->getRight();
			}
			else
			{
				return curNode;
			}
		}

		return curNode;
	}

	TreeNode4_11* getRandomNode()
	{
		int totalNodeCounts = root->getSize();
		/* initialize random seed: */
		srand(time(NULL));

		int randomNum = rand() % totalNodeCounts + 1; // Count from 1 instead of 0

		cout << "Random Num = " << randomNum << endl << endl;

		return getRandomNode(root, randomNum);
	}

	void printTree()
	{
		queue<TreeNode4_11*> qToBeVisited;
		int lastLevel = 0;
		int nextLevel = 0;
		int spaceCount = 20;
		bool isCurrentLevelHasNode = false;
		bool isNextLevelHasNode = false;

		printSpace(spaceCount);
		spaceCount -= 1;

		qToBeVisited.push(this->root);
		lastLevel++;
		isCurrentLevelHasNode = true;

		while (qToBeVisited.size() != 0)
		{
			TreeNode4_11* cur = qToBeVisited.front();
			qToBeVisited.pop();

			cout << cur->getValue() << " ";

			lastLevel--;

			if (cur->getValue() != 0 || isCurrentLevelHasNode == true)
			{
				TreeNode4_11* left = cur->getLeft();
				TreeNode4_11* right = cur->getRight();

				if (left)
				{
					qToBeVisited.push(left);
					isNextLevelHasNode = true;
				}
				else
				{
					qToBeVisited.push(this->createZeroTreeNode());
				}

				if (right)
				{
					qToBeVisited.push(right);
					isNextLevelHasNode = true;
				}
				else
				{
					qToBeVisited.push(this->createZeroTreeNode());
				}

				nextLevel += 2;
			}

			if (lastLevel == 0)
			{
				cout << endl;

				this->printSpace(spaceCount);
				spaceCount -= 2;

				lastLevel = nextLevel;
				nextLevel = 0;

				isCurrentLevelHasNode = isNextLevelHasNode;
				isNextLevelHasNode = false;
			}
		}

		cout << endl << endl;
	}

private:
	TreeNode4_11* root;

	TreeNode4_11* findLeftMostNode(TreeNode4_11* node)
	{
		TreeNode4_11* curNode = node;

		while (curNode != NULL && curNode->getLeft() != NULL)
		{
			curNode = curNode->getLeft();
		}

		return curNode;
	}

	void printSpace(int num)
	{
		for (int i = 0; i < num; i++)
		{
			cout << " ";
		}
	}

	TreeNode4_11* createZeroTreeNode()
	{
		return new TreeNode4_11(0);
	}

	TreeNode4_11* getRandomNode(TreeNode4_11* curNode, int randomNum)
	{
		int totalNodeCounts = curNode->getSize();

		int leftCount = 0; 
		if (curNode->getLeft())
		{
			leftCount = curNode->getLeft()->getSize();
		}

		int rightCount = 0;
		if (curNode->getRight())
		{
			rightCount = curNode->getRight()->getSize();
		}

		if (randomNum <= leftCount)
		{
			return getRandomNode(curNode->getLeft(), randomNum);
		}
		else if (randomNum == leftCount + 1)
		{
			return curNode;
		}
		else
		{
			return getRandomNode(curNode->getRight(), randomNum - leftCount - 1);
		}
	}
};