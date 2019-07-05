#include "Ch2Common.h"

int sNode::getData()
{
	return this->data;
}

void sNode::setData(int data)
{
	this->data = data;
}

sNode* sNode::getNextNode()
{
	return this->next;
}

void sNode::setNextNode(sNode* node)
{
	this->next = node;
}

sNode::sNode(int data)
{
	this->data = data;
}

sNode* createSingleLinkedList(int length)
{
	srand(time(NULL));  // Initialize random number generator.
	
	sNode *head = new sNode(rand() % 10);
	sNode *tmp = head;

	for (int i = 1; i < length; i++)
	{
		int data = rand() % 10;
		sNode* cur = new sNode(data);
		tmp->setNextNode(cur);
		tmp = cur;
	}

	return head;
}

void printSList(sNode* cur)
{
	while (cur != NULL)
	{
		cout << cur->getData();
		cur = cur->getNextNode();
		if (cur != NULL)
		{
			cout << " -> ";
		}
	}
	cout << endl;
}

void freeSList(sNode* cur)
{
	while (cur != NULL)
	{
		sNode* tmp = cur;
		cur = cur->getNextNode();
		free(tmp);
	}
}