#pragma once
#include "../Ch3Common.h"

void test3_5();

stack<int> sortStack_NoLimitation(stack<int> myStack);
int findMax(stack<int>& unSortedStack, stack<int>& tmpStack);
void popMax(stack<int>& unSortedStack, stack<int>& tmpStack, int value);
void pushMax(stack<int>& sortedStack, int data);

stack<int> sortStack_TwoStacksOnly(stack<int> unSortedStack);
int getMax(stack<int>& unSortedStack, stack<int>& sortedStack);
int pushMax(stack<int>& unSortedStack, stack<int>& sortedStack);

void pushItemsToDes(stack<int>& src, stack<int>& des);
void printStack(stack<int> printStack);