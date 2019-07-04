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
