#include "2_3.h"

// Delete Middle Node
void test2_3()
{
	int length;
	int stop;
	sNode* head = NULL;

	cout << "Enter the length of the list: ";
	cin >> length;
	cout << endl;

	head = createSingleLinkedList(length);
	cout << "Print the list" << endl;
	printSList(head);
    RemoveMiddleNode(head);
	printSList(head);

	cin >> stop;
	freeSList(head);
}

void RemoveMiddleNode(sNode* head)
{
	sNode* front = head;
	sNode* middle = head;
	sNode* middlePre = NULL;

	while (front != NULL && front->getNextNode() != NULL && front->getNextNode()->getNextNode() != NULL)
	{
		front = front->getNextNode()->getNextNode();
		middlePre = middle;
		middle = middle->getNextNode();
	}

	if (middlePre != NULL)
	{
		cout << "Middle Node = " << middle->getData() << endl;
		removeCurSNode(middlePre, middle);
	}
}