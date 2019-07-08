#include "2_5.h"

// Sum Lists
void test2_5()
{
	int length;
	int stop;
	sNode* head1 = NULL;
	sNode* head2 = NULL;
	sNode* result1 = NULL;
	sNode* result2 = NULL;

	cout << "Enter the length of the list: ";
	cin >> length;

	head1 = createSingleLinkedList(length);
	this_thread::sleep_for(chrono::seconds(1));
	head2 = createSingleLinkedList(length);
	cout << "Print the list" << endl;

	printSList(head1);
	printSList(head2);
	result1 = sumListForward(head1, head2);
	cout << "Sun list result (forward):" << endl;
	printSList(result1);

	result2 = sumListBackward(head1, head2);
	cout << "Sun list result (backward):" << endl;
	printSList(result2);


	cin >> stop;
	freeSList(head1);
	freeSList(head2);
	freeSList(result1);
	freeSList(result2);
}

sNode* sumListForward(sNode* head1, sNode* head2)
{
	int carry = 0;
	int sum = head1->getData() + head2->getData();
	if (sum > 9)
	{
		carry = 1;
		sum -= 10;
	}
		
	sNode* resultHead = new sNode(sum);
	sNode* cur = resultHead;

	head1 = head1->getNextNode();
	head2 = head2->getNextNode();

	while (head1 != NULL)
	{
		sum = head1->getData() + head2->getData() + carry;
		if (sum > 9)
		{
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;

		sNode* newDigit = new sNode(sum);
		cur->setNextNode(newDigit);
		cur = newDigit;
		head1 = head1->getNextNode();
		head2 = head2->getNextNode();
	}

	if (carry == 1)
	{
		sNode* newDigit = new sNode(carry);
		cur->setNextNode(newDigit);
	}

	return resultHead;
}

// Assume list can be modified
// Instead of using vector to store the values and sum
// Use reversing list to practice
sNode* sumListBackward(sNode* head1, sNode* head2)
{
	head1 = reverseList(head1);
	
	head2 = reverseList(head2);

	return sumListForward(head1, head2);
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

	printSList(cur);

	return cur;
}