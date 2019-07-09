#include "2_7.h"

// Intersection
void test2_7()
{
	int length1;
	int length2;

	cout << "Enter the length of the list1, can not be zero: ";
	cin >> length1;
	cout << endl;

	cout << "Enter the length of the list2 excluded after the intersection node, can not be zero: ";
	cin >> length2;
	cout << endl;

	pair<sNode*, sNode*> intersecLists = createSingleLinkedListWithIntersection(length1, length2);

	cout << "Print the list" << endl;
	printSList(intersecLists.first);
	printSList(intersecLists.second);

	bool result = hasIntersection(intersecLists.first, intersecLists.second);

	cout << "Does the intersection list have intersection: " << result << endl << endl;

	cout << "Enter the length if list1, can not be zero: ";
	cin >> length1;
	cout << "Enter the length if list2, can not be zero: ";
	cin >> length2;
	pair<sNode*, sNode*> noIntersectionLists;
	noIntersectionLists.first = createSingleLinkedList(length1);
	noIntersectionLists.second = createSingleLinkedList(length2);

	cout << "Print the list" << endl;
	printSList(noIntersectionLists.first);
	printSList(noIntersectionLists.second);

	result = hasIntersection(noIntersectionLists.first, noIntersectionLists.second);

	cout << "Does the lists have intersection: " << result << endl;

	freeSListsWithIntersection(intersecLists.first, intersecLists.second);
	freeSList(noIntersectionLists.first);
	freeSList(noIntersectionLists.second);
}

bool hasIntersection(sNode* list1, sNode* list2)
{
	int length1 = listLength(list1);
	int length2 = listLength(list2);

	int diff;

	sNode* longList;
	sNode* shortList;

	if (length1 >= length2)
	{
		longList = list1;
		shortList = list2;
		diff = length1 - length2;
	}
	else
	{
		longList = list2;
		shortList = list1;
		diff = length2 - length1;
	}

	for (int i = 0; i < diff; i++)
	{
		longList = longList->getNextNode();
	}

	while (longList != NULL)
	{
		if (longList == shortList)
			return true;

		longList = longList->getNextNode();
		shortList = shortList->getNextNode();
	}

	return false;
}