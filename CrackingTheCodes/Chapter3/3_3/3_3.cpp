#include "3_3.h"

// Stack of Plates
void test3_3()
{
	int innerSize = 0;
	cout << "Enter the size for each inner stack: ";
	cin >> innerSize;
	cout << endl;

	SetOfStacks<int> myStack(innerSize);
	testFunction(myStack);
}

template <typename T>
void testFunction(SetOfStacks<T>& myStack)
{
	while (true)
	{
		int method;

		cout << "method 1: callPush" << endl;
		cout << "method 2: callPop" << endl;
		cout << "method 3: callPopAt" << endl;
		cout << "method 4: callPeek" << endl;
		cout << "method 5: callIsEmpty" << endl;
		cout << "method 6: callIsFull" << endl;
		cout << "method 7: callPrintStack" << endl;
		cout << "---------------------" << endl;
		cout << "Enter the mothod to execute: ";
		cin >> method;
		cout << endl;

		int index = 0;
		T data = NULL;
		bool result = false;

		switch (method)
		{
		case 1: cout << "Enter the data: ";
				cin >> data;
				cout << endl;
				result = myStack.push(data);
				cout << "Push data result: " << result << endl;
				break;
		case 2: myStack.pop();
				cout << "Pop done" << endl;
				break;
		case 3: cout << "Enter the index: ";
				cin >> index;
				myStack.popAt(index);
				cout << "Pop done" << endl;
				break;
		case 4: data = myStack.peek();
				cout << "Data = " << data << endl;
				break;
		case 5: result = myStack.isEmpty();
				cout << "Is empty: " << result << endl;
				break;
		case 6: result = myStack.isFull();
				cout << "Is full: " << result << endl;
				break;
		case 7: myStack.printStack();
			break;
		default: cout << "No Method found" << endl;
		}
	}
}