#include "3_5.h"

// Sort Stack
void test3_5()
{
	stack<int> unSortedStack;
	
	vector<int> myVector1{ 1, 2, 3, 4, 5 };
	vector<int> myVector2{ 5, 4, 3, 2, 1 };
	vector<int> myVector3{ 99, 1, 8, 10, 5, 4, 3, 100, 98, 101,68 };

	for (auto& item : myVector3) {
		unSortedStack.push(item);
	}

	cout << "Print unsorted stack" << endl;
	printStack(unSortedStack);

	stack<int> sortedStack = sortStack(unSortedStack);

	cout << "Print sorted stack" << endl;
	printStack(sortedStack);
}

stack<int> sortStack(stack<int> unSortedStack)
{
	stack<int> sortedStack;

	while (unSortedStack.size() != 0)
	{
		int max = findMax(unSortedStack);
		popMax(unSortedStack, max);
		pushMax(sortedStack, max);
	}
	
	return sortedStack;
}

int findMax(stack<int> myStack)
{
	int max = INT32_MIN;

	while (myStack.size() != 0)
	{
		int data = myStack.top();
		if (data > max)
		{
			max = data;
		}

		myStack.pop();
	}

	return max;
}

void popMax(stack<int>& myStack, int value)
{
	stack<int> tmpStack;

	while (myStack.size() != 0)
	{
		int data = myStack.top();
		if (data == value)
		{
			myStack.pop();
			break;
		}

		tmpStack.push(data);
		myStack.pop();
	}

	while (tmpStack.size() != 0)
	{
		int data = tmpStack.top();
		myStack.push(data);

		tmpStack.pop();
	}
}

void pushMax(stack<int>& myStack, int data)
{
	myStack.push(data);
}

void printStack(stack<int> printStack)
{
	cout << "Stack from top: ";
	while (printStack.size() != 0)
	{
		cout << printStack.top() << " ";
		printStack.pop();
	}
	cout << endl << endl;
}