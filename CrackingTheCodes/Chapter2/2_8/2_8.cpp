#include "2_8.h"

// Loop Detection
void test2_8()
{
	int length;
	int stop;
	sNode* head = NULL;

	cout << "Enter the length of the list: ";
	cin >> length;
	cout << endl;

	head = createSingleLinkedListWithLoop(length);
	cout << "Print the list" << endl;
	printSListWithLoop(head);

	sNode* loopNode = loopDetection(head);
	cout << "Loop node data(should be -1): " << loopNode->getData() << endl << endl;
	freeSListsWithLoop(head);
}

sNode* loopDetection(sNode* list)
{
	if (list == NULL)
		return NULL;

	bool isLoop = false;
	int countSlow = 1;
	int countFast = 2;
	sNode* slow = list;
	sNode* fast = list;
	fast = list->getNextNode();

	if (fast == slow)
	{
		cout << "Loop location is at 0" << endl;
		return fast;
	}
		

	while (fast != NULL)
	{
		slow = slow->getNextNode();
		countSlow++;

		fast = fast->getNextNode();
		countFast++;
		if (fast == slow)
		{
			isLoop = true;
			break;
		}

		fast = fast->getNextNode();
		countFast++;
		if (fast == slow)
		{
			isLoop = true;
			break;
		}
	}

	if (isLoop)
	{
		int loopIterateLength = countFast - countSlow;

		fast = list;
		loopIterateLength--;
		while (loopIterateLength != 0)
		{
			fast = fast->getNextNode();
			loopIterateLength--;
		}

		slow = list;
		fast = fast->getNextNode();

		int loopNodeLoc = 0;
		while (fast != slow)
		{
			slow = slow->getNextNode();
			fast = fast->getNextNode();
			loopNodeLoc++;
		}

		cout << "Loop location is at: " << loopNodeLoc << endl;
		return slow;
	}
	else
	{
		return NULL;
	}
}