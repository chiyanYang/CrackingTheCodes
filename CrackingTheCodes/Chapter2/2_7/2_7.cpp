#include "2_7.h"

// Intersection
void test2_7()
{
	int length;
	int stop;

	cout << "Enter the length of the list: ";
	cin >> length;
	cout << endl;

	pair<sNode*, sNode*> intersecLists = createSingleLinkedListWithIntersection(length);

	cout << "Print the list" << endl;
	printSList(intersecLists.first);
	printSList(intersecLists.second);

	bool result = hasIntersection(intersecLists.first, intersecLists.second);

	cout << "Does the list have intersection: " << result;

	cin >> stop;
	//freeSList(head);
}

bool hasIntersection(sNode* list1, sNode* list2)
{

	return true;
}