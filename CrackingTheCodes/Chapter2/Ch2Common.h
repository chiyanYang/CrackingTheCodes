#pragma once
#include "../Common.h"

class sNode
{
public:
	sNode(int data);

	int getData();
	void setData(int data);

	sNode* getNextNode();
	void setNextNode(sNode* node);

private:
	int data;
	sNode* next;
};

sNode* createSingleLinkedList(int length);
void printSList(sNode* head);
void freeSList(sNode* head);
sNode* removeCurSNode(sNode* pre, sNode* cur);
sNode* reverseList(sNode* head);
sNode* copyList(sNode* head);
sNode* createSingleLinkedListWithPalindrome(int length);
pair<sNode*, sNode*> createSingleLinkedListWithIntersection(int length1, int length2);
void freeSListsWithIntersection(sNode* list1, sNode* list2);
int listLength(sNode* list);
sNode* createSingleLinkedListWithLoop(int length);
void freeSListsWithLoop(sNode* list);
void printSListWithLoop(sNode* cur);