#include "4_1.h"

// Route Between Nodes
void test4_1()
{
	directedGraph g;
	vector<Pair> v;
	v.push_back(make_pair(0, 1));
	v.push_back(make_pair(0, 2));
	v.push_back(make_pair(0, 3));

	v.push_back(make_pair(1, 4));
	v.push_back(make_pair(1, 5));

	v.push_back(make_pair(5, 6));

	v.push_back(make_pair(6, 4));

	v.push_back(make_pair(3, 7));
	v.push_back(make_pair(3, 8));

	v.push_back(make_pair(7, 9));

	v.push_back(make_pair(8, 10));

	v.push_back(make_pair(9, 6));
	/*
	             0
	    1        2        3
	 [4   5]           [7     8]
	     [6]           [9]  [10]
	     [*4]          [6*]
		 
    Note: *means loop back
	*/
	g.addGraph(v);
	g.printGraph();
	cout << endl;

	int n1;
	int n2;

	cout << "Enter the start: ";
	cin >> n1;
	cout << "Enter the end: ";
	cin >> n2;
	cout << endl;

	bool result = existRouteInTwoNodes_UseQueue(g, n1, n2);

	cout << "Does connection exist: " << result << endl << endl;
}

bool existRouteInTwoNodes(directedGraph &g, int n1, int n2)
{
	node* nodeStart = g.findNode(n1);
	node* nodeEnd = g.findNode(n2);

	if (!nodeStart || !nodeEnd)
	{
		cout << "Nodes not exist" << endl;
		return false;
	}

	bool resultStart = existConnection(nodeStart, n2);
	bool resultEnd = existConnection(nodeEnd, n1);

	return resultStart || resultEnd;
}

bool existConnection(node* nodeStart, int target)
{
	if (nodeStart->value == target)
		return true;

	if (nodeStart->state == Visited)
		return false;

	nodeStart->state = Visited;

	vector<node*> adjNodeStart = nodeStart->adjacent();

	for (auto it = adjNodeStart.begin(); it != adjNodeStart.end(); ++it)
	{
		if (existConnection((*it), target))
			return true;
	}

	return false;
}

bool existRouteInTwoNodes_UseQueue(directedGraph &g, int n1, int n2)
{
	bool resultStart = existConnection_UseQueue(g, n1, n2);

	g.resetNodeState();

	bool resultEnd = existConnection_UseQueue(g, n2, n1);

	return resultStart || resultEnd;
}

bool existConnection_UseQueue(directedGraph &g, int n1, int n2)
{
	queue<node*> qToBeVisited;

	node* nodeStart = g.findNode(n1);
	node* nodeEnd = g.findNode(n2);

	nodeStart->state = Visiting;

	qToBeVisited.push(nodeStart);

	while (qToBeVisited.size() != 0)
	{
		node* cur = qToBeVisited.front();
		qToBeVisited.pop();

		if (cur == nodeEnd)
		{
			return true;
		}

		cur->state = Visited;

		vector<node*> adj = cur->adjacent();

		for (auto it = adj.begin(); it != adj.end(); ++it)
		{
			if ((*it)->state == NotVisited)
			{
				(*it)->state = Visiting;
				qToBeVisited.push((*it));
			}
		}
	}

	return false;
}
