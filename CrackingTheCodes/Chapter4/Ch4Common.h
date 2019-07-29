#pragma once
#include "../Common.h"

typedef pair<int, int> Pair;

// Assume value indicate the id of node, which is unique for each node, and is positive unless root node
class node
{
public:
	int value;

	node(int value)
	{
		this->value = value;
	}

	void SetNextNode(node* n)
	{
		auto result = find_if(nextNodes.begin(), nextNodes.end(), [&n](const node* item) {
			return item->value == n->value;
		});

		if (result != nextNodes.end()) {
			nextNodes.push_back(*result);
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
		return nextNodes;
	}

private:
	vector<node*> nextNodes;


};

// Assume value indicate the id of node, which is unique for each node, and is positive unless root node
// The head nodes (standalone nodes) will not be connected by another nodes.
class graph
{
public:

	graph() {}

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

				if (foundNodeSecond)
				{
					firstNode->SetNextNode(foundNodeSecond);
				}
				else
				{
					node* secondNode = new node(it->second);
					firstNode->SetNextNode(secondNode);
					
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
				}

			}
		}
	}

	void printGraph()
	{

	}

private:
	vector<node*> head;

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

	node* findNode(int target)
	{
		for (auto it = head.begin(); it != head.end(); ++it)
		{
			findNode(target, *it);
		}
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
	}
};