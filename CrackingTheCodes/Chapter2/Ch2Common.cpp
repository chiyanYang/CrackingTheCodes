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

sNode* removeCurSNode(sNode* pre, sNode* cur)
{
	if (pre == NULL || cur == NULL)
		return pre;

	sNode* tmp = cur;
	cur = cur->getNextNode();
	pre->setNextNode(cur);

	free(tmp);
	return pre;
}

sNode* reverseList(sNode* head)
{
	sNode* cur = head;
	sNode* pre = NULL;
	sNode* next = cur->getNextNode();

	while (next != NULL)
	{
		cur->setNextNode(pre);

		pre = cur;
		cur = next;
		next = cur->getNextNode();
	}

	cur->setNextNode(pre);

	return cur;
}

sNode* copyList(sNode* head)
{
	if (head == NULL)
		return NULL;

	sNode* copiedList = new sNode(head->getData());
	sNode* cur = copiedList;

	head = head->getNextNode();

	while (head != NULL)
	{
		sNode* copiedNode = new sNode(head->getData());
		cur->setNextNode(copiedNode);
		cur = cur->getNextNode();
		head = head->getNextNode();
	}

	return copiedList;
}

sNode* createSingleLinkedListWithPalindrome(int length)
{
	srand(time(NULL));  // Initialize random number generator.

	sNode *head = new sNode(rand() % 10);
	sNode *tmp = head;

	int middle = length / 2;
	for (int i = 1; i < middle; i++)
	{
		int data = rand() % 10;
		sNode* cur = new sNode(data);
		tmp->setNextNode(cur);
		tmp = cur;
	}

	sNode *copiedList = copyList(head);
	sNode *reversedList = reverseList(copiedList);

	if (length % 2 == 1)
	{
		int data = rand() % 10;
		sNode* cur = new sNode(data);
		tmp->setNextNode(cur);
		tmp = cur;
	}

	tmp->setNextNode(reversedList);

	return head;
}

// Create intersection list, the node which is intersection, the value is set to -1 for debugging purpose.
pair<sNode*, sNode*> createSingleLinkedListWithIntersection(int length)
{
	srand(time(NULL));  // Initialize random number generator.

	pair<sNode*, sNode*>* twoLists = NULL;
	sNode *head1 = new sNode(rand() % 10);
	sNode *tmp1 = head1;

	int interSecNodeLoc = rand() % length; // the location of the intersection node
	
	cout << "intersection node location is at: " << interSecNodeLoc << endl;

	for (int i = 1; i < length; i++)
	{
		int data = rand() % 10;
		sNode* cur = new sNode(data);
		tmp1->setNextNode(cur);
		tmp1 = cur;
	}

	sNode *head2;
	sNode *tmp2;

	if (interSecNodeLoc != 0)
	{
		head2 = new sNode(rand() % 10);
		tmp2 = head2;
		tmp1 = head1;

		for (int i = 1; i < length; i++)
		{
			tmp1 = tmp1->getNextNode();
			if (i == interSecNodeLoc)
			{
				tmp2->setNextNode(tmp1);
				tmp1->setData(-1);
				break;
			}

			int data = rand() % 10;
			sNode* cur = new sNode(data);
			tmp2->setNextNode(cur);
			tmp2 = cur;
		}
	}
	else
	{
		head2 = head1;
		head2->setData(-1);
	}

	return make_pair(head1, head2);;
}

void freeSListsWithIntersection(sNode* list1, sNode* list2)
{
	// to be done
}