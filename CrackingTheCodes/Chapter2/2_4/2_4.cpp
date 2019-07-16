#include "2_4.h"

// Partition
void test2_4()
{
	int value;
	int length;
	int stop;
	sNode* head = NULL;

	cout << "Enter the length of the list: ";
	cin >> length;
	cout << endl;
	cout << "Enter the value of the partition: ";
	cin >> value;

	head = createSingleLinkedList(length);
	cout << "Print the list" << endl;
	printSList(head);
	partitionList(head, value);
	printSList(head);

	cin >> stop;
	freeSList(head);
}

// (1) Two pointer, one always points smaller value, one always points bigger/equeal value
// (2) if the position of smaller value > the position of smaller value
//     if not, move the samller pointer to next node, start from step (1)
// (3) Swap the value, then move the samller pointer to next node, then start from step (1)
void partitionList(sNode* head, int value)
{
	sNode* smaller = head;
	sNode* larger = head;
	int smallerPosition = 0;
	int LargerPosition = 0;

	while (true)
	{
		while (larger != NULL && larger->getData() < value)
		{
			larger = larger->getNextNode();
			LargerPosition++;
		}

		while (smaller != NULL && smaller->getData() >= value)
		{
			smaller = smaller->getNextNode();
			smallerPosition++;
		}

		if (smaller == NULL || larger == NULL)
			break;

		if (LargerPosition < smallerPosition)
		{
			swapData(smaller, larger);
		}

		// This movement is important, remove this cause infinite loop. (in the case "LargerPosition >= smallerPosition")
		smaller = smaller->getNextNode();
		smallerPosition++;
	}
}

void swapData(sNode* s1, sNode* s2)
{
	int tmp = s2->getData();
	s2->setData(s1->getData());
	s1->setData(tmp);
}