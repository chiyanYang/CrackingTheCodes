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
				TreeNode4_11* nodeToMove = this->findLeftMostNode(nodeToDelete);


			}
		}
		else if (nodeToDelete->getRight() != NULL)
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
		return NULL;
	}

	void printTree()
	{
		queue<TreeNode4_11*> qToBeVisited;
		int lastLevel = 0;
		int nextLevel = 0;
		int spaceCount = 20;

		printSpace(spaceCount);
		spaceCount -= 1;

		qToBeVisited.push(this->root);
		lastLevel++;

		while (qToBeVisited.size() != 0)
		{
			TreeNode4_11* cur = qToBeVisited.front();
			qToBeVisited.pop();

			cout << cur->getValue() << " ";

			lastLevel--;

			if (cur->getValue() != 0)
			{
				TreeNode4_11* left = cur->getLeft();
				TreeNode4_11* right = cur->getRight();

				if (left)
				{
					qToBeVisited.push(left);
				}
				else
				{
					qToBeVisited.push(this->createZeroTreeNode());
				}

				if (right)
				{
					qToBeVisited.push(right);
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
};