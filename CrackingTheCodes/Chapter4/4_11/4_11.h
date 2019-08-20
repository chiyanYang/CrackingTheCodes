#pragma once
#include "../Ch4Common.h"

void test4_11();

class TreeNode4_11;
class Tree4_11;

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

private:
	TreeNode4_11* root;
};

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