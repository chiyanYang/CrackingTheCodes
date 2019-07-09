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
		tmp->setNextNode(NULL); // Make sure the pointer set to NULL, in case of free this list twice
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
// length1 is the length of list1, length2 is the length of list2 but intersection nde and the following nodes not included.
pair<sNode*, sNode*> createSingleLinkedListWithIntersection(int length1, int length2)
{
	srand(time(NULL));  // Initialize random number generator.

	pair<sNode*, sNode*>* twoLists = NULL;
	sNode *head1 = new sNode(rand() % 10);
	sNode *tmp1 = head1;

	int interSecNodeLoc = rand() % length1; // the location of the intersection node in list1
	
	cout << "intersection node location is at: " << interSecNodeLoc << endl;

	for (int i = 1; i < length1; i++)
	{
		int data = rand() % 10;
		sNode* cur = new sNode(data);
		tmp1->setNextNode(cur);
		tmp1 = cur;
	}

	sNode *head2;
	sNode *tmp2;

	if (length2 == 0) // list2 is all in list1
	{
		tmp1 = head1;

		for (int i = 0; i < interSecNodeLoc; i++)
		{
			tmp1 = tmp1->getNextNode();
		}

		head2 = tmp1;
		head2->setData(-1);
	}
	else if (interSecNodeLoc == 0) // list1 head node is the intersection node, and list2 tail node' next node is list1 head node.
	{
		head2 = new sNode(rand() % 10);
		tmp2 = head2;

		for (int i = 1; i < length2; i++)
		{
			int data = rand() % 10;
			sNode* cur = new sNode(data);
			tmp2->setNextNode(cur);
			tmp2 = cur;
		}

		tmp2->setNextNode(head1);
		head1->setData(-1);
	}
	else
	{
		// Build list2
		head2 = new sNode(rand() % 10);
		tmp2 = head2;

		for (int i = 1; i < length2; i++)
		{
			int data = rand() % 10;
			sNode* cur = new sNode(data);
			tmp2->setNextNode(cur);
			tmp2 = cur;
		}

		tmp1 = head1;

		// Get the pointer to the intersection node
		for (int i = 0; i < interSecNodeLoc; i++)
		{
			tmp1 = tmp1->getNextNode();
		}

		// tmp1 is the intersection node
		tmp2->setNextNode(tmp1);
		tmp1->setData(-1);
	}

	return make_pair(head1, head2);;
}

void freeSListsWithIntersection(sNode* list1, sNode* list2)
{
	// to be done later
}