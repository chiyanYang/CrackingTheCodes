#pragma once
#include "../Ch3Common.h"

void test3_5();

stack<int> sortStack(stack<int> myStack);
int findMax(stack<int> myStack);
void popMax(stack<int>& myStack, int value);
void pushMax(stack<int>& myStack, int data);

void printStack(stack<int> printStack);