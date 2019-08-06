#pragma once
#include "../Common.h"

typedef pair<int, int> Pair;

class TreeNode;
TreeNode* createBinaryTree(vector<int>& v, int start, int end);
TreeNode* createRandomBTree(vector<int>& v, int start, int end);

void printSpace(int num);
void printBinaryTree(TreeNode* rootNode);
TreeNode* createZeroTreeNode();

enum status
{
	NotVisited,
	Visiting, // For nodes in Queue
	Visited,
};

// Assume value indicate the id of node, which is unique for each node, and is positive unless root node
class node
{
public:
	int value;
	status state;

	node(int value)
	{
		this->value = value;
		state = NotVisited;
	}

	void SetNextNode(node* n)
	{
		auto result = find_if(nextNodes.begin(), nextNodes.end(), [&n](const node* item) {
			return item->value == n->value;
		});

		if (result == nextNodes.end()) {
			nextNodes.push_back(n);
		}
	}

	void SetNextNodes(vector<node*> nodes)
	{
		for (auto it = nextNodes.begin(); it != nextNodes.end(); ++it) {
			this->SetNextNode(*it);
		}
	}

	vector<node*> adjacent()
	{
		return this->nextNodes;
	}

private:
	vector<node*> nextNodes;
};

// Assume value indicate the id of node, which is unique for each node, and is positive unless root node
// Directed Graph
// The head nodes (standalone nodes) will not be connected by another nodes.
class directedGraph
{
public:

	directedGraph() {}

	void addGraph(vector<Pair>& v)
	{
		for (auto it = v.begin(); it != v.end(); ++it) {

			if (isRootNode(it->second))
			{
				cout << "Error: root node can not be connected" << endl;
				cout << it->first << " -> " << it->second << endl;
				continue;
			}

			node* foundNodeFirst = findNode(it->first);
			node* foundNodeSecond = findNode(it->second);

			if (!foundNodeFirst)
			{
				node* firstNode = new node(it->first);

				head.push_back(firstNode);
				debugHead.push_back(firstNode);

				if (foundNodeSecond)
				{
					firstNode->SetNextNode(foundNodeSecond);
				}
				else
				{
					node* secondNode = new node(it->second);
					firstNode->SetNextNode(secondNode);

					debugHead.push_back(secondNode);
				}
			}
			else // found foundNodeFirst
			{
				if (foundNodeSecond)
				{
					foundNodeFirst->SetNextNode(foundNodeSecond);
				}
				else
				{
					node* secondNode = new node(it->second);
					foundNodeFirst->SetNextNode(secondNode);

					debugHead.push_back(secondNode);
				}
			}
		}
	}

	void printGraph()
	{
		for (auto it = debugHead.begin(); it != debugHead.end(); ++it)
		{
			node* curNode = *it;
			cout << "Node: " << curNode->value << "-> ";

			printAdj(curNode);
		}
	}

	void printAdj(node* curNode)
	{
		vector<node*> curNodeAdj = curNode->adjacent();
		for (auto it = curNodeAdj.begin(); it != curNodeAdj.end(); ++it)
		{
			cout << (*it)->value << " ";
		}

		cout << endl;
	}

	void resetNodeState()
	{
		for (auto it = debugHead.begin(); it != debugHead.end(); ++it)
		{
			(*it)->state = NotVisited;
		}
	}

	node* findNode(int target)
	{
		for (auto it = head.begin(); it != head.end(); ++it)
		{
			node* targetNode = findNode(target, (*it));
			if (targetNode)
			{
				return targetNode;
			}
		}

		return NULL;
	}

	~directedGraph()
	{
		for (auto it = debugHead.begin(); it != debugHead.end(); ++it)
		{
			free((*it));
		}
	}

private:
	vector<node*> head;

	// Store all the nodes for debug purpose
	vector<node*> debugHead;

	bool isRootNode(int target)
	{
		for (auto it = head.begin(); it != head.end(); ++it)
		{
			if ((*it)->value == target)
			{
				return true;
			}
		}

		return false;
	}

	node* findNode(int target, node* root)
	{
		if (root->value == target)
			return root;

		vector<node*> adj = root->adjacent();

		for (auto it = adj.begin(); it != adj.end(); ++it) {
			node* targetNode = findNode(target, *it);
			if (targetNode)
			{
				return targetNode;
			}
		}

		return NULL;
	}
};


class TreeNode
{
public:
	TreeNode(int v)
	{
		value = v;
	}

	int getValue()
	{
		return value;
	}

	void setValue(int v)
	{
		value = v;
	}

	TreeNode* getLeft()
	{
		return left;
	}

	TreeNode* getRight()
	{
		return right;
	}

	void setLeftNode(TreeNode* node)
	{
		left = node;
	}

	void setRightNode(TreeNode* node)
	{
		right = node;
	}

private:
	int value;
	TreeNode* left;
	TreeNode* right;
};