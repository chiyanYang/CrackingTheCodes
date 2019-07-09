#include "2_7.h"

// Intersection
void test2_7()
{
	int length1;
	int length2;

	cout << "Enter the length of the list1, can not be zero: ";
	cin >> length1;
	cout << endl;

	cout << "Enter the length of the list2, can not be zero: ";
	cin >> length2;
	cout << endl;

	pair<sNode*, sNode*> intersecLists = createSingleLinkedListWithIntersection(length1, length2);

	cout << "Print the list" << endl;
	printSList(intersecLists.first);
	printSList(intersecLists.second);

	bool result = hasIntersection(intersecLists.first, intersecLists.second);

	cout << "Does the list have intersection: " << result;

	freeSListsWithIntersection(intersecLists.first, intersecLists.second);
}

bool hasIntersection(sNode* list1, sNode* list2)
{

	return true;
}