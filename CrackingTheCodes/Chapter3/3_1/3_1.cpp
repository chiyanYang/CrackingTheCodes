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
		    case 1: callPush();
				    break;
			case 2: callPop();
					break;
			case 3: callPeek();
					break;
			case 4: callIsEmpty();
					break;
			case 5: callIsFull();
					break;
			default: "No Method found"
		}
	}

	fixStack<int> myStack(length, numOfStack);
}

