#include "3_1.h"

// Three in One
void test3_1()
{
	int length;
	int numOfStack;
	int method;

	cout << "Please enter the length the array:";
	cin >> length;
	cout << "Please enter the number of stack:";
	cin >> numOfStack;
	cout << endl;
	cout << "The fix size for each stack is \"length / numOfStack\"" << endl;
	cout << "The fix size per stack is:" << length / numOfStack << "Number of stack is:" << numOfStack  << endl;

	fixStack<int> myStack(length, numOfStack);

	while (true)
	{
		cout << "method 1: callPush" << endl;
		cout << "method 2: callPop" << endl;
		cout << "method 3: callPeek" << endl;
		cout << "method 4: callIsEmpty" << endl;
		cout << "method 5: callIsFull" << endl;
		cout << "Enter the mothod to execure:";
		cin >> method;

		switch (method)
		{
		    case 1: callPush(myStack);
				    break;
			case 2: callPop(myStack);
					break;
			case 3: callPeek(myStack);
					break;
			case 4: callIsEmpty(myStack);
					break;
			case 5: callIsFull(myStack);
					break;
			default: "No Method found";
		}
	}
}


template <typename T>
void callPush(fixStack<T>& myStack)
{

}

template <typename T>
void callPop(fixStack<T>& myStack)
{

}

template <typename T>
void callPeek(fixStack<T>& myStack)
{
	
}

template <typename T>
void callIsEmpty(fixStack<T>& myStack)
{
	bool result = myStack.isEmpty(0);
	cout << "IsEmpty:" << result << endl;
}

template <typename T>
void callIsFull(fixStack<T>& myStack)
{

}

