#include "2_8.h"

// Loop Detection
void test2_8()
{

}

sNode* loopDetection(sNode* list)
{
	if (list == NULL)
		return NULL;

	bool isLoop = false;
	int count = 1;
	sNode* slow = list;
	sNode* fast = list;
	fast = list->getNextNode();

	if (fast == slow)
		return fast;

	while (fast != NULL)
	{
		slow = slow->getNextNode();
		count++;

		fast = fast->getNextNode();
		if (fast == slow)
		{
			isLoop = true;
			break;
		}

		fast = fast->getNextNode();
		{
			isLoop = true;
			break;
		}
	}

	if (isLoop)
	{

	}
	else
	{
		return NULL;
	}

}