#include "2_6.h"

// Palindrome
void test2_6()
{
	int length;
	int stop;
	sNode* head1 = NULL;
	sNode* head2 = NULL;

	cout << "Enter the length of the list: ";
	cin >> length;
	cout << endl;

	head1 = createSinglePalindromeLinkedList(length);
	cout << "Print the list" << endl;
	printSList(head1);
	bool result1 = isPalindrome(head1);

	cout << "Is the list Palindrome: " << result1 << endl;

	head2 = createSingleLinkedList(length);
	cout << "Print the list" << endl;
	printSList(head2);
	bool result2 = isPalindrome(head2);

	cout << "Is the list Palindrome: " << result2 << endl;

	cin >> stop;
	freeSList(head1);
	freeSList(head2);
}

bool isPalindrome(sNode* head)
{
	sNode* copiedList = copyList(head);
	sNode* reversedList = reverseList(copiedList);

	while (head != NULL)
	{
		if (reversedList->getData() != head->getData())
			return false;

		reversedList = reversedList->getNextNode();
		head = head->getNextNode();
	}

	free(reversedList);

	return true;
}