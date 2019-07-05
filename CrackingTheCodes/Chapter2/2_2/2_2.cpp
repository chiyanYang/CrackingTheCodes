#include "2_2.h"

// Return Kth to Last
void test2_2()
{
	int length;
	int kth;
	int stop;
	sNode* head = NULL;
	sNode* kthNode = NULL;

	cout << "Enter the length of the list: ";
	cin >> length;
	cout << "Enter the kth: ";
	cin >> kth;
	cout << endl;

	head = createSingleLinkedList(length);
	cout << "Print the list" << endl;
	printSList(head);
	kthNode = findKthToLast(head, kth);
	cout << kth << "th Node = " << kthNode->getData() << endl;

	cin >> stop;
	freeSList(head);
}

sNode* findKthToLast(sNode* head, int k)
{
	int count = 1;
	sNode* front = head;
	sNode* kth = head;

	while (front != NULL && front->getNextNode() != NULL && count < k)
	{
		front = front->getNextNode();
		count++;
	}
	while (front != NULL && front->getNextNode() != NULL)
	{
		front = front->getNextNode();
		kth = kth->getNextNode();
	}

	return kth;
}