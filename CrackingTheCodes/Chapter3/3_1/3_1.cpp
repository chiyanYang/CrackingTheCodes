#include "3_1.h"

// Three in One
void test3_1()
{
	int length;
	int numOfStack;
	int stackType;


	cout << "Please enter the length the array: ";
	cin >> length;
	cout << "Please enter the number of stack: ";
	cin >> numOfStack;
	cout << endl;

	cout << "Stack Type:" << endl;
	cout << "1 for fix size" << endl;
	cout << "2 for variable" << endl;
	cout << "Please enter the type of stack: ";
	cin >> stackType;
	cout << endl;
	cout << "Number of stack is: " << numOfStack << endl;

	if (stackType == 1)
	{
		cout << "The fix size for each stack is \"length / numOfStack\"" << endl;
		cout << "The fix size per stack is: " << length / numOfStack << endl;
		fixStack<int> myStack(length, numOfStack);
		testFunction(&myStack);
	}
	else
	{
		variableStack<int> myStack(length, numOfStack);
		testFunction(&myStack);
	}


}

void testFunction(baseStack<int>* myStack)
{
	while (true)
	{
		int method;

		cout << endl << "---------------------" << endl;
		cout << "method 1: callPush" << endl;
		cout << "method 2: callPop" << endl;
		cout << "method 3: callPeek" << endl;
		cout << "method 4: callIsEmpty" << endl;
		cout << "method 5: callIsFull" << endl;
		cout << "method 6: callPrintStack" << endl;
		cout << "---------------------" << endl;
		cout << "Enter the mothod to execure: ";
		cin >> method;
		cout << endl;

		int stackIdx = 0;

		if (method != 6)
		{
			cout << "Enter the stack index: ";
			cin >> stackIdx;
			cout << endl;
		}

		switch (method)
		{
			case 1: callPush(myStack, stackIdx);
					break;
			case 2: callPop(myStack, stackIdx);
					break;
			case 3: callPeek(myStack, stackIdx);
					break;
			case 4: callIsEmpty(myStack, stackIdx);
					break;
			case 5: callIsFull(myStack, stackIdx);
					break;
			case 6: callPrintStack(myStack);
					break;
			default: cout << "No Method found" << endl;
		}
	}
}

template <typename T>
void callPush(baseStack<T>* myStack, int stackIdx)
{
	int data;
	cout << "Enter the data: ";
	cin >> data;
	cout << endl;

	bool result = myStack->push(stackIdx, data);

	cout << "Push success: " << result;
}

template <typename T>
void callPop(baseStack<T>* myStack, int stackIdx)
{
	myStack->pop(stackIdx);
}

template <typename T>
void callPeek(baseStack<T>* myStack, int stackIdx)
{
	T data = myStack->peek(stackIdx);
	cout << "Data is: " << data << endl;
}

template <typename T>
void callIsEmpty(baseStack<T>* myStack, int stackIdx)
{
	bool result = myStack->isEmpty(stackIdx);
	cout << "IsEmpty: " << result << endl;
}

template <typename T>
void callIsFull(baseStack<T>* myStack, int stackIdx)
{
	bool result = myStack->isFull(stackIdx);
	cout << "IsFull: " << result << endl;
}

template <typename T>
void callPrintStack(baseStack<T>* myStack)
{
	myStack->printStack();
}

