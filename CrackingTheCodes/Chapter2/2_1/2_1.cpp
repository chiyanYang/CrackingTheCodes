#include "2_1.h"

// Remove Dups
void test2_1()
{
	int stop = 0;
	int length = 0;
	sNode* head = NULL;

	cout << "Enter the length of the single linked list" << endl;
	cin >> length;

	head = createSingleLinkedList(length);
	printSList(head);
	
	removeDups(head);
	printSList(head);

	freeSList(head);
	cin >> stop;
}

void removeDups(sNode* head)
{
	sNode* pre = NULL;
	unordered_set<int> numbers = {};
	while (head != NULL)
	{
		int data = head->getData();

		auto found = numbers.find(data);
		if (found != numbers.end())
		{
			head = removeCurSNode(pre, head);
		}
		else
			numbers.insert(data);

		pre = head;

		if (head != NULL)
		    head = head->getNextNode();
	}
}