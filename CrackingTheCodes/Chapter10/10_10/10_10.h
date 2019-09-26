#pragma once
#include "../Ch10Common.h"

void test10_10();

class treeNode;

void track(treeNode* root, int target);
int getRankOfNumber(treeNode* root, int target);

class treeNode
{
public:
	treeNode(int value)
	{
		this->value = value;
	}

	int getValue()
	{
		return this->value;
	}

	void addLeftTreeCount()
	{
		leftNodeCount++;
	}

	int getLeftTreeCount()
	{
		return leftNodeCount;
	}

	void setSubNode(treeNode* targetNode, int direction)
	{
		if (direction == 0)
		{
			leftNode = targetNode;
		}
		else
		{
			rightNode = targetNode;
		}
	}

	treeNode* getSubNode(int direction)
	{
		if (direction == 0)
		{
			return this->leftNode;
		}
		else
		{
			return this->rightNode;
		}
	}

	static void printTree(treeNode* root)
	{
		if (root != NULL)
		{
			if (root->getSubNode(0) != NULL)
			{
				treeNode* curNode = root->getSubNode(0);
				printTree(curNode);
			}

			cout << root->getValue() << endl;

			if (root->getSubNode(1) != NULL)
			{
				treeNode* curNode = root->getSubNode(1);
				printTree(curNode);
			}
		}
	}

	static void freeTree(treeNode* root)
	{
		if (root != NULL)
		{
			if (root->getSubNode(0) != NULL)
			{
				treeNode* curNode = root->getSubNode(0);
				freeTree(curNode);
				delete curNode;
			}

			if (root->getSubNode(1) != NULL)
			{
				treeNode* curNode = root->getSubNode(0);
				freeTree(curNode);
				delete curNode;
			}

			delete root;
		}
	}

private:
	int value;
	int leftNodeCount = 0;
	treeNode* leftNode = NULL;
	treeNode* rightNode = NULL;

};