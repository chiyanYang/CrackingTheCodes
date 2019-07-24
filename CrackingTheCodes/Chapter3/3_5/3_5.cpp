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

	stack<int> sortedStack = sortStack_TwoStacksOnly(unSortedStack);

	cout << "Print sorted stack" << endl;
	printStack(sortedStack);
}

stack<int> sortStack_NoLimitation(stack<int> unSortedStack)
{
	stack<int> sortedStack;
	stack<int> tmpStack;

	while (unSortedStack.size() != 0)
	{
		int max = findMax(unSortedStack, tmpStack);
		popMax(unSortedStack, tmpStack, max);
		pushMax(sortedStack, max);
	}
	
	return sortedStack;
}

int findMax(stack<int>& unSortedStack, stack<int>& tmpStack)
{
	int max = INT32_MIN;

	while (unSortedStack.size() != 0)
	{
		int data = unSortedStack.top();
		if (data > max)
		{
			max = data;
		}

		unSortedStack.pop();
		tmpStack.push(data);
	}

	pushItemsToDes(tmpStack, unSortedStack);

	return max;
}

void popMax(stack<int>& unSortedStack, stack<int>& tmpStack, int value)
{
	while (unSortedStack.size() != 0)
	{
		int data = unSortedStack.top();
		if (data == value)
		{
			unSortedStack.pop();
			break;
		}

		tmpStack.push(data);
		unSortedStack.pop();
	}

	while (tmpStack.size() != 0)
	{
		int data = tmpStack.top();
		unSortedStack.push(data);

		tmpStack.pop();
	}
}

stack<int> sortStack_TwoStacksOnly(stack<int> unSortedStack)
{
	stack<int> sortedStack;

	while (unSortedStack.size() != 0)
	{
		int max = getMax(unSortedStack, sortedStack);
		pushMax(sortedStack, max);
	}

	return sortedStack;
}

int getMax(stack<int>& unSortedStack, stack<int>& sortedStack)
{
	int max = INT32_MIN;
	int count = 0;

	while (unSortedStack.size() != 0)
	{
		int data = unSortedStack.top();

		if (data > max)
		{
			max = data;
		}
		sortedStack.push(data);
		unSortedStack.pop();
		count++;
	}

	bool isFirstTime = true;
	while (count != 0)
	{
		int data = sortedStack.top();
		sortedStack.pop();
		count--;

		if (data == max && isFirstTime)
		{
			isFirstTime = false;
			continue;
		}

		unSortedStack.push(data);
	}

	return max;
}

void pushMax(stack<int>& sortedStack, int data)
{
	sortedStack.push(data);
}

void pushItemsToDes(stack<int>& src, stack<int>& des)
{
	while (src.size() != 0)
	{
		int data = src.top();
		src.pop();
		des.push(data);
	}
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